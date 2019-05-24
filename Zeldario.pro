#-------------------------------------------------
#
# Project created by QtCreator 2019-04-16T13:46:18
#
#-------------------------------------------------

QT       += core gui \
         multimedia  \
         network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Zeldario
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

CONFIG += c++11

SOURCES += \
    background.cpp \
    client.cpp \
    clientthread.cpp \
    coin.cpp \
    coincounter.cpp \
    ground.cpp \
    link.cpp \
    main.cpp \
    mainwindow.cpp \
    mariocontroller.cpp \
    marioview2.cpp \
    monstercontroller.cpp \
    monsterview.cpp \
    mushroom.cpp \
    platform.cpp \
    scene.cpp \
    view.cpp \
    zelda_monster.cpp

HEADERS += \
    background.h \
    client.h \
    clientthread.h \
    coin.h \
    coincounter.h \
    ground.h \
    link.h \
    mainwindow.h \
    mariocontroller.h \
    marioview2.h \
    monstercontroller.h \
    monsterview.h \
    mushroom.h \
    platform.h \
    scene.h \
    view.h \
    zelda_monster.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images/ground.png \
    Images/sky.png \
    Images/ground2.png \
    Images/marioWalk.png \
    Images/marioStop.png \
    Images/MonsterDeath.png \
    Images/MonsterIdle.png \
    Images/shit.png \
    res.qrc
