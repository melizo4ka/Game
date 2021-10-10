#ifndef GAME_PLANTINGSTATE_H
#define GAME_PLANTINGSTATE_H

#include "PlayerState.h"
#include "StandingState.h"


class PlantingState
        : public PlayerState{
public:

    PlayerState* handleInput(Player& pl, vector <int> map, int mapWidth, int mapHeight, int px, Keyboard::Key key);
};


#endif //GAME_PLANTINGSTATE_H
