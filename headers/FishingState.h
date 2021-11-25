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
#include "Pond.h"
#include "Fish.h"
#include <memory>

using namespace sf;

class FishingState
        : public PlayerState{
public:

    std::shared_ptr<PlayerState> handleInput(Player& pl, int map[], int mapWidth, int mapHeight, int px, Keyboard::Key key) override;

};

#endif //GAME_FISHINGSTATE_H
