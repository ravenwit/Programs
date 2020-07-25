#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ICS0025Client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    ICS0025Client *pClient=nullptr;
    QThread *pConnectThread;
    QMutex tmutex;
    static const char NULLBYTE='\x00';
    enum LogFlag { info = 0, error = 1, sent_message = 2, sent_bytes = 3,
                 received_message = 4, received_bytes = 5};
    QString ParseByteToMessage(QByteArray);
    int ParseByteToDouble(QByteArray, int, QVector<double>&, QVector<double>&);
    void PrintLog(QString, LogFlag lflag = LogFlag::info);

signals:
    void Stop();
    void Exit();

private slots:
    void activateOrder(QString);
    void Connect();
    void Compute();
    void ReadPipe();
    void Break();
    void exit();

    void doConnected();
    void doDisconnected();
    void PrintConnectionError(QString);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
