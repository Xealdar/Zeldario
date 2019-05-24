#include "background.h"

#include <QPainter>

Background::Background(const QPixmap &pixmap, QGraphicsItem *parent, qreal newPosX, qreal newPosY): QGraphicsPixmapItem (pixmap,parent)
{
    originPixmap = pixmap;
    posX = newPosX;
    posY = newPosY;

    setPos(this->posX,this->posY);



}

QPainterPath Background::shape() const
{
    return QPainterPath();
}


void Background::setPixmapSize(int w, int h)
{
    QPixmap resizedPixmap;
    resizedPixmap = originPixmap.scaled(w,h);
    setPixmap(resizedPixmap);
}

void Background::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawPixmap(0,0, this->pixmap(), 0, 0,2000, 2000);
    this->setTransformOriginPoint(boundingRect().center());
    Q_UNUSED(widget);
    Q_UNUSED(option);



}
