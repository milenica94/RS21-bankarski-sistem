#include "player.h"

#include <iostream>
#include <QString>

using namespace std;

Player::Player(){}

Player::Player(QString name, int lives, int level, int roomCount, int totalCount)
    : _name(name), _lives(lives), _level(level), _roomCount(roomCount), _totalCount(totalCount)
{}

Player::Player(const Player& p)
    : _name(p.name()), _lives(p.lives()), _level(p.level()), _roomCount(p.roomCount()), _totalCount(p.totalCount())
{}

Player& Player::operator =(const Player& p){

     if(this != &p){

        _name = p.name();
        _lives = p.lives();
        _level = p.level();
        _roomCount = p.roomCount();
        _totalCount = p.totalCount();
     }
     return *this;
}

Player::~Player(){}


QString Player::name() const{

    return _name;
}

int Player::lives() const{

    return _lives;
}

void Player::setLives(int lives){

    _lives = lives;
}

int Player::level() const{

    return _level;
}

void Player::setLevel(int level){

    _level = level;
}

int Player::roomCount() const{

    return _roomCount;
}

int Player::totalCount() const{

    return _totalCount;
}
void Player::setRoomCount(int points){

    _roomCount = points;
}

void Player::setTotalCount(int points){

    _totalCount = points;
}

void Player::choosePath(char& path) const{

    cout << "Izaberite kojom putanjom zelite ici. " << endl;
    cout << "Unesite L za levo ili D za desno: " << endl;

    cin >> path;

    while(path != 'D' && path != 'L'){
        cout << "Morate uneti L ili D! " << endl;
        cin >> path;
    }
}


