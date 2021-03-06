#-------------------------------------------------
#
# Project created by QtCreator 2018-06-02T13:18:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pet
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    data.cpp \
    rule.cpp \
    select_pet.cpp \
    pet_main.cpp \
    attribute.cpp \
    game.cpp

HEADERS += \
        mainwindow.h \
    data.h \
    rule.h \
    select_pet.h \
    pet_main.h \
    attribute.h \
    game.h

FORMS += \
        mainwindow.ui \
    rule.ui \
    select_pet.ui \
    pet_main.ui

RESOURCES += \
    picture.qrc

DISTFILES += \
    res/angry.gif \
    res/happy.gif \
    res/homework.gif \
    res/play.gif \
    res/sleep.gif \
    res/sport1.gif \
    res/sport2.gif \
    res/travel.gif \
    res/work.gif \
    res/ePet.ico
