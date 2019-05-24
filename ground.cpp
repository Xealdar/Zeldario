#include "ground.h"

#include <qdebug.h>

#include <QPainter>

#include "scene.h"

Ground::Ground(const QPixmap &pixmap, QGraphicsItem *parent, qreal newPosX, qreal newPosY): QGraphicsPixmapItem (pixmap,parent)
{
    originPixmap = pixmap;
    posX = newPosX;
    posY = newPosY;

    this->setPos(this->posX,this->posY);
    this->setShapeMode(QGraphicsPixmapItem::HeuristicMaskShape);

}

QPainterPath Ground::shape() const
{
    QPainterPath path;
    path.addRect(0,0,scene()->sceneRect().width(),50);
    return path;
}

void Ground::resizePixmap(int viewHeight, int viewWidth)
{
    resizedPixmap = originPixmap.scaled(viewHeight,viewWidth,Qt::KeepAspectRatio);
    this->moveBy(((viewWidth - oldViewWidth) * posFactor),((viewHeight-oldViewHeight) * posFactor)); //A régler pour que la position ne change pas quoi qu'il arrive quand on change la size
    this->setPixmap(resizedPixmap);
    qDebug()<<"dX"<<((viewWidth - oldViewWidth) * posFactor)<<"dY"<<((viewHeight-oldViewHeight) * posFactor);

    oldViewWidth = viewWidth;
    oldViewHeight = viewHeight;
}

QPixmap Ground::getResizedPixmap()
{
    return resizedPixmap;
}

void Ground::setPixmapSize(int w, int h)
{
    resizedPixmap = originPixmap.scaled(w,h);
    this->setPixmap(resizedPixmap);
}

qreal Ground::getPosX()
{
    return posX;
}

qreal Ground::getPosY()
{
    return posY;
}

QRectF Ground::boundingRect() const
{
    return QRectF(0,0,2000,2000);
}

void Ground::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawPixmap(0,0, this->pixmap(), 0, 0,2000, 2000);
    this->setTransformOriginPoint(boundingRect().center());
    Q_UNUSED(widget);
    Q_UNUSED(option);



}
