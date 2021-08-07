#include "Player.h"
#include <iostream>
#include "PlayerState.h"
#include "StandingState.h"

Player::Player(int x, int y) {
    this->initGraphics(x, y);
    this->initVariables();
    this->state_ = new StandingState();
}

Player::~Player(){

}

void Player::initVariables() {
    this->setName();
    this->money = 1000;
    this->energy = 50;
}

void Player::initGraphics(int x, int y) {
    standingTexture.loadFromFile("assets/standing.png");
    walkingTexture.loadFromFile("assets/walking.png");

    sprite.setTexture(standingTexture);
    sprite.setTextureRect(sf::IntRect(0, 0, 42, 57));
    sprite.setPosition(x, y);
}

void Player::setName(){
    cout << "Insert your NAME here: \n";
    cin >> namePlayer;
}

void Player::updateWindowBoundsCollision(const RenderTarget *target) {
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

void Player::setGraphics(Texture texture) {
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 42, 57));
}

void Player::update(const RenderTarget* target, vector <int> map, int mapWidth, int mapHeight, int px) {
    this->handleInput(map, mapWidth, mapHeight, px);
    //window collision detection
    this->updateWindowBoundsCollision(target);
}

void Player::render(RenderWindow* window) {
    window->draw(sprite);
}

void Player::handleInput(vector <int> map, int mapWidth, int mapHeight, int px) {
    PlayerState* state = state_->handleInput(*this, map, mapWidth, mapHeight, px);
    if (state != NULL)
    {
        delete state_;
        state_ = state;

        // Call the enter action on the new state.
        state_->enter(*this);
    }
}

void Player::consumeEnergy(){
    energy--;
}