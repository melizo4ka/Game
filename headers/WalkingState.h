#ifndef GAME_WALKINGSTATE_H
#define GAME_WALKINGSTATE_H

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
    ~WalkingState();
    std::shared_ptr<PlayerState> handleInput(Player& pl, int map[], int mapWidth, int mapHeight, int px, Keyboard::Key key) override;

    static bool checkCollision(float x, float y, const int map[], int mapWidth, int px);

};


#endif //GAME_WALKINGSTATE_H
