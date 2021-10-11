#include "HarvestingState.h"

PlayerState* HarvestingState::handleInput(Player& pl, vector <int> map, int mapWidth, int mapHeight, int px, Keyboard::Key key) {
    pl.consumeEnergy();
    return new StandingState();
}
