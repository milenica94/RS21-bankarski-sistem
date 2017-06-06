#include "room.h"
#include "question.h"
#include "questionabcd.h"
#include "rebus.h"
#include "player.h"

#include <QString>
#include <map>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include <QDebug>


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

Room::Room(map<int,string> kategorija,int rbr_sobe)
    :_rbr_sobe(rbr_sobe)
{

    string naziv[3],linija;
    int poeni;
    QString tekst;
    QString correctAnswer;
    QString answer1, answer2, answer3, answer4;

    for(int j = 0; j < 3; j++){
        random_device rd;
        uniform_int_distribution<int> dist(0,3);
        auto r = dist(rd);

        int i = r%3 + 1;

        naziv[j]=to_string(j+1)+kategorija[rbr_sobe]+to_string(i)+".txt";
        ifstream in("C:\\Users\\Natalija\\Desktop\\Fakultet\\IV godina\\Razvoj softvera\\projekat\\labirinthGUI3\\"+naziv[j],ifstream::in);
        getline(in,linija);

        switch(j){
        case 0:
            poeni=10;
            break;
        case 1:
            poeni=20;
            break;
        case 2:
            poeni=30;
            break;
        }

       vector<string> linije=split(linija);
       tekst=QString::fromStdString(linije[0]);
       correctAnswer=QString::fromStdString(linije[1]);

        if(kategorija[rbr_sobe] != "igraonica"){

            answer1=QString::fromStdString(linije[2]);
            answer2=QString::fromStdString(linije[3]);
            if(linije.size()>=5)
                answer3=QString::fromStdString(linije[4]);
            if(linije.size()==6)
                answer4=QString::fromStdString(linije[5]);

            QuestionABCD* q1=new QuestionABCD(poeni,tekst,correctAnswer,answer1,answer2,answer3,answer4);
            _questions.push_back(q1);
        }
        else{

            Rebus* rebus = new Rebus(poeni, tekst, correctAnswer);
            _rebus.push_back(rebus);
        }
    }
}

Room::Room(const Room &room)
    :_rbr_sobe(room.rbr_sobe())
{}

Room& Room::operator =(const Room& room){
    if(this!=&room){
        _rbr_sobe=room.rbr_sobe();
    }
    return *this;
}

Room::~Room(){
    for(auto i=_questions.begin();i!=_questions.end();i++)
        delete *i;
}

int Room::rbr_sobe() const{
    return _rbr_sobe;
}

vector<QuestionABCD*> Room::questions() const{
   return _questions;
}

vector<Rebus*> Room::rebus() const{

    return _rebus;
}


ostream& operator <<(ostream& ostr,const Room& room){
    ostr<<"Redni broj sobe je "<<room.rbr_sobe()<<endl;
    return ostr;
}



