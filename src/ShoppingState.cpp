#include "ShoppingState.h"

PlayerState* ShoppingState::handleInput(Player& pl, vector <int> map, int mapWidth, int mapHeight, int px, Keyboard::Key key) {

    return new StandingState();
}

