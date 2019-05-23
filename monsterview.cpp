#include "monsterview.h"

#include <QDebug>
#include <QPainter>
#include "monstercontroller.h"

#include <QGraphicsScene>



MonsterView::MonsterView(QPixmap newPixmap)
{
    controller = new MonsterController(this);
    setPixmap(newPixmap);

    setShapeMode(QGraphicsPixmapItem::HeuristicMaskShape);

    //setPixmapSize(3960,4086);
    setPixmapSize(960,1086); //-3000
    //setPixmapSize(460,586); //-3500

    controller->createRandomSpawn();
    setPos(controller->PosX(),controller->PosY());

}

QRectF MonsterView::boundingRect() const
{
    return QRectF(0,0,45,73);
}

QPainterPath MonsterView::shape() const
{
    return QPainterPath();
}

void MonsterView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    count++;


    painter->drawPixmap(0,0, pixmap(), pixmapWidthIndex, pixmapHeightIndex,200, 155);


    this->setTransformOriginPoint(boundingRect().center());

/*
    QList<QGraphicsItem*> itemsCollidingList = scene()->collidingItems(this);
    if(itemsCollidingList.size() > 0){
        qDebug() << itemsCollidingList;
    }
*/
    double dx = controller->getDx();
    double dy = controller->getDy();



    if(dx != 0 || dy != 0){
        //moveBy(dx, dy);
        if(count % 50 == 0)
        {

            updatePixmapIndex();
        }


    } else
        count = 0;

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void MonsterView::updatePixmapIndex()
{


    pixmapWidthIndex += 250;
    if (pixmapWidthIndex >= pixmapWidth) {
        pixmapWidthIndex = 0;
        pixmapHeightIndex += 170;
    }
    if(pixmapHeightIndex >= pixmapHeight)

        pixmapHeightIndex = 0;


}



void MonsterView::setQPixmap(QPixmap pixmap){
    setPixmap(pixmap);
}

void MonsterView::setPixmapSize(int w, int h)
{
    QPixmap resizedPixmap;
    resizedPixmap = pixmap().scaled(w,h,Qt::KeepAspectRatio);
    this->setPixmap(resizedPixmap);
}

