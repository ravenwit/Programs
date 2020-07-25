#ifndef ICS0025CLIENT_H
#define ICS0025CLIENT_H

#include <QObject>
#include <QMutex>
#include <QWaitCondition>
#include <QByteArray>
#include <QLocalSocket>

class ICS0025Client : public QObject
{
    Q_OBJECT
public:
    //bool ConnectionStatus=0;
    explicit ICS0025Client(QObject *parent = nullptr);
    quint64 SendData(QByteArray);
    QByteArray ReadData();

private:
    QMutex tmutex;
    QLocalSocket clientpipe;
    QWaitCondition stopsig;

signals:
    void Finished();
    void readyRead();
    void serverConnected();
    void serverDisconnected();
    void connectionError(QString);

private slots:
    void ReadyData();
    void emitConnected();
    void emitDisconnected();
    void emitConectionError();

public slots:
    void ConnectPipe();
    void DisconnectPipe();

};

#endif // ICS0025CLIENT_H
