#include "Engine.h"
#include "TileMap.h"
int main() {


    //initialize game
    Engine engine;
    bool mapInitialized = false;

    //game loop
    while(engine.running()){
        const int level[] =
                {
                        1, 1, 1, 1, 1, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0,
                        0, 0, 0, 0, 0, 4, 3, 3, 3, 0, 0, 3, 6, 3, 0, 0,
                        4, 0, 0, 0, 0, 0, 3, 5, 3, 0, 0, 0, 0, 0, 4, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0,
                        2, 2, 2, 2, 2, 2, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4,
                        2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 4, 0, 4, 0, 0, 0,
                        2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                };

        TileMap map;
        if (!map.load("assets/tileset.png", sf::Vector2u(32, 32), level, 16, 8))
            return -1;
        if(!mapInitialized){
        engine.getMap(level, 16, 8, 64);
        mapInitialized = true;
        }
        engine.update();
        engine.render(map);
    }

    return 0;
}