#include "Charactview.h"
#include <QDebug>
#include <QPainter>

CharactView::CharactView(QPixmap newPixmap, int newPosX, int newPosY)
{
    originPixmap = newPixmap;
    posX = newPosX;
    posY = newPosY;
    this->setPixmap((originPixmap));
    this->setPos(this->posX,this->posY);

}

QPainterPath CharactView::shape() const
{
    return QPainterPath();
}


void CharactView::nextFrame()
{
    mCurrentFrame += 57;
    if (mCurrentFrame >= 1191 ) {
        mCurrentFrame = 0;
    }
}

QRectF CharactView::boundingRect() const
{
    return QRectF(0,0,45,73);
}

void CharactView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0, this->pixmap(), mCurrentFrame, 0,60, 73);
    this->setTransformOriginPoint(boundingRect().center());
    Q_UNUSED(widget);
    Q_UNUSED(option);
}


void CharactView::swapPixmapDirection(int direction)
{
    QPixmap swappedPixmap;
    swappedPixmap = originPixmap.transformed(QTransform().scale(direction,1));
    this->setPixmap(swappedPixmap);
}

void CharactView::setPixmapSize(int w, int h)
{
    QPixmap resizedPixmap;
    resizedPixmap = originPixmap.scaled(w,h);
    this->setPixmap(resizedPixmap);
}
