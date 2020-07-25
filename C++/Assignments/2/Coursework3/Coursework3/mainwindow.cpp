#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include <QByteArray>
#include <QString>
#include <QMessageBox>
#include <QVector>
#include <algorithm>
#include <thread>
#include <QDataStream>
#include <QTextStream>

#define FUNCTION_NAME(a, b) a ## b

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->cmbFunction->addItem("Sine integral");
    ui->cmbFunction->addItem("Cosine integral");
    ui->cmbFunction->addItem("Bessel function");
    ui->cmbFunction->addItem("Fresnel integral S");
    ui->cmbFunction->addItem("Fresnel integral C");
    ui->btnBreak->setEnabled(FALSE);
    ui->btnCompute->setEnabled(FALSE);
    connect(ui->btnConnect, &QPushButton::clicked, this, &MainWindow::Connect );
    connect(ui->cmbFunction, &QComboBox::currentTextChanged, this, &MainWindow::activateOrder);
    connect(ui->btnBreak, &QPushButton::clicked, this, &MainWindow::Break);
    connect(ui->btnCompute, &QPushButton::clicked, this, &MainWindow::Compute);
    connect(ui->btnExit, &QPushButton::clicked, this, &MainWindow::exit);
    activateOrder(ui->cmbFunction->currentText());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exit()
{
    QApplication::exit();
}


void MainWindow::Connect()
{

   pClient=new ICS0025Client;
   pConnectThread=new QThread;
   pClient->moveToThread(pConnectThread);

   connect(pConnectThread, &QThread::started, pClient, &ICS0025Client::ConnectPipe, Qt::DirectConnection);
   connect(pConnectThread, &QThread::finished, pClient, &QObject::deleteLater);
   connect(pClient, &ICS0025Client::Finished, pConnectThread, &QObject::deleteLater);
   connect(this, &MainWindow::Stop, pClient, &ICS0025Client::DisconnectPipe, Qt::DirectConnection);
   connect(pClient, &ICS0025Client::readyRead, this, &MainWindow::ReadPipe);
   connect(pClient, &ICS0025Client::serverConnected, this, &MainWindow::doConnected);
   connect(pClient, &ICS0025Client::serverDisconnected, this, &MainWindow::doDisconnected);
   connect(pClient, &ICS0025Client::connectionError, this, &MainWindow::PrintConnectionError);

   pConnectThread->start();

}

void MainWindow::Break()
{
    QChar StopMessage[] = {'S', 't', 'o', 'p'};
    int packetSize;
    packetSize=sizeof(int)+sizeof(StopMessage) + 2;
    char cpacketSize[sizeof(packetSize)];
    memcpy_s(cpacketSize, sizeof(int), &packetSize, sizeof(int));
    QString SentMessage;
    QByteArray messageData;
    SentMessage.setNum(packetSize, 10);
    messageData.append(QByteArray::fromRawData(cpacketSize, sizeof(packetSize)));
    messageData.append(reinterpret_cast<char*>(StopMessage),
                       sizeof(StopMessage));
    SentMessage += QString(StopMessage);
    PrintLog(QString("Sending ") + QString::number(packetSize) + QString(" bytes to server"));
    pClient->SendData(messageData);
    PrintLog(QString(messageData.toHex(' ')), sent_bytes);
    //PrintLog(SentMessage, sent_message);

    emit this->Stop();
    pConnectThread->quit();
    pConnectThread->wait();
    delete pConnectThread;
}


