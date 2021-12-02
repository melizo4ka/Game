#ifndef GAME_STANDINGSTATE_H
#define GAME_STANDINGSTATE_H

#include "PlayerState.h"
#include "WalkingState.h"
#include "SleepingState.h"


class StandingState
        : public PlayerState{
public:
    ~StandingState();
    std::shared_ptr<PlayerState> handleInput(Player& pl, int map[], int mapWidth, int mapHeight, int px, Keyboard::Key key) override;

    static int checkEnteredSquare(float x, float y,const int map[], int mapWidth, int px);

};


#endif //GAME_STANDINGSTATE_H
