#ifndef SCENE_H
#define SCENE_H

#include <QScrollBar>
#include <QObject>
#include <QTimerEvent>
#include <QGraphicsScene>

#include <background.h>
#include <mario.h>

#include <QVector>

#include <controller.h>


class Scene : public QGraphicsScene
{

public:
    Scene(QObject *parent = 0);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    static bool getIsRightPushed();
    static bool getIsLeftPushed();
    static bool getIsJumpPushed();


private:

    void initWorld();

    //QVector<Background*> ground{10};

    int groundYPosition = 650;

    Background *scene;
    Background *ground;
    Background *coin;
    Background *sky;
    Mario *mario;

    Controller *controller;





};



#endif // SCENE_H
