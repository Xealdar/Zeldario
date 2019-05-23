#include "mushroom.h"
#include <QPainter>
#include <QDebug>

Mushroom::Mushroom(QRectF platformRect, int direction,QGraphicsItem *parent): QGraphicsItem(parent),mCurrentFrame(),mPlatform(platformRect), mDirection(direction)

{
    setFlag(ItemClipsToShape);
    mPixmap = QPixmap(":images/m40.png");
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(nextFrame()));
    timer->start(100);
    up= true;
    down = true;
    right = true;
    right2 = false;
}

Mushroom::~Mushroom(){

}

void Mushroom::nextFrame(){

    if(up) {
        if(this->pos().y() > mPlatform.y()-40) {

            setPos(this->pos().x(), this->pos().y() - (mDirection *5));
        }
    }
    if(right){
        if(this->pos().y() == mPlatform.y() -42) {

            up = false;
            setPos(this->pos().x() + (mDirection *5), this->pos().y());
        }
    }

    if(down) {
        if(this->pos().x() > mPlatform.x() + mPlatform.width()+20) {

            right = false;
            setPos(this->pos().x() , this->pos().y() + (mDirection *25));
        }
    }

    if(this->pos().y() > 619) {

        down =false;
        setPos(this->pos().x() + (mDirection *5), 620);
    }

}

QRectF Mushroom::boundingRect() const {
    return QRectF(0,0,70,50);

}

void Mushroom::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0,0, mPixmap, mCurrentFrame, 0,70, 50);
    setTransformOriginPoint(boundingRect().center());
    Q_UNUSED(widget);
    Q_UNUSED(option);

}

int Mushroom::type() const {
    return Type;
}


