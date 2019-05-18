#ifndef MARIO_H
#define MARIO_H

#include <QGraphicsItem>

#include <Charactview.h>



class Mario
{

public:
    Mario(int newPosX, int newPosY);

    ~Mario();


    enum State
    {
        STANDING,
        STANDSHOOT,
        WALKING,
        JUMPING,
        FALLING,
        JUMPANDWALK,
        FALLANDWALK,
    };

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    // Voir si j'ai besoin de ces trois bools
   /* bool isFootColliding(QGraphicsItem *item);
    bool isHeadColliding(QGraphicsItem *item);
    bool isPlatformColliding(QGraphicsItem *item);*/

    bool isColliding(QGraphicsItem *item);

    int getDirection() const;
    int getStandingDirection() const;
    void stand();
    void jump();
    void walk();
    void fall();
    bool isFalling();
    void jumpAndWalk();
    void fallAndWalk();


    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    //QRectF boundingRect() const;
    void move();
    //void nextFrame();

    void setDirection(int newDirection);

    QGraphicsPixmapItem *getCurrentQGraphicsItem();

    int getCurrentFrame();
    State getCurrentState();

private:


    int mDirection;
    int mStandingDirection;
    int mCurrentFrame;

    State mCurrentState;


    QPixmap mWalkPixmap;
    QPixmap mStandingPixmap;
    QPixmap mJumpPixmap; //Trouver une image
    QPixmap mShootPixmap;
    QPixmap mCurrentPixmap;



    qreal dx;
    qreal dy;
    qreal mVelocity = 5;

    int posX;
    int posY;


    CharactView *currentQGraphicsItem;


};

#endif // MARIO_H
