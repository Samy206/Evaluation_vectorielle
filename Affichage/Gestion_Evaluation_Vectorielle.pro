QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addfunctwindow.cpp \
    addvectwindow.cpp \
    display_4d.cpp \
    displaywindow.cpp \
    executewindow.cpp \
    liste_vecteurs.c \
    loadwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    savewindow.cpp \
    statistiques.c \
    tinyexpr.c \
    vecteurs.c

HEADERS += \
    addfunctwindow.h \
    addvectwindow.h \
    display_4d.h \
    displaywindow.h \
    executewindow.h \
    liste_vecteurs.h \
    loadwindow.h \
    mainwindow.h \
    savewindow.h \
    statistiques.h \
    tinyexpr.h \
    vecteurs.h

FORMS += \
    addfunctwindow.ui \
    addvectwindow.ui \
    display_4d.ui \
    displaywindow.ui \
    executewindow.ui \
    loadwindow.ui \
    mainwindow.ui \
    savewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
