#include "Player.h"
#include <iostream>
#include "PlayerState.h"
#include "StandingState.h"
#include <windows.h>
#include <memory>


Player::Player(int x, int y) {
    this->initGraphics(x, y);
    this->initVariables();
    this->state_ = std::shared_ptr<PlayerState>(new StandingState());
    this->initInventory();
}

Player::~Player(){

}

void Player::initVariables() {
    this->setName();
    this->money = 1000;
    this->energy = maxEnergy;
    this->day = 1;
}

void Player::initGraphics(int x, int y) {
    try{
        standingTexture.loadFromFile("../assets/standing.png");
    }
    catch (...){
        std::cerr << "Couldn't find Standing Texture" << std::endl;
    }

    sprite.setTexture(standingTexture);
    sprite.setTextureRect(sf::IntRect(0, 0, 42, 57));
    sprite.setPosition(x, y);
}

void Player::initInventory() {
    for (int i = 0; i < 6; i++){
        inventory[i][0] = i;
        inventory[i][1] = 0;
    }
}

void Player::setName(){
    cout << "Insert your Name here: \n";
    cin >> namePlayer;
}

void Player::updateWindowBoundsCollision(std::shared_ptr<RenderWindow> target) {
    FloatRect playerBounds = this->sprite.getGlobalBounds();
    //left collision
    if(playerBounds.left < 0.f)
        this->sprite.setPosition(0.f, playerBounds.top);
    //right collision
    else if(playerBounds.left + playerBounds.width > target->getSize().x)
        this->sprite.setPosition(target->getSize().x - playerBounds.width, playerBounds.top);
    //top collision
    if(playerBounds.top < 0.f)
        this->sprite.setPosition(playerBounds.left, 0.f);
    //bottom collision
    else if(playerBounds.top + playerBounds.height > target->getSize().y)
        this->sprite.setPosition(playerBounds.left, target->getSize().y - playerBounds.height);
}

void Player::update(std::shared_ptr<RenderWindow> target, int map[], int mapWidth, int mapHeight, int px) {
    this->handleInput(map, mapWidth, mapHeight, px);

    //window collision detection
    this->updateWindowBoundsCollision(target);

    this->getClick(map, mapWidth, mapHeight, px, target);
}

void Player::render(std::shared_ptr<RenderWindow> window) {
    window->draw(sprite);
}

void Player::handleInput(int map[], int mapWidth, int mapHeight, int px) {
    Keyboard::Key key = this->getInput();
    std::shared_ptr<PlayerState> state = state_->handleInput(*this, map, mapWidth, mapHeight, px, key);

    if (state != nullptr)
        state_ = state;
}

Keyboard::Key Player::getInput() {
    if (sf::Keyboard::isKeyPressed(Keyboard::A) || sf::Keyboard::isKeyPressed(Keyboard::Left)){
            return Keyboard::Key::A;
        }
    else if(sf::Keyboard::isKeyPressed(Keyboard::W) || sf::Keyboard::isKeyPressed(Keyboard::Up)){
            return Keyboard::Key::W;
        }
    else if(sf::Keyboard::isKeyPressed(Keyboard::D) || sf::Keyboard::isKeyPressed(Keyboard::Right)){
            return Keyboard::Key::D;
        }
    else if(sf::Keyboard::isKeyPressed(Keyboard::S) || sf::Keyboard::isKeyPressed(Keyboard::Down)){
            return Keyboard::Key::S;
        }
    else {
        return Keyboard::Key::Unknown;
    }
}

void Player::getClick(const int map[], int mapWidth, int mapHeight, int px, std::shared_ptr<RenderWindow> window) {
    if(energy > 0){
        //clicking on objects
        if(Mouse::isButtonPressed(Mouse::Left)){
            Vector2i position = sf::Mouse::getPosition(*window);
            int squareClicked = map[(position.x / px) + (position.y / px) * mapWidth];
            //pond
            if (squareClicked == 1){
                pondClicked = true;
            }
            //blank ground
            else if (squareClicked == 2){
                blankClicked = true;
            }
            //harvest
            else if (squareClicked == 9 || squareClicked == 13){
                harvestableClicked = true;
            }
        }
    }
}

void Player::consumeEnergy(){
    energy--;
}
