QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 qaxcontainer

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    customaction.cpp \
    customcolorfontdialog.cpp \
    customtextedit.cpp \
    main.cpp \
    mainwindow.cpp \
    style.cpp

HEADERS += \
    customaction.h \
    customcolorfontdialog.h \
    customtextedit.h \
    mainwindow.h \
    style.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ProManager.qrc

# Linking to OfficeLibrary
INCLUDEPATH += $$PWD/../../CustomQtOfficeLibraryFiles/CustomQtOfficeLibrary
DEPENDPATH += $$PWD/../../CustomQtOfficeLibraryFiles/CustomQtOfficeLibrary
LIBS += -L$$PWD/../../CustomQtOfficeLibraryFiles/build-CustomQtOfficeLibrary-Desktop_Qt_6_1_2_MSVC2019_64bit-Debug/debug/ -lCustomQtOfficeLibrary
