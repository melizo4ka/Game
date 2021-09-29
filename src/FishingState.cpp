#include "FishingState.h"

PlayerState* FishingState::handleInput(Player& pl, vector <int> map, int mapWidth, int mapHeight, int px) {
    printf("You clicked on pond \n");
    /*int p = pond.fishRandom();
    if (1 < p & p < 5){
        //put Herring into inventory
        shared_ptr<Fish> herring(new Fish(0.9, 100));
        inventory.putItem(*herring);
    }
    else if (p == 1){
        //put Salmon into inventory
        shared_ptr<Fish> salmon(new Fish(0.1, 500));
        inventory.putItem(*salmon);
    }*/

    /*if()
    {
        return new StandingState();
    }*/
}

void FishingState::enter(Player& pl)
{
    //pl.setGraphics(pl.walkingTexture);

}