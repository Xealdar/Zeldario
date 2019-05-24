#include "monstercontroller.h"

#include <qrandom.h>

#include "monsterview.h"

#include <QDebug>

#include <scene.h>



MonsterController::MonsterController(MonsterView *view)
{
    this->view = view;
    state = IDLE;
}


void MonsterController::createRandomSpawn()
{
    originPosX = QRandomGenerator::global()->bounded(750);
    originPosY = QRandomGenerator::global()->bounded(10);
}


void MonsterController::IA()
{
    directionX = marioPosX - view->pos().x();
    directionY = marioPosY - view->pos().y();

    originDx = directionX * velocity;
    originDy = directionY * velocity;
}

void MonsterController::setMarioPos(double newMarioPosX, double newMarioPosY)
{
    marioPosX = newMarioPosX;
    marioPosY = newMarioPosY;
    IA();
}

void MonsterController::collisionReaction(QVector<QGraphicsItem*> itemsCollidingVector)
{
    //qDebug()<<"itemVector : "<<itemsCollidingVector<<"item in scene : "<<view->scene()->items()[0];

    if(itemsCollidingVector.contains(dynamic_cast<Scene*>(view->scene())->getGround()))
    {
        state = BOUNCING;
    }

    if(itemsCollidingVector.contains(dynamic_cast<Scene*>(view->scene())->getMario()))
    {
        qDebug()<<"YOU DIE";
        //Gérer la mort de mario
    }
}
