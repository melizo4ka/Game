#include "PlantingState.h"

std::shared_ptr<PlayerState> PlantingState::handleInput(Player& pl, int map[], int mapWidth, int mapHeight, int px, Keyboard::Key key) {
    if(pl.energy > 0){
        FloatRect playerBounds = pl.sprite.getGlobalBounds();
        int tileCoord = getTile(playerBounds.left, playerBounds.top+playerBounds.height, map, mapWidth, px);
        if(map[tileCoord] == 2){
            if(pl.inventory[4][1] > 0){ // check for apple seed
                pl.inventory[4][1] = pl.inventory[4][1] - 1;
                //change square
                map[tileCoord] = 10;
                pl.consumeEnergy();
            }
            else if(pl.inventory[2][1] > 0){ //check for potato seed
                pl.inventory[2][1] = pl.inventory[2][1] - 1;
                //change square
                map[tileCoord] = 7;
                pl.consumeEnergy();
            }
        }
    }
    return std::shared_ptr<PlayerState>(new StandingState());
}

int PlantingState::getTile(float x, float y, int map[], int mapWidth, int px) {
    int mapX = x / px;
    int mapY = y / px;
    int newTile = mapX + mapY * mapWidth;
    return newTile;
}

PlantingState::~PlantingState() {

}
