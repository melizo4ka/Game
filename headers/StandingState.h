#ifndef GAME_STANDINGSTATE_H
#define GAME_STANDINGSTATE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "PlayerState.h"
#include "WalkingState.h"
using namespace sf;


class StandingState
        : public PlayerState{
public:
    float movementSpeed = 5.f;

    PlayerState* handleInput(Player& pl);
    void enter(Player& pl);
};


#endif //GAME_STANDINGSTATE_H
