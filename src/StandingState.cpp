#include "StandingState.h"

PlayerState* StandingState::handleInput(Player &pl) {
    if (Keyboard::isKeyPressed(Keyboard::A)||Keyboard::isKeyPressed(Keyboard::Left)||
        Keyboard::isKeyPressed(Keyboard::W)||Keyboard::isKeyPressed(Keyboard::Up)||
        Keyboard::isKeyPressed(Keyboard::D)||Keyboard::isKeyPressed(Keyboard::Right)||
        Keyboard::isKeyPressed(Keyboard::S)||Keyboard::isKeyPressed(Keyboard::Down))
    {
            //left
            if(Keyboard::isKeyPressed(Keyboard::A)||Keyboard::isKeyPressed(Keyboard::Left)){
                pl.sprite.move(-this->movementSpeed, 0.f);
            }
            //right
            else if(Keyboard::isKeyPressed(Keyboard::D)||Keyboard::isKeyPressed(Keyboard::Right)){
                pl.sprite.move(this->movementSpeed, 0.f);
            }
            //up
            if(Keyboard::isKeyPressed(Keyboard::W)||Keyboard::isKeyPressed(Keyboard::Up)){
                pl.sprite.move(0.f, -this->movementSpeed);
            }
            //down
            else if(Keyboard::isKeyPressed(Keyboard::S)||Keyboard::isKeyPressed(Keyboard::Down)) {
                pl.sprite.move(0.f, this->movementSpeed);
            }
        return new WalkingState();
    }
    //add Standing-->Shopping
    //add Standing-->Fishing
}

void StandingState::enter(Player& pl)
{
    pl.setGraphics(pl.standingTexture);
}
