#include "marioview2.h"

#include <QDebug>
#include <QPainter>
#include "mariocontroller.h"

#include <QGraphicsScene>

int count = 0;

MarioView2::MarioView2(QPixmap pixmap, int originX, int originY)
{
    controller = new MarioController(this);
    setPixmap(pixmap);
    setPos(originX,originY);
    setShapeMode(QGraphicsPixmapItem::HeuristicMaskShape);
    initMediaPlayer();

    qDebug() << "mario view init done" << pos().x() << pos().y();
}

QRectF MarioView2::boundingRect() const
{
    return QRectF(0,0,45,73);
}

QPainterPath MarioView2::shape() const
{
    QPainterPath path;
    path.addRect(0,0,35,73);
    return path;
}

void MarioView2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    count++;

    painter->drawPixmap(0,0, pixmap(), pixmapIndex, 0,60, 73);
    this->setTransformOriginPoint(boundingRect().center());


    QList<QGraphicsItem*> itemsCollidingList = scene()->collidingItems(this);
    if(itemsCollidingList.size() > 0){
        qDebug() << itemsCollidingList;
    }

    double dx = controller->getDx();
    double dy = controller->getDy();

    if(dx != 0 || dy != 0){
        moveBy(dx, dy);
        if(count % 8 == 0)
            updatePixmapIndex();
    } else
        count = 0;

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void MarioView2::initMediaPlayer(){
    mediaPlayer = new QMediaPlayer();
    mediaPlayer->setMedia(QUrl("qrc:/sounds/billie_jean.mp3"));
}

void MarioView2::playMJ(){
    if(mediaPlayer != nullptr && mediaPlayer->state() != QMediaPlayer::PlayingState){
        mediaPlayer->play();
    }
}

void MarioView2::pauseMJ(){
    if(mediaPlayer != nullptr && mediaPlayer->state() == QMediaPlayer::PlayingState){
        mediaPlayer->pause();
    }
}

void MarioView2::updatePixmapIndex()
{
    pixmapIndex += 57;
    if (pixmapIndex >= 1191 ) {
        pixmapIndex = 0;
    }
}

void MarioView2::setQPixmap(QPixmap pixmap){
    setPixmap(pixmap);
}

