#include "WalkingState.h"

std::shared_ptr<PlayerState> WalkingState::handleInput(Player& pl, int map[], int mapWidth, int mapHeight, int px, Keyboard::Key key) {
    FloatRect playerBounds = pl.sprite.getGlobalBounds();
    //left
    if(key == Keyboard::A){
        bool move1 = checkCollision(playerBounds.left - this->movementSpeed, playerBounds.top + playerBounds.height, map, mapWidth, px);//bottom check
        if(move1)
            pl.sprite.move(-this->movementSpeed, 0.f);
    }
    //right
    else if(key == Keyboard::D){
        bool move1 = checkCollision(playerBounds.left + playerBounds.width + this->movementSpeed, playerBounds.top + playerBounds.height, map, mapWidth, px);//bottom check
        if(move1)
            pl.sprite.move(this->movementSpeed, 0.f);
    }
    //up
    if(key == Keyboard::W){
        bool move1 = checkCollision(playerBounds.left, playerBounds.top + playerBounds.height - this->movementSpeed, map, mapWidth, px);//left top check
        bool move2 = checkCollision(playerBounds.left + playerBounds.width, playerBounds.top + playerBounds.height - this->movementSpeed, map, mapWidth, px);//right top check
        if(move1 && move2)
            pl.sprite.move(0.f, -this->movementSpeed);
    }
    //down
    else if(key== Keyboard::S) {
        bool move1 = checkCollision(playerBounds.left, playerBounds.top + playerBounds.height + this->movementSpeed, map, mapWidth, px);//left bottom check
        bool move2 = checkCollision(playerBounds.left + playerBounds.width,  playerBounds.top + playerBounds.height + this->movementSpeed, map, mapWidth, px);//right bottom check
        if(move1 && move2)
            pl.sprite.move(0.f, this->movementSpeed);
    }
    return std::shared_ptr<PlayerState>(new StandingState());
}


bool WalkingState::checkCollision(float x, float y, const int map[], int mapWidth, int px) {
    int mapX = x / px;
    int mapY = y / px;
    int newSquare = map[mapX + mapY * mapWidth];
    if(newSquare == 1 || newSquare == 3 || newSquare == 4){
        return false;
    }
    else
        return true;
}