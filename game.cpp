#include "game.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <map>

using namespace std;

Game::Game() {
        int i;
        // Pravi se putanja
        for (i = 0 ; i < 5 ; i++) {
          setPutanja();
        }
    }

Game::~Game()
{

    for(auto i=_rooms.begin();i!=_rooms.end();i++)
        delete &i;
}

void Game::setPutanja() {
       random_device rd;
       uniform_int_distribution<int> dist(0,1);
        int i;
        for (i = 0 ; i < 7 ; i++) {
            int x = dist(rd);
            _putanja.push_back(x);
        }
    }

vector<int> Game::getPutanja(){

    return _putanja;
}

vector<Room> Game::rooms(){

    return _rooms;
}
