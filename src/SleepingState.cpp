#include "SleepingState.h"

PlayerState* SleepingState::handleInput(Player& pl, vector <int> map, int mapWidth, int mapHeight, int px, Keyboard::Key key) {
    pl.day++;
    pl.energy = pl.maxEnergy;
    FloatRect playerBounds = pl.sprite.getGlobalBounds();
    pl.sprite.setPosition(pl.startingPosX, pl.startingPosY);
    return new StandingState();
}

