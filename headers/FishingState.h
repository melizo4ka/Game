#ifndef GAME_FISHINGSTATE_H
#define GAME_FISHINGSTATE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "PlayerState.h"
#include "WalkingState.h"
using namespace sf;


class FishingState
        : public PlayerState{
public:

    PlayerState* handleInput(Player& pl, vector <int> map, int mapWidth, int mapHeight, int px);
    void enter(Player& pl);

};

#endif //GAME_FISHINGSTATE_H
