#include "client.h"
#include "player.h"

#include <QTcpSocket>
#include <QDebug>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::vector<std::string> split(const std::string & str)
{
    std::vector<std::string> result;

    auto i = str.cbegin();
    while (i != str.cend()) {
        i = std::find_if_not(i, str.cend(), [](unsigned char c){return c==';';} );
        auto j = std::find_if(i, str.cend(), [](unsigned char c){return c==';';} );
        if (i != str.cend()) {
            result.push_back(std::string(i, j));
        }
        i = j;
    }
    return result;
}

client::client(QObject *parent) : QObject(parent) {}

void client::Test(Player* player){
    _socket=new QTcpSocket(this);
    connect(_socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(_socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(_socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    qDebug()<<"Connecting...";
    _socket->connectToHost("localhost",1234);
    if(!_socket->waitForConnected(1000)){
        qDebug() << "Error: " << _socket->errorString();
     }
}

void client::connected(){
    qDebug() << "Connected!";
}

void client::disconnected(){
    qDebug() << "Disconnected!";
}


void client::readyRead(){

    QString line = QString::fromUtf8(_socket->readAll()).trimmed();
    _socket->flush();
     if ( line.startsWith("Pitanje") ) {
     std::vector<std::string> lines = split(line.toUtf8().constData());
     string pitanje = lines[0];
     pitanje.append(" poena: ");
     pitanje.append("\n"+lines[1]);
     pitanje.append("\n"+lines[2]);
     pitanje.append("\n"+lines[3]);

     if (lines.size() >= 5)
         pitanje.append("\n"+lines[4]);
     if (lines.size() >= 6)
        pitanje.append("\n"+lines[5]);

     qDebug() << QString::fromStdString("********************************************************************************").toUtf8().constData();
     qDebug() << QString::fromStdString(pitanje).toUtf8().constData();

     string odgovor;
     cin >> odgovor;
     odgovor.append("\n");
     _socket->write(QString::fromStdString(odgovor).toUtf8().constData());
     _socket->flush();
    }

    else {
        qDebug() << QString::fromStdString("********************************************************************************").toUtf8().constData();
        qDebug().noquote() << line; //prima poene zajedno sa info tacan/netacan
        _socket->flush();
    }
    _socket->flush();
 }
