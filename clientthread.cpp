#include "clientthread.h"
#include <QDebug>

ClientThread::ClientThread(MarioController *controller)
{
    client = new Client();
    this->controller = controller;

}

void ClientThread::run()
{
    qDebug("thread started");

    int connected = client->connectToHost("localhost");
    qDebug() << "connected to server ? " << connected;

    while(connected){
        char* label = client->getData();
        qDebug() << label;

        if(strcmp(label, "disconnect") == 0){
            client->disconnect();
            break;
        }

        if(strcmp(label, "goUp") == 0){
            QKeyEvent *event = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Space, nullptr);
            controller->keyPressEvent(event);
        }

        if(strcmp(label, "goRight") == 0){
            QKeyEvent *event = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Right, nullptr);
            controller->keyPressEvent(event);
        }

        if(strcmp(label, "goLeft") == 0){
            QKeyEvent *event = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Left, nullptr);
            controller->keyPressEvent(event);
        }

        if(strcmp(label, "default") == 0){
            QKeyEvent *event = new QKeyEvent(QKeyEvent::KeyRelease, Qt::Key_Right, nullptr);
            controller->keyReleaseEvent(event);
        }
    }

}
