#include "Engine.h"

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
    this->window = new RenderWindow(this->videoMode, "Farm", Style::Close | Style::Titlebar);
    this->window->setFramerateLimit(60);
}

Engine::Engine() {
    this->initVariables(1024, 512, 16, 8, 64);
    this->initWindow();
}

Engine::~Engine(){
    delete this->window;
}

int* Engine::readMapFile(int level[]) {
    ifstream myfile ("../assets/map.txt");
    if (myfile.is_open())
    {
        while (! myfile.eof() )
        {
            char piece;
            int symbol;
            for(int i = 0; i < 129; i++){
                myfile >> piece;
                symbol = piece-'0';
                level[i] = symbol;
            }
        }
        myfile.close();
    }
    else {
        cout << "Can't find input file " << endl;
    }
    return level;
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
    if(!tilemap.load("assets/tileset.png", sf::Vector2u(32, 32), level, 16, 8))
    {
        // error...
    }
    this->pollEvents();
    this->player.update(this->window, this->map, this->mapWidth, this->mapHeight, this->pixels);
    render(tilemap);
}

void Engine::render(TileMap) {
    this->window->clear();
    this->window->draw(tilemap);//<---
    this->showText();
    this->player.render(this->window);
    if(iPressed){
        this->showInventory(player.inventory);
    }
    this->window->display();
}

void Engine::showText() {
    sf::Font font;
    if (!font.loadFromFile("../assets/arial.ttf"))
    {
        // error...
    }
    sf::Text text;
    text.setFont(font);
    text.setString(this->player.namePlayer+" Day:" +to_string(this->player.day)+ " Money: "+to_string(this->player.money)+" Energy: "+to_string(this->player.energy));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    window->draw(text);
}

void Engine::showInventory(int inventory[6][2]){
    sf::Texture texture;
    if (!texture.loadFromFile("../assets/itemset.png"))
    {
        // error...
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);
    window->draw(sprite);

    sf::Font font;
    if (!font.loadFromFile("../assets/arial.ttf"))
    {
        // error...
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Salmon " + to_string(inventory[0][1])+ "; Herring: "+to_string(inventory[1][1])+
    "; Potato S. : "+to_string(inventory[2][1])+"; Potatoes: "+to_string(inventory[3][1])+
    "; Apple S.: "+to_string(inventory[4][1])+"; Apples: "+to_string(inventory[5][1]));
    text.setCharacterSize(12);
    text.setFillColor(sf::Color::Black);
    window->draw(text);
}
