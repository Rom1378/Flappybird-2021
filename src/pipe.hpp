#ifndef PIPE_HPP
#define PIPE_HPP
#define SFML_STATIC
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <ctime>

class Pipe {
        
    public:
    Pipe();
    ~Pipe();

    void update(bool gameIsStarted, float dt);
    void draw(sf::RenderWindow & window, float dt);
    const std::vector<sf::Sprite *> & getUpPipe() { return upPipe; }
    const std::vector<sf::Sprite *> & getDownPipe() { return downPipe; }

    sf::FloatRect getDownPipeRect(const sf::Sprite & pipe) const ;
    sf::FloatRect getUpPipeRect(const sf::Sprite & pipe) const;
    private:
    std::vector<sf::Sprite*> upPipe;
    sf::Texture *upTexPipe;
    std::vector<sf::Sprite*> downPipe;
    sf::Texture *downTexPipe;

    unsigned int lastPipePrited;
    //sf::Sprite *upPipe;
    //sf::Sprite *downPipe;
    //std::vector<sf::Sprite *> pipes;
    //sf::Sprite *test;

    //sf::Vector2i vel;
};

#endif