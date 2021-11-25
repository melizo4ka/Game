#include <ShoppingState.h>
#include <FishingState.h>
#include <PlantingState.h>
#include <HarvestingState.h>
#include "StandingState.h"

std::shared_ptr<PlayerState> StandingState::handleInput(Player &pl, int map[], int mapWidth, int mapHeight, int px, Keyboard::Key key) {
    FloatRect playerBounds = pl.sprite.getGlobalBounds();
    int squareType = checkEnteredSquare(playerBounds.left, playerBounds.top+playerBounds.height, map, mapWidth, px);

    if(squareType == 5)
        return std::shared_ptr<PlayerState>(new ShoppingState());

    else if(squareType == 6)
        return std::shared_ptr<PlayerState>(new SleepingState());

    else if(key == Keyboard::W || key == Keyboard::A || key == Keyboard::S || key == Keyboard::D)
        return std::shared_ptr<PlayerState>(new WalkingState());

    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && pl.pondClicked){
        pl.pondClicked = false;
        return std::shared_ptr<PlayerState>(new FishingState());
    }

    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && pl.blankClicked && squareType == 2){
        pl.blankClicked = false;
        return std::shared_ptr<PlayerState>(new PlantingState());
    }

    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && pl.harvestableClicked && (squareType == 9||squareType == 13))
        return std::shared_ptr<PlayerState>(new HarvestingState());

    else
        return std::shared_ptr<PlayerState>(new StandingState());
}

int StandingState::checkEnteredSquare(float x, float y, const int map[], int mapWidth, int px) {
    int mapX = x / px;
    int mapY = y / px;
    int newSquare = map[mapX + mapY * mapWidth];
    return newSquare;
}