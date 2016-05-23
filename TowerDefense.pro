#-------------------------------------------------
#
# Project created by QtCreator 2016-04-17T10:35:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TowerDefense
TEMPLATE = app


SOURCES += main.cpp \
    Tower.cpp \
    bullet.cpp \
    game.cpp \
    enemy.cpp \
    buildshoottowericon.cpp \
    shoottower.cpp \
    bluetower.cpp \
    buildbluetowericon.cpp \
    buildslowtowericon.cpp \
    slowtower.cpp \
    slowdart.cpp \
    triplearrow.cpp \
    score.cpp \
    menu.cpp \
    health.cpp \
    home.cpp \
    gameover.cpp \
    highscore.cpp \
    map.cpp

HEADERS  += \
    Tower.h \
    bullet.h \
    game.h \
    enemy.h \
    buildshoottowericon.h \
    shoottower.h \
    bluetower.h \
    buildbluetowericon.h \
    buildslowtowericon.h \
    slowtower.h \
    slowdart.h \
    triplearrow.h \
    score.h \
    menu.h \
    health.h \
    home.h \
    gameover.h \
    highscore.h \
    map.h

FORMS    +=

RESOURCES += \
    res.qrc
