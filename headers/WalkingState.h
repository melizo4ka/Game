#ifndef GAME_WALKINGSTATE_H
#define GAME_WALKINGSTATE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Player.h"
#include "PlayerState.h"
#include "StandingState.h"

using namespace sf;

class WalkingState
        : public PlayerState{
public:
    float movementSpeed = 5.f;
    PlayerState* handleInput(Player& pl, vector <int> map, int mapWidth, int mapHeight, int px, Keyboard::Key key);
    virtual void enter(Player& pl);

    bool checkCollision(float x, float y, vector <int> map, int mapWidth, int mapHeight, int px);

};


#endif //GAME_WALKINGSTATE_H
