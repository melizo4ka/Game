#include "SleepingState.h"

std::shared_ptr<PlayerState> SleepingState::handleInput(Player& pl, int map[], int mapWidth, int mapHeight, int px, Keyboard::Key key) {
    pl.day++;
    for (int i= 0; i < mapWidth*mapHeight; i++){
        //potato
        if (map[i] == 7)
            map[i] = 8;
        else if (map[i] == 8)
            map[i] = 9;
        //apple
        else if (map[i] == 10)
            map[i] = 11;
        else if (map[i] == 11)
            map[i] = 12;
        else if (map[i] == 12)
            map[i] = 13;
        else if (map[i] == 13)
            map[i] = 2;
    }
    pl.energy = pl.maxEnergy;
    pl.sprite.setPosition(pl.startingPosX, pl.startingPosY);
    return std::shared_ptr<PlayerState>(new StandingState());
}

SleepingState::~SleepingState() {

}

