#ifndef CHARACTVIEW_H
#define CHARACTVIEW_H

#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsPixmapItem>



class MarioView : public QGraphicsPixmapItem
{
public:
    MarioView(QPixmap newPixmap, int newPosX, int newPosY);
    virtual QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void nextFrame();
    QRectF boundingRect() const;
    void setPixmapSize(int w, int h);


    void swapPixmapDirection(int direction);

    void setCurrentState(QString newState);

    void move();

private:


    QPixmap originPixmap;
    qreal posX;
    qreal posY;

    int mCurrentFrame;
    QString mCurrentState;


};

#endif // CHARACTVIEW_H
