#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QGraphicsPixmapItem>

#include <QVector>

class Background : public QGraphicsPixmapItem
{
public:
    Background(const QPixmap &pixmap, QGraphicsItem *parent = 0, qreal newPosX=0, qreal newPosY=0);
    virtual QPainterPath shape() const;

    void resizePixmap(int viewWidth, int viewHeight);

    QPixmap getResizedPixmap();

    void setPixmapSize(int w, int h);

    qreal getPosX();
    qreal getPosY();

private:
    QPixmap originPixmap;
    QPixmap resizedPixmap;
    qreal posX;
    qreal posY;
    qreal posFactor = 0.9;

    int oldViewHeight = 720;
    int oldViewWidth = 1280;
};

#endif // BACKGROUND_H
