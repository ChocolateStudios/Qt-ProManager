#include "document.h"
#include <windows.h>

#include <QAxObject>
#include <QColor>
#include <QUuid>

namespace OfficeLib { namespace Word {

Document::Document(QAxObject* appObj, QAxObject *docObj) : wordObj(appObj), docObj(docObj),
    selection(wordObj->querySubObject("Selection")), isOpen(true)
{
}

Document::~Document()
{
    if (isOpen)
        close();
}

void Document::writeText(const QString &text)
{
    if (!isOpen || text.isEmpty()) return;
    selection->dynamicCall("TypeText(const QString&)", text);
}

void Document::setFontSize(const unsigned short &size)
{
    if (!isOpen) return;
    selection->querySubObject("Font")->setProperty("Size", size);
}

void Document::setFontColor(Word::WdColor &color)
{
    if (!isOpen) return;
    selection->querySubObject("Font")->dynamicCall("SetColor(WdColor)", color);
    selection->querySubObject("Font")->setProperty("Color", color);
}

QVariant Document::getFontColor()
{
    if (!isOpen) return QVariant();
    return selection->querySubObject("Font")->dynamicCall("Color()");
}

void Document::setFontName(const QString &font)
{
    if (!isOpen) return;
    selection->querySubObject("Font")->setProperty("Name", font);
}

void Document::setFontBold(const bool &value)
{
    if (!isOpen) return;
    selection->querySubObject("Font")->setProperty("Bold", value);
}

void Document::close()
{
    if (!isOpen) return;
    docObj->dynamicCall("Close(bool)", false);
    isOpen = false;
}

void Document::save()
{
    if (!isOpen) return;
     docObj->dynamicCall("Save()");
}

void Document::saveAs(const QString &fileName)
{
    if (!isOpen) return;
    docObj->dynamicCall("SaveAs(const QString&)", fileName);
}

}}
