#include "WalkingState.h"

PlayerState* WalkingState::handleInput(Player& pl) {
    if (!Keyboard::isKeyPressed(Keyboard::A)||!Keyboard::isKeyPressed(Keyboard::Left)||
        !Keyboard::isKeyPressed(Keyboard::W)||!Keyboard::isKeyPressed(Keyboard::Up)||
        !Keyboard::isKeyPressed(Keyboard::D)||!Keyboard::isKeyPressed(Keyboard::Right)||
        !Keyboard::isKeyPressed(Keyboard::S)||!Keyboard::isKeyPressed(Keyboard::Down))
    {
        return new StandingState();
    }

}

void WalkingState::enter(Player& pl)
{
    pl.setGraphics(pl.walkingTexture);

}
