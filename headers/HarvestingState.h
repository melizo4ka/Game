#ifndef GAME_HARVESTINGSTATE_H
#define GAME_HARVESTINGSTATE_H

#include "PlayerState.h"
#include "StandingState.h"


class HarvestingState
        : public PlayerState{
public:

    PlayerState* handleInput(Player& pl, int map[], int mapWidth, int mapHeight, int px, Keyboard::Key key);

    int getTile(float x, float y, int map[], int mapWidth, int px);

};


#endif //GAME_HARVESTINGSTATE_H
