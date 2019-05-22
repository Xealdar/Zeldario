#include "marioview2.h"

#include <QDebug>
#include <QPainter>
#include "mariocontroller.h"

#include <QGraphicsScene>

static int count = 0;

MarioView2::MarioView2(QPixmap pixmap)
{
    controller = new MarioController(this);
    this->setPixmap(pixmap);
    this->setPos(0,0);
    //this->setPos(controller->getOriginX(),controller->getOriginY());
    this->setShapeMode(QGraphicsPixmapItem::HeuristicMaskShape);

    qDebug() << "mario view init done" << pos().x() << pos().y();
}

QRectF MarioView2::boundingRect() const
{
    return QRectF(0,0,45,73);
}

QPainterPath MarioView2::shape() const
{
    return QPainterPath();
}

void MarioView2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    count++;

    painter->drawPixmap(0,0, pixmap(), pixmapIndex, 0,60, 73);
    this->setTransformOriginPoint(boundingRect().center());

    double dx = controller->getDx();
    double dy = controller->getDy();

    if(dx != 0 || dy != 0){
        moveBy(dx, dy);
        if(count % 20 == 0)
            updatePixmapIndex();
    }else
        count = 0;

    Q_UNUSED(option);
    Q_UNUSED(widget);

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

