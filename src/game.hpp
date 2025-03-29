#ifndef GAME_HPP
#define GAME_HPP


#include "window.hpp"
#include <iostream>
#include "Bird.hpp"
#include "pipe.hpp"

class Game{
    public:
    Game();
    ~Game();
    void update();
    void updateDt();
    void draw();
    void handleEvent(sf::Event &event);

    bool IsRunning();
    bool GameOver() const { return gameOver; }
    
    float getTime() const ;

    float getDt() const { return dt; }


    private: //============private============//


    sf::Clock gameTimer;
    Window *window;
    bool gameStarted;
    bool gameOver;
    sf::Texture *backgroundTexture;
    sf::Texture *groundTexture;
    sf::Sprite *groundSprite;
    sf::RectangleShape *groundRect;

    //dt
    float dt;
    sf::Clock dtClock;

    // bird
    Bird *bird;
    
    // pipes
    Pipe *pipe;

    //collide
    bool collided(Bird& bird,Pipe& pipe);
    
};

#endif