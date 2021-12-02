#ifndef GAME_PLANTINGSTATE_H
#define GAME_PLANTINGSTATE_H

#include "PlayerState.h"
#include "StandingState.h"


class PlantingState
        : public PlayerState{
public:
    ~PlantingState();
    std::shared_ptr<PlayerState> handleInput(Player& pl, int map[], int mapWidth, int mapHeight, int px, Keyboard::Key key) override;

    static int getTile(float x, float y, int map[], int mapWidth, int px);

};


#endif //GAME_PLANTINGSTATE_H
