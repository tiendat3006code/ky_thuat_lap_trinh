#include "comconnection.h"

ComConnection::ComConnection(QObject *parent)
    : QObject{parent}
{}

void ComConnection::connectPort(QString portName){
    port->setPortName(portName);
    port->setBaudRate(QSerialPort::Baud9600);
    port->setParity(QSerialPort::NoParity);
    port->setDataBits(QSerialPort::Data8);
    port->setFlowControl(QSerialPort::NoFlowControl);
    port->setStopBits(QSerialPort::OneStop);

    if(port->open(QIODevice::ReadWrite)){
        qInfo()<<"Error";
        qInfo()<<port->errorString();
    }
    else{
        qInfo()<<"Open port success";
        qInfo()<<"Ready to control";
    }
    qInfo()<<"Port connect";
    if(!port->isOpen()){
        qInfo()<<"Error in open port";
    }
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
        qInfo()<<"Set car move backward";
        sendData('b');
        break;
    case 0:
        qInfo()<<"Set car stop";
        sendData('s');
        break;
    case 2:
        qInfo()<<"Set car move right";
        sendData('r');
        break;
    case 3:
        qInfo()<<"Set car move left";
        sendData('l');
        break;
    default:
        break;
    }
}

void ComConnection::disconnect()
{
    port->close();
    qInfo()<<"Port disconnect";
}

void ComConnection::read()
{
    if(port->isOpen()){
        qInfo()<<"Port is open";
        connect(port, &QSerialPort::readyRead, this, &ComConnection::procData);
    }
    else{
        qInfo()<<"Port is close";
    }
}

void ComConnection::procData()
{
    qInfo()<<"Processing data .....";
    if(port->readAll().isEmpty()){
        qInfo()<<"Nothing to read here";
    }
    else{
        qInfo()<<"Data to read availble";
    }
}
