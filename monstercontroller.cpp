#include "monstercontroller.h"

#include <qrandom.h>

#include "monsterview.h"

#include <QDebug>

MonsterController::MonsterController(MonsterView *view)
{
    this->view = view;
    state = WALKING_RIGHT; //Pour les tests
    //tests:
    move();


}


void MonsterController:: move(){

    switch(state){
        case WALKING_LEFT:
            dx = -1 * velocity;
            dy = 0;

        break;

        case WALKING_RIGHT:
            dx = velocity;
            dy = 0;

        break;

        case DYING:
            dx = 0;
            dy = 0;
        break;
    }
}


void MonsterController::createRandomSpawn()
{
    originPosX = QRandomGenerator::global()->bounded(750);
    originPosY = QRandomGenerator::global()->bounded(10);
    qDebug()<<"random: "<<originPosY;

    //width = 750
    //height = 850
}

void MonsterController::IA()
{
    directionX = marioPosX - view->pos().x();
    directionY = marioPosY - view->pos().y();

    dx = directionX * velocity;
    dy = directionY * velocity;


}

void MonsterController::setMarioPos(double newMarioPosX, double newMarioPosY)
{
    marioPosX = newMarioPosX;
    marioPosY = newMarioPosY;
    IA();
}

