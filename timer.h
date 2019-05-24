#ifndef TIMER_H
#define TIMER_H

#include <QGraphicsTextItem>

class Timer: public QGraphicsTextItem{
public:
    Timer(QGraphicsItem * parent=0);
    void decrease();
    int getTime();
    void timerEvent(QTimerEvent *);


    void timerEvent(QTimer);

private:
    int timeCount;
};

#endif // TIMER_H
