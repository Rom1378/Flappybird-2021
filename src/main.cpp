#include <iostream>
#include "game.hpp"

int main(){
    Game game;
    
    while(game.IsRunning()){
        sf::Event event{};

        game.handleEvent(event);
        game.update();
        game.draw();
        if (game.GameOver()){ return 0; }
    }

    return 0;
}