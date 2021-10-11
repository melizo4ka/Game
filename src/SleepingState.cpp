#include "SleepingState.h"

PlayerState* SleepingState::handleInput(Player& pl, vector <int> map, int mapWidth, int mapHeight, int px, Keyboard::Key key) {
    pl.day++;
    pl.energy = pl.maxEnergy;
    pl.sprite.setPosition(pl.startingPosX, pl.startingPosY);
    return new StandingState();
}

