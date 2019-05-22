#include "controller.h"

#include <QDebug>



Controller::Controller(Mario *newMario)
{
    mario = newMario;
}

void Controller::checkInputPushed(int newInput)
{
    inputPushed = newInput;

    //QFuture<void> future = QtConcurrent::run(this,&Controller::moveCharact,inputPushed);

    moveCharact(inputPushed);
}

void Controller::checkInputReleased(int newInput)
{
    inputReleased = newInput;
    mario->stand();
}

void Controller::moveCharact(int inputPushed)
{
    mario->move();

    switch(inputPushed)
    {
        case Qt::Key_Right:

            //mario->setDirection(1);
            //mario->walk();
            //mario->move();


        break;

        case Qt::Key_Left:
            mario->setDirection(-1);
            mario->walk();
            mario->move();
        break;

        case Qt::Key_Space:
            mario->jump();
        break;
        //Gérer le cas où on appuie sur deux touches en même temps

        default:
        break;

    }


}

void Controller::collisionreact(QString newCollisionInfo)
{
    if(newCollisionInfo == "notFalling")
    {
        if(mario->isFalling())
            mario->stand();
    }

}


