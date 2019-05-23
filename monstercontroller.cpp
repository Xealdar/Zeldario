#include "monstercontroller.h"

#include <qrandom.h>

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
    posX = QRandomGenerator::global()->bounded(750);
    posY = QRandomGenerator::global()->bounded(10);
    qDebug()<<"random: "<<posY;

    //width = 750
    //height = 850
}

void MonsterController::IA()
{

}