void MainWindow::Compute()
{
    try {
        ui->customPlot->addGraph();

        QChar FunctionBessel[] = {'B', 'e', 's', 's', 'e', 'l', ' ', 'f', 'u', 'n', 'c', 't', 'i', 'o', 'n'};
        QChar FunctionSine[] = {'S', 'i', 'n', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'r', 'a', 'l'};
        QChar FunctionCosine[] = {'C', 'o', 's', 'i', 'n', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'r', 'a', 'l'};
        QChar FunctionFresnelS[] = {'F', 'r', 'e', 's', 'n', 'e', 'l', ' ',
                                    'i', 'n', 't', 'e', 'g', 'r', 'a', 'l', ' ', 'S'};
        QChar FunctionFresnelC[] = {'F', 'r', 'e', 's', 'n', 'e', 'l', ' ',
                                    'i', 'n', 't', 'e', 'g', 'r', 'a', 'l', ' ', 'C'};

        QString strFunction=ui->cmbFunction->currentText();
        int indexFunction = ui->cmbFunction->currentIndex();
        double range1=ui->dblspnRangeStart->value();
        double range2=ui->dblspnRangeEnd->value();
        int nPoints=ui->spnN->value();
        int nOrder=ui->spnOrder->value();


        ///////////////////////////////////////////////////////////////////////////////////////
        char brange1_t[sizeof(range1)];
        memcpy_s(brange1_t, sizeof(range1), &range1, sizeof(range1));

        char brange2_t[sizeof(range2)];
        memcpy_s(brange2_t, sizeof(range2), &range2, sizeof(range2));

        char cN[sizeof(nPoints)];
        memcpy_s(cN, sizeof(nPoints), &nPoints, sizeof(nPoints));

        char cOrder[sizeof(nOrder)];
        memcpy_s(cOrder, sizeof(nOrder), &nOrder, sizeof(nOrder));

        int packetSize;
        switch(indexFunction){
        case 0:
            packetSize=sizeof(int)+sizeof(FunctionSine) + 2
                            + sizeof(brange1_t)+sizeof(brange2_t)+sizeof(nPoints);
            break;
        case 1:
            packetSize=sizeof(int)+sizeof(FunctionCosine) + 2
                            + sizeof(brange1_t)+sizeof(brange2_t)+sizeof(nPoints);
            break;
        case 2:
            packetSize=sizeof(int)+sizeof(FunctionBessel) + 2
                         + sizeof(brange1_t)+sizeof(brange2_t)+sizeof(nPoints)+sizeof(nOrder);
            break;
        case 3:
            packetSize=sizeof(int)+sizeof(FunctionFresnelS) + 2
                         + sizeof(brange1_t)+sizeof(brange2_t)+sizeof(nPoints);
            break;
        case 4:
            packetSize=sizeof(int)+sizeof(FunctionFresnelC) + 2
                         + sizeof(brange1_t)+sizeof(brange2_t)+sizeof(nPoints);
            break;
        }

        char cpacketSize[sizeof(packetSize)];
        memcpy_s(cpacketSize, sizeof(int), &packetSize, sizeof(int));
        ///////////////////////////////////////////////////////////////////////////////////////


        ///////////////////////////////////////////////////////////////////////////////////////
        QString SentMessage;
        QByteArray messageData;
        messageData.append(QByteArray::fromRawData(cpacketSize, sizeof(packetSize)));
        SentMessage.setNum(packetSize, 10);

        switch(indexFunction){
        case 0:
            messageData.append(reinterpret_cast<char*>(FunctionSine),
                               sizeof(FunctionSine));
            SentMessage += QString(FunctionSine);
            break;
        case 1:
            messageData.append(reinterpret_cast<char*>(FunctionCosine),
                               sizeof(FunctionCosine));
            SentMessage += QString(FunctionCosine);
            break;
        case 2:
            messageData.append(reinterpret_cast<char*>(FunctionBessel),
                               sizeof(FunctionBessel));
            SentMessage += QString(FunctionBessel);
            break;
        case 3:
            messageData.append(reinterpret_cast<char*>(FunctionFresnelS),
                               sizeof(FunctionFresnelS));
            SentMessage += QString(FunctionFresnelS);
            break;
        case 4:
            messageData.append(reinterpret_cast<char*>(FunctionFresnelC),
                               sizeof(FunctionFresnelC));
            SentMessage += QString(FunctionFresnelC);
            break;
        }

        SentMessage.setNum(range1, 'f', 2); SentMessage.setNum(range2, 'f', 2);
        SentMessage.setNum(nPoints, 10);

        messageData.append(NULLBYTE);
        messageData.append(NULLBYTE);
        messageData.append((QByteArray::fromRawData(brange1_t, sizeof(range1))));
        messageData.append(QByteArray::fromRawData(brange2_t, sizeof(range2)));
        messageData.append(QByteArray::fromRawData(cN, sizeof(nPoints)));
        if(indexFunction == 2){
            messageData.append(QByteArray::fromRawData(cOrder, sizeof(nOrder)));
            SentMessage.setNum(nOrder, 10);
        }

        PrintLog(QString("Sending ") + QString::number(packetSize) + QString(" bytes to server"));
        pClient->SendData(messageData);
        PrintLog(QString(messageData.toHex(' ')), sent_bytes);
        //PrintLog(SentMessage, sent_message);

    } catch (std::exception& err) {
        PrintLog(err.what(), LogFlag::error);
    }
}


