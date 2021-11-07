#include "HarvestingState.h"

PlayerState* HarvestingState::handleInput(Player& pl, int map[], int mapWidth, int mapHeight, int px, Keyboard::Key key) {
    if(pl.energy > 0){
        FloatRect playerBounds = pl.sprite.getGlobalBounds();
        int tileCoord = getTile(playerBounds.left, playerBounds.top+playerBounds.height, map, mapWidth, px);
        //harvest potato
        if(map[tileCoord] == 9){
            pl.inventory[3][1] = pl.inventory[3][1] + 1;
            map[tileCoord] = 2;
        }
        //harvest apple
        if(map[tileCoord] == 13){
            pl.inventory[5][1] = pl.inventory[5][1] + 1;
            map[tileCoord] = 12;
        }

        pl.consumeEnergy();
    }
    return new StandingState();
}

int HarvestingState::getTile(float x, float y, int map[], int mapWidth, int px) {
    int mapX = x / px;
    int mapY = y / px;
    int newTile = mapX + mapY * mapWidth;
    return newTile;
}