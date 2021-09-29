#ifndef GAME_STANDINGSTATE_H
#define GAME_STANDINGSTATE_H

#include "PlayerState.h"
#include "WalkingState.h"
#include "SleepingState.h"


class StandingState
        : public PlayerState{
public:
    float movementSpeed = 4.f;

    PlayerState* handleInput(Player& pl, vector <int> map, int mapWidth, int mapHeight, int px, Keyboard::Key key);
    void enter(Player& pl);

    int checkEnteredSquare(float x, float y, vector <int> map, int mapWidth, int mapHeight, int px);

};


#endif //GAME_STANDINGSTATE_H
