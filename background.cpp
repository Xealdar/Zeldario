#include "background.h"

#include <qdebug.h>

#include <QPainter>

Background::Background(const QPixmap &pixmap, QGraphicsItem *parent, qreal newPosX, qreal newPosY): QGraphicsPixmapItem (pixmap,parent)
{
    originPixmap = pixmap;
    posX = newPosX;
    posY = newPosY;

    this->setPos(this->posX,this->posY);
    this->setShapeMode(QGraphicsPixmapItem::HeuristicMaskShape);

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

QRectF Background::boundingRect() const
{
    return QRectF(0,0,2000,2000);
}

void Background::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawPixmap(0,0, this->pixmap(), 0, 0,2000, 2000);
    this->setTransformOriginPoint(boundingRect().center());
    Q_UNUSED(widget);
    Q_UNUSED(option);



}
