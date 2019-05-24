#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QGraphicsPixmapItem>



class Background : public QGraphicsPixmapItem
{
public:

    Background(const QPixmap &pixmap, QGraphicsItem *parent, qreal newPosX, qreal newPosY);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setPixmapSize(int w,int h);
    virtual QPainterPath shape() const;
private:

    QPixmap originPixmap;

    qreal posX;
    qreal posY;
};

#endif // BACKGROUND_H
