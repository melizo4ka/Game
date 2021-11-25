#ifndef GAME_HARVESTINGSTATE_H
#define GAME_HARVESTINGSTATE_H

#include "PlayerState.h"
#include "StandingState.h"


class HarvestingState
        : public PlayerState{
public:

    std::shared_ptr<PlayerState> handleInput(Player& pl, int map[], int mapWidth, int mapHeight, int px, Keyboard::Key key) override;

    int getTile(float x, float y, int map[], int mapWidth, int px);

};


#endif //GAME_HARVESTINGSTATE_H
