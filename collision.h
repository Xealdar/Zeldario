#ifndef COLLISION_H
#define COLLISION_H

#include <QGraphicsItem>

class Collision
{
public:
    Collision();

    void collisionMaker();

private:
    QGraphicsItem *object1;
    QGraphicsItem *object2;
};

#endif // COLLISION_H
