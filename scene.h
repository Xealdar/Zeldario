#ifndef SCENE_H
#define SCENE_H

#include <QScrollBar>
#include <QObject>
#include <QTimerEvent>
#include <QGraphicsScene>

#include <background.h>
#include "marioview2.h"
#include "monsterview.h"

#include <QVector>

#include <controller.h>



class Scene : public QGraphicsScene
{

public:
    Scene(QObject *parent = 0);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:

    void initWorld();

    //QVector<Background*> ground{10};

    int groundYPosition = 650;

    Background *scene;
    Background *ground;
    Background *coin;
    Background *sky;
    MarioView2 *mario;
    MonsterView *monster;

    Controller *controller;

    QTimer *timer;

private slots:
    void monsterSpawwn();
};



#endif // SCENE_H
