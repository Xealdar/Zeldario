#ifndef MONSTERCONTROLLER_H
#define MONSTERCONTROLLER_H

class MonsterView;

class MonsterController
{
public:
    MonsterController(MonsterView *view);

    inline double getDx(){return dx;}
    inline double getDy(){return dy;}

    inline int PosX(){return posX;}
    inline int PosY(){return posY;}

    inline int getPixmapIndex(){return pixmapIndex;}

    enum State
    {
        WALKING_RIGHT,
        WALKING_LEFT,
        DYING,
    };

    void createRandomSpawn();

    void IA();

private:
    MonsterView *view;

    State state;

    double dx = 0;
    double dy = 0;
    double velocity = 0.15;

    int pixmapIndex = 0;

    void move();


    int direction;
    int posX;
    int posY;

};

#endif // MONSTERCONTROLLER_H
