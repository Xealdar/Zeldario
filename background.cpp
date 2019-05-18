#include "background.h"

#include <qdebug.h>

Background::Background(const QPixmap &pixmap, QGraphicsItem *parent, qreal newPosX, qreal newPosY): QGraphicsPixmapItem (pixmap,parent)
{
    originPixmap = pixmap;
    posX = newPosX;
    posY = newPosY;

    this->setPos(this->posX,this->posY);

}

QPainterPath Background::shape() const
{
    return QPainterPath();
}

void Background::resizePixmap(int viewHeight, int viewWidth)
{
    resizedPixmap = originPixmap.scaled(viewHeight,viewWidth,Qt::KeepAspectRatio);
    this->moveBy(((viewWidth - oldViewWidth) * posFactor),((viewHeight-oldViewHeight) * posFactor)); //A régler pour que la position ne change pas quoi qu'il arrive quand on change la size
    this->setPixmap(resizedPixmap);
    qDebug()<<"dX"<<((viewWidth - oldViewWidth) * posFactor)<<"dY"<<((viewHeight-oldViewHeight) * posFactor);

    oldViewWidth = viewWidth;
    oldViewHeight = viewHeight;
}

QPixmap Background::getResizedPixmap()
{
    return resizedPixmap;
}

void Background::setPixmapSize(int w, int h)
{
    resizedPixmap = originPixmap.scaled(w,h);
    this->setPixmap(resizedPixmap);
}

qreal Background::getPosX()
{
    return posX;
}

qreal Background::getPosY()
{
    return posY;
}
