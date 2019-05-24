#ifndef MUSHROOM_H
#define MUSHROOM_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QTimer>
#include <QObject>
#include <typeinfo>
#include <QGraphicsScene>

class Mushroom : public QObject, public QGraphicsItem
{

public:
    //enum { Type = UserType + mushroomType };
    Mushroom(QRectF platformRect, int direction,QGraphicsItem *parent = 0);
    virtual ~Mushroom();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int type() const;
    //const int mushroomType = 18;

public slots:
    void nextFrame();

signals:
    void marioSizeStatus(int);

private:

    int mCurrentFrame;
    QPixmap mPixmap;
    QRectF mPlatform;
    int mDirection;
    bool up;
    bool right;
    bool down;
    bool right2;

};
#endif // MUSHROOM_H
