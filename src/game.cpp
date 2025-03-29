#include "game.hpp"

Game::Game(){
    backgroundTexture = nullptr;
    groundTexture = nullptr;
    backgroundTexture = new sf::Texture();
    if (!backgroundTexture->loadFromFile("../res/textures/background/day.png")){
        std::cout << "backgroundTexture failed to load" << std::endl;
    }
    groundTexture = new sf::Texture();
    if (!groundTexture->loadFromFile("../res/textures/ground.png")){
        std::cout << "groundTexture failed to load" << std::endl;
    }

    groundSprite = new sf::Sprite(*groundTexture);
    groundSprite->setPosition(0, backgroundTexture->getSize().y);
    bird = new Bird();
    pipe = new Pipe();
    window = new Window(sf::Vector2u(400, 700));
    window->setFramerateLimit(60);

    groundRect = new sf::RectangleShape(sf::Vector2f((float)groundSprite->getTextureRect().width, window->getSize().y - ((float)backgroundTexture->getSize().y + (float)groundSprite->getTextureRect().height)));
    groundRect->setPosition(0, groundSprite->getPosition().y + (float)groundSprite->getTextureRect().height);
    groundRect->setFillColor(sf::Color(245, 228, 138));

    gameOver = false;
    gameStarted = false;

    
}
Game::~Game(){
    delete window;
    delete bird;
    delete backgroundTexture;
    delete groundTexture;
    delete groundSprite;
    delete groundRect;
    delete pipe;
}

void Game::update(){
    updateDt();
    if (gameStarted){
        bird->update(gameStarted, getDt());
        pipe->update(gameStarted, getDt());
        if (groundSprite->getPosition().x <= -96){
            groundSprite->move(96, 0);
        }else{
            groundSprite->move(-100 * dt, 0);
        }
        if (collided(*bird, *pipe)){
            gameOver = true;
            gameStarted = false;
        }
    }
}
void Game::updateDt(){
    dt = dtClock.getElapsedTime().asSeconds();
    dtClock.restart();
}

void Game::draw(){
    window->clear();
    window->draw(sf::Sprite(*backgroundTexture));
    bird->draw(*window, getDt());
    pipe->draw(* window, getDt());
    window->draw(*groundSprite);
    window->draw(*groundRect);

    
    window->display();
}
void Game::handleEvent(sf::Event &event){
    while(window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
        {
            window->close();
        }
        if (event.type == sf::Event::MouseButtonPressed){
            if (!gameStarted){
                gameStarted = true;
            }
            bird->setVel(sf::Vector2i(bird->getVel().x, -450));
        }
        if (event.type == sf::Event::KeyReleased){
            bird->setVel(sf::Vector2i(bird->getVel().x, 450));
        }
    }
}

bool Game::IsRunning(){
    return window->isOpen();
}

float Game::getTime() const {
    return gameTimer.getElapsedTime().asMilliseconds();
}

bool Game::collided(Bird& bird,Pipe& pipe){
    if (bird.getPosition().y + bird.getTextureRect().height < 0){
        // bird is in the space;
        return true;
    }
    if (bird.getPosition().y + bird.getTextureRect().height > window->getSize().y){
        // bird on the flore;
        bird.setVel(sf::Vector2i(0, 0));
        bird.setPosition(sf::Vector2f(0, groundSprite->getPosition().y + bird.getTextureRect().height));
        return true;
    }
    for (int i = 0; i<pipe.getUpPipe().size(); i++){
        if (bird.getRect().intersects(pipe.getUpPipeRect(*pipe.getUpPipe()[i]))){
            return true;
        }
        if (bird.getRect().intersects(pipe.getDownPipeRect(*pipe.getDownPipe()[i]))){
            return true;
        }
    }
    return false;
}