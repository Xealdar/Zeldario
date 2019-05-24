#include "monsterview.h"

#include <QDebug>
#include <QPainter>
#include "monstercontroller.h"

#include <QGraphicsScene>

#include <QtMath>


MonsterView::MonsterView(QPixmap newPixmap)
{
    controller = new MonsterController(this);
    setPixmap(newPixmap);

    setShapeMode(QGraphicsPixmapItem::HeuristicMaskShape);

    //setPixmapSize(3960,4086);
    setPixmapSize(960,1086); //-3000
    //setPixmapSize(460,586); //-3500

    controller->createRandomSpawn();
    setPos(controller->getOriginPosX(),controller->getOriginPosY());


    //qDebug()<<"tab : "<<dxTab;

}

QRectF MonsterView::boundingRect() const
{
    return QRectF(0,0,45,73);
}

QPainterPath MonsterView::shape() const
{
    QPainterPath path;
    path.addRect(0,0,100,100);
    return path;
}

void MonsterView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    count++;


    painter->drawPixmap(0,0, pixmap(), pixmapWidthIndex, pixmapHeightIndex,200, 155);


    this->setTransformOriginPoint(boundingRect().center());


    itemsCollidingVector = scene()->collidingItems(this).toVector();
    if(itemsCollidingVector.length() > 0){
        //qDebug()<<"itemsColliding : " << itemsCollidingVector;
        controller->collisionReaction(itemsCollidingVector);
    }


    move();




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

void MonsterView::move()
{

    double originDx = controller->getOriginDx();
    double originDy = controller->getOriginDy();
    MonsterController::State currentState = controller->getState();

    if(originDx != 0 || originDy != 0)
    {

        if(count % 50 == 0)
        {
            updatePixmapIndex();
        }


        if(currentState == MonsterController::IDLE)
        {
            moveBy(originDx, originDy);
        }

        else if(currentState == MonsterController::BOUNCING)
        {

            double y = parabole(bx);




            double newPos = 578 - y;
            dy = newPos - pos().y();

            //double newPos = y - pos().y();
            //dy =pos().y()-newPos;


            qDebug() << "calc y" << y << "newPos:" << newPos;
            qDebug() << "posY" << pos().y() << "dy:" << dy << "\n";
            //dy *= controller->getBouncingVelocity();
            if(originDx < 0)
                moveBy(-0.5,dy);
            else
                moveBy(0.5,dy);

            bx +=0.5;

            if(bx >= 160)
                bx = 0;

            //if(dxIndex >=79)
            //{
                //dxIndex = 0;
                //qDebug()<<"dxIndex : "<<dxIndex;
//            }
//            dxIndex++;
        }

    }
    else
        count = 0;

}

double MonsterView::parabole(double x){
    //return -0.0875*qPow(x,2) + 7*x + 1.4;
    return -0.05*qPow(x,2) + 8.3*x + 1.4;
}
