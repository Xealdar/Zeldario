#ifndef MARIOVIEW2_H
#define MARIOVIEW2_H

#include<QGraphicsPixmapItem>
#include <QMediaPlayer>

class MarioController;

class MarioView2 : public QGraphicsPixmapItem
{
public:
    MarioView2(QPixmap newPixmap, int originX, int originY);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    virtual QPainterPath shape() const;

    inline MarioController* getController(){return controller;}

    inline QPixmap getQPixmap(){return pixmap();}
    void setQPixmap(QPixmap pixmap);
    void playMJ();
    void pauseMJ();


private:
    MarioController *controller;

    void updatePixmapIndex();
    void initMediaPlayer();

    int pixmapIndex = 0;
    QMediaPlayer *mediaPlayer;
};

#endif // MARIOVIEW2_H
