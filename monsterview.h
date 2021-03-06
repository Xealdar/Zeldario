#ifndef MONSTERVIEW_H
#define MONSTERVIEW_H

#include<QGraphicsPixmapItem>
#include <QPixmap>



class MonsterController;

class MonsterView : public QGraphicsPixmapItem
{
public:
    MonsterView(QPixmap newPixmap);


    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    virtual QPainterPath shape() const;

    inline MonsterController* getController(){return controller;}

    inline QPixmap getQPixmap(){return pixmap();}
    void setQPixmap(QPixmap pixmap);




private:
    MonsterController *controller;

    void updatePixmapIndex();
    void initMediaPlayer();

    int pixmapHeightIndex = 0;
    int pixmapWidthIndex = 0;


    int count = 0;

    int pixmapHeight = 850;
    int pixmapWidth = 750;

    void setPixmapSize(int w, int h);

    QVector<QGraphicsItem*> itemsCollidingVector;

    void move();

    QList<double> dxTab;

    int dxIndex = 0;
    double dy;
    double bx = 0;

    double parabole(double x);
};

#endif // MONSTERVIEW_H
