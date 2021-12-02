#include "FishingState.h"

std::shared_ptr<PlayerState> FishingState::handleInput(Player& pl, int map[], int mapWidth, int mapHeight, int px, Keyboard::Key key) {
    if(pl.energy > 0){
        Vector2f position = pl.sprite.getPosition();
        Pond pond(position.x, position.y);
        int p = pond.fishRandom();
        if (p > 1 && p <= 5){
            //put Herring into inventory
            Fish* herring(new Fish(100));
            pl.inventory[1][1] = pl.inventory[1][1]+1;
        }
        else if (0 <= p && p <= 1){
            //put Salmon into inventory
            Fish* salmon(new Fish(500));
            pl.inventory[0][1] = pl.inventory[0][1]+1;
        }
        pl.consumeEnergy();
    }
    return std::shared_ptr<PlayerState>(new StandingState());
}

FishingState::~FishingState() {

}
