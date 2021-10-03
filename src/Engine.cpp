#include <memory>
#include "Engine.h"

void Engine::initVariables(unsigned WindowWidth, unsigned WindowHeight) {
    this->endEngine = false;
    this->WindowWidth = WindowWidth;
    this->WindowHeight = WindowHeight;
}
void Engine::initWindow() {
    this->videoMode = VideoMode(WindowWidth, WindowHeight);
    this->window = new RenderWindow(this->videoMode, "Farm", Style::Close | Style::Titlebar);
    this->window->setFramerateLimit(60);
}

//constructor
Engine::Engine() {
    this->initVariables(1024, 512);
    this->initWindow();
}

//destructor
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
            int simb;
            for(int i = 0; i < 129; i++){
                myfile >> piece;
                simb = piece-'0';
                level[i] = simb;
            }
        }
        myfile.close();
    }
    else { //Error message
        cout << "Can't find input file " << endl;
    }
    return level;
}

void Engine::getMap(const int gameMap[], unsigned int width, unsigned int height, int pixels) {
    this->mapHeight = height;
    this->mapWidth = width;
    this->pixels = pixels; //pixel per object

    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            //pond
            if(gameMap[i + j * width] == 1){
                Pond pond(i * pixels, j * pixels);
                map.push_back(1);
            }
            //ground
            else if(gameMap[i + j * width] == 2){
                Object object(i * pixels, j * pixels);
                map.push_back(2);
            }
            //stone
            else if(gameMap[i + j * width] == 3){
                Object object(i * pixels, j * pixels);
                map.push_back(3);
            }
            //tree
            else if(gameMap[i + j * width] == 4){
                Object object(i * pixels, j * pixels);
                map.push_back(4);
            }
            //shop
            else if(gameMap[i + j * width] == 5){
                Shop shop(i * pixels, j * pixels);
                map.push_back(5);
            }
            //house
            else if(gameMap[i + j * width] == 6){
                House house(i * pixels, j * pixels);
                map.push_back(6);
            }
            else{
                map.push_back(0);
            }
        }
}

const bool Engine::running() const {
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
                if(this->sfmlEvent.key.code == Keyboard::Escape){
                    //pause
                /* display inventory on request
                else if(this->sfmlEvent.key.code == Keyboard::I)
                    this->inventory->render();*/}
                break;
        }
    }
}

void Engine::update() {
    this->pollEvents();
    this->player.update(this->window, this->map, this->mapWidth, this->mapHeight, this->pixels);
}

void Engine::render(TileMap map) {
    this->window->clear();
    this->window->draw(map);
    this->showText();
    this->player.render(this->window);
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
