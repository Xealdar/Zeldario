#include "collision.h"

Collision::Collision()
{

}


void Collision::collisionMaker()
{
    object1->collidesWithItem(object2);
}
