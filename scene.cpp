#include <scene.h>

#include <QDebug>

#include <QKeyEvent>



#include <QPainter>


Scene::Scene(QObject *parent) : QGraphicsScene(0,0,8000,720, parent)


{
    Scene::initWorld();
    controller = new Controller(mario);
}



void Scene::initWorld()
{


    sky = new Background(QPixmap(":Images/sky.png"),0,0,0);
    //sky->setZValue(1);

    addItem(sky);

    ground = new Background(QPixmap(":Images/ground2.png"),0,0,groundYPosition);
    //ground->setZValue(2);
    addItem(ground);

    mario = new Mario(0,groundYPosition - 70);
    //mario->getCurrentQGraphicsItem()->setZValue(3);
    addItem(mario->getCurrentQGraphicsItem());


}


void Scene::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {

        case Qt::Key_Right:
            controller->checkInputPushed(Qt::Key_Right);

        break;

        case Qt::Key_Left:
            controller->checkInputPushed(Qt::Key_Left);
        break;

        case Qt::Key_Space:
            controller->checkInputPushed(Qt::Key_Space);
        break;

        default:
        break;

    }
}

void Scene::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat())
        return;

    switch(event->key())
    {
        case Qt::Key_Right:
            controller->checkInputReleased(Qt::Key_Right);
        break;

        case Qt::Key_Left:
            controller->checkInputReleased(Qt::Key_Left);
        break;

        case Qt::Key_Space:
            controller->checkInputReleased(Qt::Key_Space);
        break;
        //Gérer le cas où on appuie sur deux touches en même temps

        default:
        break;

    }
}









/*bool Scene::getIsRightPushed()
{
    return isRightPushed;
}

bool Scene::getIsLeftPushed()
{
    return isLeftPushed;
}

bool Scene::getIsJumpPushed()
{
    return isJumpPushed;
}*/




