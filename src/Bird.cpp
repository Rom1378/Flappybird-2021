#include "Bird.hpp"

Bird::Bird(){
    for (const auto& path : {
            "../res/textures/bird/1-2.png",
            "../res/textures/bird/1-3.png",
            "../res/textures/bird/1-2.png",
            "../res/textures/bird/1-1.png",}) {
            auto frame = new sf::Texture();
            frame->loadFromFile(path);
            textures.push_back(frame);
        }
    currentTexture = textures[0];
    
    setTexture(*currentTexture);
    setPosition(50, 500);
}

Bird::~Bird(){
    for (int i = 0;i<textures.size();i++){
        delete textures[i];
    }
}



void Bird::update(bool gameIsStarted, float dt){
    
    //vel update
    if (gameIsStarted && vel.y <= 450){
        vel.y += 685*dt;
    }

    //texture update
    if (gameIsStarted && annimationClock.getElapsedTime().asSeconds() > (lastAnimationTime + 0.3))
    {
        static int index = 1;
        currentTexture = textures[index];
        index += 1;
        if (index >= 4){ index = 0; }
        lastAnimationTime = annimationClock.getElapsedTime().asSeconds();
    }
    //if (vel.y <)
}

void Bird::draw(sf::RenderWindow & window, float const& dt){
    //new texture;
    setTexture(*currentTexture);
    setRotation(9*(vel.y/300));
    setPosition(50, getPosition().y + vel.y * dt);
    window.draw(*this);

}

sf::FloatRect Bird::getRect() const {
    return sf::FloatRect(getPosition().x + 10, getPosition().y, getTextureRect().width + getPosition().x - 70, getTextureRect().height);
}