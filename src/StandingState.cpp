#include "StandingState.h"

PlayerState* StandingState::handleInput(Player &pl, vector <int> map, int mapWidth, int mapHeight, int px) {
    if (Keyboard::isKeyPressed(Keyboard::A)||Keyboard::isKeyPressed(Keyboard::Left)||
        Keyboard::isKeyPressed(Keyboard::W)||Keyboard::isKeyPressed(Keyboard::Up)||
        Keyboard::isKeyPressed(Keyboard::D)||Keyboard::isKeyPressed(Keyboard::Right)||
        Keyboard::isKeyPressed(Keyboard::S)||Keyboard::isKeyPressed(Keyboard::Down))
    {
        FloatRect playerBounds = pl.sprite.getGlobalBounds();
            //left
            if(Keyboard::isKeyPressed(Keyboard::A)||Keyboard::isKeyPressed(Keyboard::Left)){
                bool move1 = checkCollision(playerBounds.left - this->movementSpeed, playerBounds.top + playerBounds.height, map, mapWidth, mapHeight, px);//bottom check
                if(move1)
                    pl.sprite.move(-this->movementSpeed, 0.f);
            }
            //right
            else if(Keyboard::isKeyPressed(Keyboard::D)||Keyboard::isKeyPressed(Keyboard::Right)){
                bool move1 = checkCollision(playerBounds.left + playerBounds.width + this->movementSpeed, playerBounds.top + playerBounds.height, map, mapWidth, mapHeight, px);//bottom check
                if(move1)
                    pl.sprite.move(this->movementSpeed, 0.f);
            }
            //up
            if(Keyboard::isKeyPressed(Keyboard::W)||Keyboard::isKeyPressed(Keyboard::Up)){
                bool move1 = checkCollision(playerBounds.left, playerBounds.top + playerBounds.height - this->movementSpeed, map, mapWidth, mapHeight, px);//left top check
                bool move2 = checkCollision(playerBounds.left + playerBounds.width, playerBounds.top + playerBounds.height - this->movementSpeed, map, mapWidth, mapHeight, px);//right top check
                if(move1 && move2)
                    pl.sprite.move(0.f, -this->movementSpeed);
            }
            //down
            else if(Keyboard::isKeyPressed(Keyboard::S)||Keyboard::isKeyPressed(Keyboard::Down)) {
                bool move1 = checkCollision(playerBounds.left, playerBounds.top + playerBounds.height + this->movementSpeed, map, mapWidth, mapHeight, px);//left bottom check
                bool move2 = checkCollision(playerBounds.left + playerBounds.width,  playerBounds.top + playerBounds.height + this->movementSpeed, map, mapWidth, mapHeight, px);//right bottom check
                if(move1 && move2)
                    pl.sprite.move(0.f, this->movementSpeed);
            }
        return new WalkingState();
    }
    //add Standing-->Shopping
    //add Standing-->Fishing
}

void StandingState::enter(Player& pl) {
    pl.setGraphics(pl.standingTexture);
}

bool StandingState::checkCollision(float x, float y, vector <int> map, int mapWidth, int mapHeight, int px) {
    int mapX = x / px;
    int mapY = y / px;
    int newSquare = map[mapX * mapHeight + mapY];
    if(newSquare == 1 || newSquare == 3 || newSquare == 4){
        return false;
    }
    else
        return true;
}
