#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "Player.h"
#include "Shop.h"
#include "Pond.h"
#include "House.h"
#include "Inventory.h"
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
using namespace sf;
using namespace std;

class Engine {
private:
    unsigned WindowWidth;
    unsigned WindowHeight;

    VideoMode videoMode;
    bool endEngine;
    Event sfmlEvent;

    vector <int> map ;
    int mapWidth;
    int mapHeight;
    int pixels;

    Player player;
    Inventory inventory;

    void initVariables(unsigned WindowWidth, unsigned WindowHeight);
    void initWindow();

public:
    //constructor and destructor
    Engine();
    ~Engine();

    RenderWindow* window;

    int* readMapFile(int level[]);
    void getMap(const int gameMap[], unsigned int width, unsigned int height, int pixels);

    //functions
    const bool running() const;
    void pollEvents();

    void update();
    void render(TileMap);
    void showText();

};


#endif //GAME_ENGINE_H
