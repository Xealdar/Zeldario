#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QString>
#include <QThread>

#include <mario.h>

class Controller
{
public:
    Controller(Mario *newMario);
    void checkInputPushed(int newInput);
    void moveCharact(int inputPushed);
    void checkInputReleased(int newInput);
    void collisionreact(QString newCollisionInfo);

private:
    int inputPushed = Qt::Key_Right;
    int inputReleased = 1000;
    Mario *mario;
    bool isPushed;




};

#endif // CONTROLLER_H
