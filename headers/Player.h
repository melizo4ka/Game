#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <memory>
#include "PlayerState.h"
#include "Plant.h"
#include "Fish.h"

using namespace sf;
using namespace std;

class Player {
private:
    void initVariables();
    void initGraphics(int x, int y);
    void setName();

public:
    string namePlayer;
    int money;
    int energy;
    int day;
    int startingPosX = 128;
    int startingPosY = 128;
    int maxEnergy = 30;

    Plant potato = Plant(10, 50);
    Plant apple = Plant(80, 800);
    Fish salmon = Fish(500);
    Fish herring = Fish(200);

    Sprite sprite;
    Texture standingTexture;
    std::shared_ptr<PlayerState> state_;
    int inventory[6][2]; //items (salmon, herring, p seed, p plant, s seed, s plant) and quantity

    bool pondClicked = false;
    bool blankClicked = false;
    bool harvestableClicked = false;

    Player(int x = 128, int y = 128);
    virtual ~Player();
    void initInventory();

    void updateWindowBoundsCollision(std::shared_ptr<RenderWindow> target);
    void update(std::shared_ptr<RenderWindow> target, int map[], int mapWidth, int mapHeight, int px);
    void render(std::shared_ptr<RenderWindow> window);

    virtual void handleInput(int map[], int mapWidth, int mapHeight, int px);
    static Keyboard::Key getInput();
    void getClick(const int map[], int mapWidth, int mapHeight, int px, std::shared_ptr<RenderWindow> window);

    void consumeEnergy();
};


#endif //GAME_PLAYER_H
