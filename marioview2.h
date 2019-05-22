#ifndef MARIOVIEW2_H
#define MARIOVIEW2_H

#include<QGraphicsPixmapItem>

class MarioController;

class MarioView2 : public QGraphicsPixmapItem
{
public:
    MarioView2(QPixmap newPixmap);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    virtual QPainterPath shape() const;

    inline MarioController* getController(){return controller;}

    inline QPixmap getQPixmap(){return pixmap();}
    void setQPixmap(QPixmap pixmap);


private:
    MarioController *controller;

    void updatePixmapIndex();

    int pixmapIndex = 0;
};

#endif // MARIOVIEW2_H
