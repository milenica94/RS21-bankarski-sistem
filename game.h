#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <map>

#include "room.h"

using namespace std;

class Game
{
public:
    Game();
    ~Game();

    void setPutanja();
    vector<int> getPutanja();
    vector<Room> rooms();

private:
   Game (const Game &g);
   Game operator = (Game &g);
   vector<int> _putanja;
   vector<Room> _rooms;
};

#endif // GAME_H
