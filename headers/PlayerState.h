#ifndef GAME_PLAYERSTATE_H
#define GAME_PLAYERSTATE_H

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace std;
using namespace sf;

class Player;

class PlayerState {
public:
    virtual ~PlayerState();
    virtual PlayerState* handleInput(Player& pl, int map[], int mapWidth, int mapHeight, int px, Keyboard::Key key);
};


#endif //GAME_PLAYERSTATE_H
