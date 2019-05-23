#include <scene.h>

#include <QDebug>
#include <QKeyEvent>
#include <QTimer>
#include <QPainter>
#include <QMediaPlayer>


#include"marioview2.h"
#include"mariocontroller.h"

#include "monstercontroller.h"

Scene::Scene(QObject *parent) : QGraphicsScene(0,0,8000,720, parent)
{

    Scene::initWorld();
    timer = new QTimer(this);
    timer->setInterval(5000);
    //connect(timer, SIGNAL(timeout()), this, SLOT(monsterSpawwn()));
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(monsterSpawn()));
    timer->start();


}



void Scene::initWorld()
{


    sky = new Background(QPixmap(":Images/sky.png"),0,0,0);
    //sky->setZValue(1);

    addItem(sky);

    ground = new Background(QPixmap(":Images/ground2.png"),0,0,groundYPosition);
    //ground->setZValue(2);
    addItem(ground);

    //mario = new Mario(0,groundYPosition - 10);
    //mario->getCurrentQGraphicsItem()->setZValue(3);


    mario = new MarioView2(QPixmap(":Images/marioWalk.png"), 150, groundYPosition - 65);
    addItem(mario);



}


void Scene::keyPressEvent(QKeyEvent *event)
{

    mario->getController()->keyPressEvent(event);


}

void Scene::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat())
        return;

    mario->getController()->keyReleaseEvent(event);



}

void Scene::monsterSpawn()
{

    monster.append(new MonsterView(QPixmap(":Images/MonsterIdle.png")));
    monster.at(monster.length()-1)->getController()->setMarioPos(mario->pos().x(),mario->pos().y());
    qDebug()<<"x : "<<mario->pos().x();
    addItem(monster[monster.length()-1]);

}


