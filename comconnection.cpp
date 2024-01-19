#include "comconnection.h"

ComConnection::ComConnection(QObject *parent)
    : QObject{parent}
{}

void ComConnection::connectPort(QString portName){
    // port->setPortName(portName);
    // port->setBaudRate(QSerialPort::Baud9600);
    // port->setParity(QSerialPort::NoParity);
    // port->setDataBits(QSerialPort::Data8);
    // port->setFlowControl(QSerialPort::NoFlowControl);
    // port->setStopBits(QSerialPort::OneStop);

    // if(port->open(QIODevice::ReadWrite)){
    //     qInfo()<<"Error";
    //     qInfo()<<port->errorString();
    // }
    // else{
    //     qInfo()<<"Open port success";
    //     qInfo()<<"Ready to control";
    // }
    qInfo()<<"Port connect";
}

void ComConnection::sendData(QChar c)
{
    QByteArray data;
    data.append(c.toLatin1());
    port->write(data);
    port->waitForBytesWritten(10);
    port->flush();
    port->clear();
    port->clearError();
}

void ComConnection::control(int value)
{
    switch (value) {
    case 1:
        qInfo()<<"Set car move forward";
        sendData('f');
        break;
    case -1:
        qInfo()<<"Set car move forward";
        sendData('b');
        break;
    case 0:
        qInfo()<<"Set car move forward";
        sendData('s');
        break;
    case 2:
        qInfo()<<"Set car move forward";
        sendData('r');
        break;
    case 3:
        qInfo()<<"Set car move forward";
        sendData('l');
        break;
    default:
        break;
    }
}

void ComConnection::disconnect()
{
    // port->close();
    qInfo()<<"Port disconnect";
}
