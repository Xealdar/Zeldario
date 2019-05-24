#include "castle.h"

Castle::Castle(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)

{

   setPixmap(QPixmap(":images/castle.png"));
}

int Castle::type() const
{
    return Type;
}
