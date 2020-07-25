#include "ics0025client.h"


ICS0025Client::ICS0025Client(QObject *parent):QObject(parent)
{}


void ICS0025Client::ConnectPipe()
{
    connect(&this->clientpipe, &QLocalSocket::connected, this, &ICS0025Client::emitConnected);
    this->clientpipe.connectToServer("\\\\.\\pipe\\ICS0025", QIODevice::ReadWrite);
    connect(&this->clientpipe, &QLocalSocket::readyRead, this, &ICS0025Client::ReadyData);
    connect(&this->clientpipe, &QLocalSocket::disconnected, this, &ICS0025Client::emitDisconnected);
    connect(&this->clientpipe, QOverload<QLocalSocket::LocalSocketError>::of(&QLocalSocket::error),
            this, &ICS0025Client::emitConectionError);
}

void ICS0025Client::DisconnectPipe()
{
    //this->ConnectionStatus=0;
    clientpipe.disconnectFromServer();
}

quint64 ICS0025Client::SendData(QByteArray data)
{
    return this->clientpipe.write(data);
}

QByteArray ICS0025Client::ReadData()
{
    return this->clientpipe.readAll();
}

void ICS0025Client::ReadyData()
{
    emit readyRead();
}

void ICS0025Client::emitConnected()
{
    emit serverConnected();
}

void ICS0025Client::emitDisconnected()
{
    emit serverDisconnected();
}

void ICS0025Client::emitConectionError()
{
    emit connectionError(this->clientpipe.errorString());
}
