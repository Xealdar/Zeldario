#ifndef MONSTERCONTROLLER_H
#define MONSTERCONTROLLER_H


#include <QGraphicsItem>

class MonsterView;

class MonsterController
{
public:
    MonsterController(MonsterView *view);

    inline double getOriginDx(){return originDx;}
    inline double getOriginDy(){return originDy;}

    inline double getOriginPosX(){return originPosX;}
    inline double getOriginPosY(){return originPosY;}

    inline int getPixmapIndex(){return pixmapIndex;}



    enum State
    {
        IDLE,
        DYING,
        BOUNCING,
    };

    void createRandomSpawn();

    void IA();

    void setMarioPos(double newMarioPosX, double newMarioPosY);

    void collisionReaction(QVector<QGraphicsItem*> itemsCollidingVector);

    inline State getState(){return state;}

    QList<double> setRandomDxTab(QList<double> dxTab);

    inline double getBouncingVelocity(){return bouncingVelocity;}


private:
    MonsterView *view;

    State state;

    double originDx = 0;
    double originDy = 0;
    double velocity = 0.0005;
    double bouncingVelocity = 0.0005;

    int pixmapIndex = 0;




    double directionX;
    double directionY;
    double originPosX;
    double originPosY;
    double marioPosX;
    double marioPosY;
};

#endif // MONSTERCONTROLLER_H
