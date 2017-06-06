#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <QString>
#include <vector>
#include <stdio.h>
#include <map>
#include "question.h"
#include "questionabcd.h"
#include "rebus.h"

using namespace std;

class Room
{
public:
    Room(map<int,string> kategorija,int r_br_sobe=1);
    Room(const Room& room);
    Room & operator =(const Room& room);
    ~Room();

    int rbr_sobe() const;
    vector<QuestionABCD*> questions() const;
    vector<Rebus*> rebus() const;

 private:
    int _rbr_sobe;
    vector<QuestionABCD*> _questions;
    vector<Rebus*> _rebus;
};

ostream &operator <<(ostream& ostr, const Room& room);
#endif // ROOM_H;
