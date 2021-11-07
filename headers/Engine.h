#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "Player.h"
#include "Shop.h"
#include "Pond.h"
#include "House.h"
#include "Object.h"
#include "Fish.h"
#include "TileMap.h"
#include "Menu.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <ctime>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

using namespace sf;
using namespace std;

class Engine {
private:
    unsigned WindowWidth;
    unsigned WindowHeight;

    VideoMode videoMode;
    Event sfmlEvent;

    int mapWidth;
    int mapHeight;
    int pixels;

    int map[128];
    int *level;

    Player player;
    bool iPressed = false;

    void initVariables(unsigned WindowWidth, unsigned WindowHeight,unsigned width, unsigned height, unsigned pixels);
    void initWindow();

public:
    Engine();
    ~Engine();

    RenderWindow* window;
    TileMap tilemap;

    int* readMapFile(int level[]);

    bool running() const;
    void pollEvents();
    void update();
    void render(TileMap);
    void showText();
    void showInventory(int inventory[6][2]);

};


#endif //GAME_ENGINE_H
