#ifndef MARIOCONTROLLER_H
#define MARIOCONTROLLER_H

#include<QKeyEvent>

class MarioView2;

class MarioController
{

public:
    MarioController(MarioView2 *view);


    enum State
    {
        STANDING,
        STANDSHOOT,
        WALKING_LEFT,
        WALKING_RIGHT,
        JUMPING,
        FALLING,
        JUMPANDWALK,
        FALLANDWALK,
    };


    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    inline double getDx(){return dx;}
    inline double getDy(){return dy;}

    inline double getVelocity(){return velocity;}

    inline int getPixmapIndex(){return pixmapIndex;}

    inline State getState(){return state;}


private:
    MarioView2 *view;

    State state;

    double dx = 0;
    double dy = 0;
    double velocity = 0.2;

    int pixmapIndex = 0;

    void move();
    void stand();

    void swapPixmapDirection(int direction);


};

#endif // MARIOCONTROLLER_H
