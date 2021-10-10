#include "PlantingState.h"

PlayerState* PlantingState::handleInput(Player& pl, vector <int> map, int mapWidth, int mapHeight, int px, Keyboard::Key key) {
        return new StandingState();
}
