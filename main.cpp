#include <QCoreApplication>
#include <string>
#include <iostream>
#include "client.h"
#include "player.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string name;
    cout<<"Unesite ime: "<<endl;
    cin>>name;
    Player* player=new Player(name);
    client mTest;
    mTest.Test(player);
    return a.exec();
}
