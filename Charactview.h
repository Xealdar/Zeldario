#ifndef CHARACTVIEW_H
#define CHARACTVIEW_H


#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsPixmapItem>


class CharactView : public QGraphicsPixmapItem
{
public:
    CharactView(QPixmap newPixmap, int newPosX, int newPosY);
    virtual QPainterPath shape() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void nextFrame();
    QRectF boundingRect() const;
    void setPixmapSize(int w, int h);


    void swapPixmapDirection(int direction);

private:


    QPixmap originPixmap;
    qreal posX;
    qreal posY;

    int mCurrentFrame;


};

#endif // CHARACTVIEW_H
