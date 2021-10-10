#ifndef GAME_HARVESTINGSTATE_H
#define GAME_HARVESTINGSTATE_H

#include "PlayerState.h"
#include "StandingState.h"


class HarvestingState
        : public PlayerState{
public:

    PlayerState* handleInput(Player& pl, vector <int> map, int mapWidth, int mapHeight, int px, Keyboard::Key key);

};


#endif //GAME_HARVESTINGSTATE_H
