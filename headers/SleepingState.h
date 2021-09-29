#ifndef GAME_SLEEPINGSTATE_H
#define GAME_SLEEPINGSTATE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "PlayerState.h"
#include "WalkingState.h"
using namespace sf;


class SleepingState
        : public PlayerState{
public:

    PlayerState* handleInput(Player& pl, vector <int> map, int mapWidth, int mapHeight, int px);
    void enter(Player& pl);


};

#endif //GAME_SLEEPINGSTATE_H
