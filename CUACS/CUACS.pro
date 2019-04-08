#-------------------------------------------------
#
# Project created by QtCreator 2019-01-31T14:03:34
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CUACS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        cuacsview.cpp \
    animal.cpp \
    databasemanager.cpp \
    client.cpp \
    detailedclientview.cpp \
    animaldetailedview.cpp \
    clientmanager.cpp \
    animalmanager.cpp \
    login.cpp \
    clientonlyview.cpp \
    ACM.cpp \
    detailedmatchesview.cpp

HEADERS += \
        cuacsview.h \
    animal.h \
    databasemanager.h \
    client.h \
    detailedclientview.h \
    animaldetailedview.h \
    clientmanager.h \
    animalmanager.h \
    login.h \
    clientonlyview.h \
    ACM.h \
    matchpair.h \
    detailedmatchesview.h

FORMS += \
        cuacsview.ui \
    detailedclientview.ui \
    animaldetailedview.ui \
    login.ui \
    clientonlyview.ui \
    detailedmatchesview.ui
