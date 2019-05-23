#include "mario.h"
#include <QKeyEvent>
#include <QPainter>
#include <QDebug>




Mario::Mario(int newPosX, int newPosY)
{
    posX = newPosX;
    posY = newPosY;

    mStandingPixmap = QPixmap(":Images/marioStop.png");
    mWalkPixmap = QPixmap(":Images/marioWalk.png");
    mShootPixmap = QPixmap("Images/marioStop.png");
    mCurrentPixmap = mWalkPixmap;

    currentQGraphicsItem = new MarioView(mCurrentPixmap,this->posX,this->posY);

    stand();

}

Mario::~Mario()
{

}

void Mario::stand()
{
    mCurrentFrame = 0;
    mCurrentPixmap = mStandingPixmap;
    mCurrentState = STANDING;
    currentQGraphicsItem->setPixmap(mCurrentPixmap);
    currentQGraphicsItem->setCurrentState("STANDING");

}

void Mario::jump()
{
    mCurrentState = JUMPING;


}



void Mario::walk()
{
    mCurrentFrame = 0;
    if(mCurrentState == WALKING )
    {
        return;
    }

    mCurrentPixmap = mWalkPixmap;
    currentQGraphicsItem->setPixmap(mCurrentPixmap);
    mCurrentState = WALKING;
    currentQGraphicsItem->setCurrentState("WALKING");


}

void Mario::fall()
{
    mCurrentState = FALLING;
}

void Mario::jumpAndWalk()
{
    mCurrentState = JUMPANDWALK;
}

void Mario::fallAndWalk()
{
    mCurrentState = FALLANDWALK;
}

bool Mario::isFalling()
{
    return mCurrentState == FALLING;
}

int Mario::getDirection() const
{
    return mDirection;
}

int Mario::getStandingDirection() const
{
    return mStandingDirection;
}


bool Mario::isColliding(QGraphicsItem *item) //Check si je garde
{
    return this->currentQGraphicsItem->collidesWithItem(item);
}

void Mario::move()
{
    if(mCurrentState == WALKING)
    {

        //currentQGraphicsItem->swapPixmapDirection(mDirection);
        dx = mDirection * mVelocity;
        dy = 0;
        currentQGraphicsItem->moveBy(dx,dy);
        //currentQGraphicsItem->nextFrame();
    }

    else if(mCurrentState == JUMPING)
    {
        dx = 0;
        dy = -mVelocity;
        currentQGraphicsItem->moveBy(dx,dy);
    }

    else if(mCurrentState == FALLING)
    {
        dx = 0;
        dy = mVelocity;
        currentQGraphicsItem->moveBy(dx,dy);
    }

    else if(mCurrentState == JUMPANDWALK)
    {
        dx = mDirection * mVelocity;
        dy = -mVelocity;
        currentQGraphicsItem->moveBy(dx,dy);
        currentQGraphicsItem->nextFrame();
    }

    else if(mCurrentState == FALLANDWALK)
    {
        dx = mDirection * mVelocity;
        dy = mVelocity;
        currentQGraphicsItem->moveBy(dx,dy);
        currentQGraphicsItem->nextFrame();
    }
}



QGraphicsPixmapItem* Mario::getCurrentQGraphicsItem()
{
    return currentQGraphicsItem;
}


void Mario::setDirection(int newDirection)
{
    mDirection = newDirection;
}


int Mario::getCurrentFrame()
{
    return mCurrentFrame;
}


Mario::State Mario::getCurrentState()
{
    return mCurrentState;
}


/*
 * Pour les classes de perso et d'intelligence, dedans il faut qu'il
 * y ait de la data et du controller, et il faut qu'il ait un QGraphicsItem mais pas qu'il en hérite.
 * Faire un little mario dans mario, pas besoin de refaire une classe
*/
