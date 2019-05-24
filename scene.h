#ifndef SCENE_H
#define SCENE_H

#include <QScrollBar>
#include <QObject>


#include <QTimerEvent>
#include <QGraphicsScene>

#include <ground.h>
#include "background.h"
#include "marioview2.h"
#include "monsterview.h"

#include <QVector>

#include <controller.h>



class Scene : public QGraphicsScene
{

    Q_OBJECT

public:
    Scene(QObject *parent = 0);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    inline Ground *getGround(){return ground;}



public slots:
    void monsterSpawn();

private:

    void initWorld();



    int groundYPosition = 650;


    Ground *ground;
    Background *sky;
    MarioView2 *mario;

    QVector<MonsterView*> monster;
    Controller *controller;

    QTimer *timer;


    void listenToServer();
};



#endif // SCENE_H
