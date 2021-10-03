#include "ShoppingState.h"

PlayerState* ShoppingState::handleInput(Player& pl, vector <int> map, int mapWidth, int mapHeight, int px) {

    return new StandingState();
}

void ShoppingState::enter(Player& pl)
{
    //pl.setGraphics(pl.walkingTexture);

}
