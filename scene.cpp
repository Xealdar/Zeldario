#include <scene.h>

#include <QDebug>
#include <QKeyEvent>
#include <QTimer>
#include <QPainter>
#include <QMediaPlayer>
#include "clientthread.h"

#include"marioview2.h"
#include"mariocontroller.h"

Scene::Scene(QObject *parent) : QGraphicsScene(0,0,8000,720, parent)
{
    Scene::initWorld();
    //controller = new Controller(mario);

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
    MarioView2 *mario2 = new MarioView2(QPixmap(":Images/marioWalk.png"), 0, groundYPosition + 600);

    addItem(mario2);
    addItem(mario);

    listenToServer();
}

void Scene::listenToServer(){
    ClientThread *thread = new ClientThread(mario->getController());
    thread->start();
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    //qDebug("keypressed");
    mario->getController()->keyPressEvent(event);

    switch(event->key())
    {

        case Qt::Key_Right:
            //mario->walk();
//            mario->setDirection(1);
//            mario->walk();
//            timer->start(1000);
//            controller->moveCharact(Qt::Key_Right);

//            if(timer->remainingTime() > 0)
//            {
//                qDebug()<<"time remain : "<<timer->remainingTime();
//            }

            //controller->checkInputPushed(Qt::Key_Right);

        break;

        case Qt::Key_Left:
            //controller->checkInputPushed(Qt::Key_Left);
        break;

        case Qt::Key_Space:
            //controller->checkInputPushed(Qt::Key_Space);
        break;

        default:
        break;

    }
}

void Scene::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat())
        return;

    mario->getController()->keyReleaseEvent(event);

    /*switch(event->key())
    {
        case Qt::Key_Right:
            controller->checkInputReleased(Qt::Key_Right);
        break;

        case Qt::Key_Left:
            controller->checkInputReleased(Qt::Key_Left);
        break;

        case Qt::Key_Space:
            controller->checkInputReleased(Qt::Key_Space);
        break;
        //Gérer le cas où on appuie sur deux touches en même temps

        default:
        break;

    }*/
}
