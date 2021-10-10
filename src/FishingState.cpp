#include "FishingState.h"

PlayerState* FishingState::handleInput(Player& pl, vector <int> map, int mapWidth, int mapHeight, int px, Keyboard::Key key) {
    if(pl.energy > 0){
        Vector2f position = pl.sprite.getPosition();
        Pond pond(position.x, position.y);
        printf("You clicked on pond \n");
        int p = pond.fishRandom();
        if (p > 1 && p <= 5){
            //put Herring into inventory
            shared_ptr<Fish> herring(new Fish(100));
            pl.inventory[1][1] = pl.inventory[1][1]+1;
        }
        else if (0 <= p && p <= 1){
            //put Salmon into inventory
            shared_ptr<Fish> salmon(new Fish(500));
            pl.inventory[0][1] = pl.inventory[0][1]+1;
        }
        return new StandingState();
    }
    else
        return new StandingState();
}
