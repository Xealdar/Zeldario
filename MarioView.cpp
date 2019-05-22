#include "MarioView.h"
#include <QDebug>
#include <QPainter>

#include <QGraphicsScene>

MarioView::MarioView(QPixmap newPixmap, int newPosX, int newPosY)
{
    originPixmap = newPixmap;
    posX = newPosX;
    posY = newPosY;
    this->setPixmap((originPixmap));
    this->setPos(this->posX,this->posY);
    this->setShapeMode(QGraphicsPixmapItem::HeuristicMaskShape);

}

QPainterPath MarioView::shape() const
{
    return QPainterPath();
}


void MarioView::nextFrame()
{
    mCurrentFrame += 57;
    if (mCurrentFrame >= 1191 ) {
        mCurrentFrame = 0;
    }
}

QRectF MarioView::boundingRect() const
{
    return QRectF(0,0,45,73);
}

void MarioView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawPixmap(0,0, this->pixmap(), mCurrentFrame, 0,60, 73);
    this->setTransformOriginPoint(boundingRect().center());
    Q_UNUSED(widget);
    Q_UNUSED(option);


    //collision
    QList<QGraphicsItem*> itemsCollidingList;
    itemsCollidingList = scene()->collidingItems(this);

    qDebug()<<"isNotColliding ? : "<<itemsCollidingList.isEmpty();
}

void MarioView::swapPixmapDirection(int direction)
{
    QPixmap swappedPixmap;
    swappedPixmap = originPixmap.transformed(QTransform().scale(direction,1));
    this->setPixmap(swappedPixmap);
}

void MarioView::setPixmapSize(int w, int h)
{
    QPixmap resizedPixmap;
    resizedPixmap = originPixmap.scaled(w,h);
    this->setPixmap(resizedPixmap);
}

void MarioView::setCurrentState(QString newState)
{
    mCurrentState = newState;
}



