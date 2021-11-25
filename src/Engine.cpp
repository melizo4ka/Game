#include "Engine.h"

#include <memory>

void Engine::initVariables(unsigned WindowWidth, unsigned WindowHeight, unsigned width, unsigned height, unsigned pixels ) {
    this->WindowWidth = WindowWidth;
    this->WindowHeight = WindowHeight;
    this->level = readMapFile(map);
    this->mapWidth = width;
    this->mapHeight = height;
    this->pixels = pixels;
}
void Engine::initWindow() {
    this->videoMode = VideoMode(WindowWidth, WindowHeight);
    this->window = std::make_shared<RenderWindow> (this->videoMode, "Farm", Style::Close | Style::Titlebar);
    this->window->setFramerateLimit(60);
}

Engine::Engine() {
    this->initVariables(1024, 512, 16, 8, 64);
    this->initWindow();
}

Engine::~Engine(){

}

std::shared_ptr<int> Engine::readMapFile (int map[]) {
    ifstream myfile ("../assets/map.txt");
    try {
        myfile.is_open();
    }
    catch(...){
        std::cerr << "Couldn't find Map File" << std::endl;
    }
    while (! myfile.eof() )
    {
        char piece;
        int symbol;
        for(int i = 0; i < 129; i++){
            myfile >> piece;
            symbol = piece-'0';
            map[i] = symbol;
        }
    }
    myfile.close();
    return std::shared_ptr<int> (map);
}

bool Engine::running() const {
    return this->window->isOpen();
}

void Engine::pollEvents(){
    while(this->window->pollEvent(this->sfmlEvent)){
        switch (this->sfmlEvent.type){
            //window closing
            case Event::Closed:
                this->window->close();
                break;
            case Event::KeyPressed:
                if(this->sfmlEvent.key.code == Keyboard::Escape)
                    this->window->close();

                // display inventory on request with I
                else if(this->sfmlEvent.key.code == Keyboard::I && !iPressed)
                    iPressed = true;
                else if(this->sfmlEvent.key.code == Keyboard::I && iPressed)
                    iPressed = false;
                break;
        }
    }
}

void Engine::update() {
    try{
        tilemap.load("assets/tileset.png", sf::Vector2u(32, 32), this->map, 16, 8);
    }
    catch (...){
        std::cerr << "Couldn't load the Tile Map" << std::endl;
    }
    this->pollEvents();
    this->player.update(this->window, this->map, this->mapWidth, this->mapHeight, this->pixels);
    render();
}

void Engine::render() {
    this->window->clear();
    this->window->draw(tilemap);
    this->showText();
    this->player.render(this->window);
    if(iPressed){
        this->showInventory(player.inventory);
    }
    this->window->display();
}

void Engine::showText() const {
    sf::Font font;
    try{
        font.loadFromFile("../assets/arial.ttf");
    }
    catch (...){
        std::cerr << "Couldn't find Arial Font" << std::endl;
    }
    sf::Text text;
    text.setFont(font);
    text.setString(this->player.namePlayer+" Day:" +to_string(this->player.day)+ " Money: "+to_string(this->player.money)+" Energy: "+to_string(this->player.energy));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    window->draw(text);
}

void Engine::showInventory(int inventory[6][2]) const{
    sf::Texture texture;
    try{
        texture.loadFromFile("../assets/itemset.png");
    }
    catch (...){
        std::cerr << "Couldn't find Inventory texture" << std::endl;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);
    window->draw(sprite);

    sf::Font font;
    try{
        font.loadFromFile("../assets/arial.ttf");
    }
    catch (...){
        std::cerr << "Couldn't find Arial Font" << std::endl;
    }

    sf::Text text;
    text.setFont(font);
    text.setString("Salmon " + to_string(inventory[0][1])+ "; Herring: "+ to_string(inventory[1][1])+
    "; Potato S. : "+ to_string(inventory[2][1])+"; Potatoes: "+ to_string(inventory[3][1])+
    "; Apple S.: "+ to_string(inventory[4][1])+"; Apples: "+ to_string(inventory[5][1]));
    text.setCharacterSize(12);
    text.setFillColor(sf::Color::Black);
    window->draw(text);
}
