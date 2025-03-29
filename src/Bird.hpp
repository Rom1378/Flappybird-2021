#ifndef BIRD_HPP
#define BIRD_HPP
#define SFML_STATIC
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>


class Bird : public sf::Sprite {
    public:
    Bird();
    ~Bird();
    void update(bool gameIsStarted, float dt);

    sf::Vector2i getVel() const { return vel; }
    sf::FloatRect getRect() const ;
    
    void setVel(sf::Vector2i nVel) { vel = nVel; }

    void draw(sf::RenderWindow &window, float const& dt);
    
    private:
    
    sf::Vector2i vel;

    std::vector<sf::Texture *> textures;
    sf::Texture *currentTexture;
    sf::Clock annimationClock;
    float lastAnimationTime;



};

#endif