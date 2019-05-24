#ifndef GROUND_H
#define GROUND_H

#include <QGraphicsPixmapItem>

#include <QVector>

class Ground : public QGraphicsPixmapItem
{
public:
    Ground(const QPixmap &pixmap, QGraphicsItem *parent = 0, qreal newPosX=0, qreal newPosY=0);
    virtual QPainterPath shape() const;

    void resizePixmap(int viewWidth, int viewHeight);

    QPixmap getResizedPixmap();

    void setPixmapSize(int w, int h);

    qreal getPosX();
    qreal getPosY();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private:
    QPixmap originPixmap;
    QPixmap resizedPixmap;
    qreal posX;
    qreal posY;
    qreal posFactor = 0.9;

    int oldViewHeight = 720;
    int oldViewWidth = 1280;
};

#endif // GROUND_H
