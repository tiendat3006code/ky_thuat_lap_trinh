#ifndef COMCONNECTION_H
#define COMCONNECTION_H

#include <QObject>
#include <QDebug>
#include <QSerialPort>
#include <QByteArray>
#include <QString>
#include <QIODevice>
#include <QChar>
#include <qqml.h>
#include <QtQml/QtQml>

class ComConnection : public QObject
{
    Q_OBJECT
public:
    explicit ComConnection(QObject *parent = nullptr);
public slots:
    void connectPort(QString portName);
    void control(int value);
    void disconnect();
signals:
private:
    QSerialPort *port;
    void sendData(QChar c);
};

#endif // COMCONNECTION_H
