#ifndef MONSTERCONTROLLER_H
#define MONSTERCONTROLLER_H



class MonsterView;

class MonsterController
{
public:
    MonsterController(MonsterView *view);

    inline double getDx(){return dx;}
    inline double getDy(){return dy;}

    inline double getOriginPosX(){return originPosX;}
    inline double getOriginPosY(){return originPosY;}

    inline int getPixmapIndex(){return pixmapIndex;}

    enum State
    {
        WALKING_RIGHT,
        WALKING_LEFT,
        DYING,
    };

    void createRandomSpawn();

    void IA();

    void setMarioPos(double newMarioPosX, double newMarioPosY);

private:
    MonsterView *view;

    State state;

    double dx = 0;
    double dy = 0;
    double velocity = 0.0005;

    int pixmapIndex = 0;

    void move();


    double directionX;
    double directionY;
    double originPosX;
    double originPosY;
    double marioPosX;
    double marioPosY;
};

#endif // MONSTERCONTROLLER_H
