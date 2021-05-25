QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Sources/addfunctwindow.cpp \
    Sources/addvectwindow.cpp \
    Sources/chartview.cpp \
    Sources/display_4d.cpp \
    Sources/displaywindow.cpp \
    Sources/executewindow.cpp \
    Sources/gestion_ES.c \
    Sources/liste_vecteurs.c \
    Sources/loadwindow.cpp \
    Sources/main.cpp \
    Sources/mainwindow.cpp \
    Sources/savewindow.cpp \
    Sources/statistiques.c \
    Sources/tinyexpr.c \
    Sources/vecteurs.c \
    Sources/\transfert_fichiers_affichage3D.cpp \

HEADERS += \
    Headers/addfunctwindow.h \
    Headers/addvectwindow.h \
    Headers/chartview.h \
    Headers/display_4d.h \
    Headers/displaywindow.h \
    Headers/executewindow.h \
    Headers/gestion_ES.h \
    Headers/liste_vecteurs.h \
    Headers/loadwindow.h \
    Headers/mainwindow.h \
    Headers/savewindow.h \
    Headers/statistiques.h \
    Headers/tinyexpr.h \
    Headers/vecteurs.h \
    Headers/\transfert_fichiers_affichage3D.h

FORMS += \
    Sources/addfunctwindow.ui \
    Sources/addvectwindow.ui \
    Sources/display_4d.ui \
    Sources/displaywindow.ui \
    Sources/executewindow.ui \
    Sources/loadwindow.ui \
    Sources/mainwindow.ui \
    Sources/savewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