QString MainWindow::ParseByteToMessage(QByteArray qbArray)
{
    PrintLog("Parsing server message from data bytes");

    try {
        int indexCount = 4;
        QByteArray EndOfMessage(3, NULLBYTE);
        int indexEndOfMessage = qbArray.indexOf(EndOfMessage, indexCount);
        int MessageLength = (indexEndOfMessage - indexCount + 1) / 2;
        char *cMessage = new char[MessageLength];
        for(int i = 0; indexCount <= indexEndOfMessage; indexCount++, ++i){
            if(qbArray.at(indexCount) == NULLBYTE) { i--; continue; }
            cMessage[i] = qbArray.at(indexCount);
        }
        cMessage[MessageLength] = '\0';
        return QString(cMessage);

    } catch (std::exception& err) {
        PrintLog("Parsing failed");
        PrintLog(err.what(), LogFlag::error);
        return "";
    }

}

int MainWindow::ParseByteToDouble(QByteArray qbArray, int BSize, QVector<double> & xPoint, QVector<double> & yPoint)
{
    PrintLog("Parsing points from data bytes");

    try {
        int indexCount = 4;
        QByteArray EndOfMessage(3, NULLBYTE);
        int indexEndOfMessage = qbArray.indexOf(EndOfMessage, indexCount);
        indexCount = indexEndOfMessage + 3;
        char cPoint[sizeof(double)]; double dPoint;
        bool flagX = TRUE;
        for(int i = 1; indexCount <= BSize; ++i, indexCount++){
            if(i > 8) {
                memcpy_s(&dPoint, sizeof(double), cPoint, sizeof(double));
                if(flagX) xPoint.append(dPoint);
                else yPoint.append(dPoint);
                flagX = !flagX;
                i = 1;
            }
            cPoint[i-1] = qbArray[indexCount];
        }
        return xPoint.size();

    } catch (std::exception& err) {
        PrintLog("Parsing failed");
        PrintLog(err.what(), LogFlag::error);
        return -1;
    }
}

void MainWindow::ReadPipe()
{
    PrintLog("Reading server response");
    try {

        QByteArray RespondData=pClient->ReadData();
        char cRespondSize[sizeof(int)]; int RespondSize;
        for(int i = 0; i <= sizeof(int); ++i) cRespondSize[i] = RespondData.at(i);
        memcpy_s(&RespondSize, sizeof(int), cRespondSize, sizeof(int));
        QString ServerMessage = ParseByteToMessage(RespondData);

        PrintLog(QString("Received ") + QString::number(RespondSize) + QString(" bytes from server"));
        PrintLog(QString(RespondData.toHex(' ')), received_bytes);
        PrintLog(ServerMessage, received_message);

        if(ServerMessage != "Curve"){ui->customPlot->removeGraph(0); return;}
        QVector<double> xPoint, yPoint;
        ParseByteToDouble(RespondData, RespondSize, xPoint, yPoint);
        PrintLog(QString("Drawing a plot of ")+QString::number(xPoint.size())+QString(" points"));

        ui->customPlot->graph(0)->setData(xPoint, yPoint);
        ui->customPlot->xAxis->setLabel("x");
        ui->customPlot->yAxis->setLabel("y");
        ui->customPlot->xAxis->setRange(*std::min_element(xPoint.begin(), xPoint.end()),
                                        *std::max_element(xPoint.begin(), xPoint.end()));
        ui->customPlot->yAxis->setRange(*std::min_element(yPoint.begin(), yPoint.end()),
                                        *std::max_element(yPoint.begin(), yPoint.end()));
        ui->customPlot->replot();

    } catch (std::exception& err) {
        PrintLog(err.what(), error);
    }

}

void MainWindow::activateOrder(QString str)
{
    if(str=="Bessel function") ui->spnOrder->setEnabled(TRUE);
    else ui->spnOrder->setEnabled(FALSE);
}


void MainWindow::PrintLog(QString str, LogFlag lflag)
{   QList<QString> flagTxt = {"Info", "Error", "Sent Message", "Sent Bytes",
                             "Received Message", "Received Bytes"};
    tmutex.lock();
    ui->plntextLog->insertPlainText("["+flagTxt.at(lflag) + "]: " + str + "\n");
    tmutex.unlock();
}


void MainWindow::doConnected()
{
    ui->btnConnect->setEnabled(FALSE);
    ui->btnBreak->setEnabled(TRUE);
    ui->btnCompute->setEnabled(TRUE);
    PrintLog(QString("Connection established with Server"));
}

void MainWindow::doDisconnected()
{
    ui->btnConnect->setEnabled(TRUE);
    ui->btnBreak->setEnabled(FALSE);
    ui->btnCompute->setEnabled(FALSE);
    PrintLog(QString("Disconnected from Server"));
}


void MainWindow::PrintConnectionError(QString err)
{
    PrintLog(err, error);
}
