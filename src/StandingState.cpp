#include <ShoppingState.h>
#include <FishingState.h>
#include "StandingState.h"

PlayerState* StandingState::handleInput(Player &pl, vector <int> map, int mapWidth, int mapHeight, int px, Keyboard::Key key) {
    FloatRect playerBounds = pl.sprite.getGlobalBounds();
    int squareType = checkEnteredSquare(playerBounds.left, playerBounds.top+playerBounds.height, map, mapWidth, mapHeight, px);
    if(squareType == 5){
        return new ShoppingState();
    }
    else if(squareType == 6){
        return new SleepingState();
    }
    else if(key == Keyboard::W || key == Keyboard::A || key == Keyboard::S || key == Keyboard::D )
        return new WalkingState();
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        return new FishingState();
    }
    else
        return new StandingState();
}

void StandingState::enter(Player& pl) {

}

int StandingState::checkEnteredSquare(float x, float y, vector <int> map, int mapWidth, int mapHeight, int px) {
    int mapX = x / px;
    int mapY = y / px;
    int newSquare = map[mapX * mapHeight + mapY];
    return newSquare;
}