#include "client.h"

static inline QByteArray IntToArray(qint32 source);

Client::Client(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
}

bool Client::connectToHost(QString host)
{
    socket->connectToHost(host, 12345);
    return socket->waitForConnected();
}

bool Client::writeData(QByteArray data)
{
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->write(IntToArray(data.size())); //write size of data
        socket->write(data); //write the data itself
        socket->waitForReadyRead();
        return socket->waitForBytesWritten();
    }
    else
        return false;
}

char* Client::getData(){
    socket->waitForReadyRead();
    socket->waitForBytesWritten();
    QByteArray data = socket->readAll();
    return data.data();
}


QByteArray IntToArray(qint32 source) //Use qint32 to ensure that the number have 4 bytes
{
    //Avoid use of cast, this is the Qt way to serialize objects
    QByteArray temp;
    QDataStream data(&temp, QIODevice::ReadWrite);
    data << source;
    return temp;
}
