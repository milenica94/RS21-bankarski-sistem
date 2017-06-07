#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QAbstractSocket>

#include "player.h"

class client : public QObject
{
    Q_OBJECT
public:
    explicit client(QObject *parent = 0);
    void Test(Player*);

signals:

public slots:
    void connected();
    void disconnected();
    void readyRead();
private:
    QTcpSocket *_socket;
};

#endif // CLIENT_H
