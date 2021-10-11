#include "PlantingState.h"

PlayerState* PlantingState::handleInput(Player& pl, vector <int> map, int mapWidth, int mapHeight, int px, Keyboard::Key key) {
    FloatRect playerBounds = pl.sprite.getGlobalBounds();
    printf("planting state");
    if(pl.energy > 0){
        if(pl.inventory[4][1] > 0){ // check for apple seed
            pl.inventory[4][1] = pl.inventory[4][1] - 1;
            //change square
        }
        else if(pl.inventory[2][1] > 0){ //check for potato seed
            pl.inventory[2][1] = pl.inventory[2][1] - 1;
            //change square ??
            int mapSquare = getMapSquare(playerBounds.left, playerBounds.top+playerBounds.height, map, mapWidth, mapHeight, px);
            map[mapSquare] = 8;
        }
        pl.consumeEnergy();
    }
    return new StandingState();
}

int PlantingState::getMapSquare(float x, float y, vector <int> map, int mapWidth, int mapHeight, int px) {
    int mapX = x / px;
    int mapY = y / px;
    int squareInMap = mapX * mapHeight + mapY;
    return squareInMap;
}