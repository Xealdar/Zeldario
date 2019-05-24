#include "mariocontroller.h"
#include "marioview2.h"
#include <QDebug>
#include <QTimer>

MarioController::MarioController(MarioView2 *view)
{
    this->view = view;
    qDebug() << view;
}


void MarioController:: move(){

    switch(state){
        case WALKING_LEFT:
            dx = -1 * velocity;
            dy = 0;
            view->playMJ();
        break;

        case WALKING_RIGHT:
            dx = velocity;
            dy = 0;
            view->pauseMJ();
        break;

        case FALLING:
            dy = velocity;

        break;

        case JUMPING:
            dy = -velocity;

        break;
    }

}

void MarioController:: stand(){
    pixmapIndex = 0;
    dx = 0;
    dy = 0;
    view->pauseMJ();
}


void MarioController::swapPixmapDirection(int direction)
{
    QPixmap swappedPixmap;
    swappedPixmap = view->getQPixmap().transformed(QTransform().scale(direction,1));
    view->setQPixmap(swappedPixmap);
}


void MarioController::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Right:
            state = WALKING_RIGHT;
            move();
        break;
        case Qt::Key_Left:
            state = WALKING_LEFT;
            move();
        break;
        case Qt::Key_Down:
            state = FALLING;
            move();
        break;
        case Qt::Key_Space:
            state = JUMPING;
            move();
        break;
    }
}

void MarioController::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Right:
        case Qt::Key_Left:
            state = STANDING;
            stand();
        break;
    }
}



