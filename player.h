#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <QString>

using namespace std;

class Player {

public:
    Player();
    Player(QString name, int lives = 3, int level = 1, int roomCount = 0, int totalCount = 0);
    ~Player();
    Player(const Player& p);
    Player& operator=(const Player& p);

    QString name() const;
    int lives() const;
    int level() const;
    int roomCount() const;
    int totalCount() const;

    void setLives(int lives);
    void setLevel(int level);
    void setRoomCount(int points);
    void setTotalCount(int points);

    void choosePath(char& path) const;

private:
    QString _name;
    int _lives;
    int _level;
    int _roomCount;
    int _totalCount;

};

ostream & operator <<(ostream& out, const Player& player);

#endif // PLAYER_H
