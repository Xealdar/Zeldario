#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include <QThread>
#include "client.h"
#include "mariocontroller.h"

class ClientThread : public QThread
{
public:
    ClientThread(MarioController *controller);

private:
    Client *client;
    MarioController *controller;

protected:
    void run();
};

#endif // CLIENTTHREAD_H
