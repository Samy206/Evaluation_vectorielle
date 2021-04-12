QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addfunctwindow.cpp \
    addvectwindow.cpp \
    displaywindow.cpp \
    executewindow.cpp \
    loadwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    savewindow.cpp

HEADERS += \
    addfunctwindow.h \
    addvectwindow.h \
    displaywindow.h \
    executewindow.h \
    loadwindow.h \
    mainwindow.h \
    savewindow.h

FORMS += \
    addfunctwindow.ui \
    addvectwindow.ui \
    displaywindow.ui \
    executewindow.ui \
    loadwindow.ui \
    mainwindow.ui \
    savewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
