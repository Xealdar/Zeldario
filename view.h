#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <background.h>


#include <QList>

class View : QGraphicsView
{

signals:
    void sceneChanged();

public:
    View(QGraphicsScene *scene);

    virtual void resizeEvent(QResizeEvent *event);



private:
    QList<QGraphicsItem*> itemsList;

};

#endif // VIEW_H
