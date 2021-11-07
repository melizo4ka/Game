#ifndef GAME_SLEEPINGSTATE_H
#define GAME_SLEEPINGSTATE_H

#include "PlayerState.h"
#include "WalkingState.h"


class SleepingState
        : public PlayerState{
public:

    PlayerState* handleInput(Player& pl, int map[], int mapWidth, int mapHeight, int px, Keyboard::Key key);


};

#endif //GAME_SLEEPINGSTATE_H
