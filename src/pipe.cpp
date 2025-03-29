#include "pipe.hpp"

Pipe::Pipe() {
    upTexPipe = new sf::Texture;
    downTexPipe = new sf::Texture;
    if (!upTexPipe->loadFromFile("../res/textures/pipe.png")){ std::cout << "pipes textures failed to load" << std::endl;}
    if (!downTexPipe->loadFromFile("../res/textures/pipe.png")){ std::cout << "pipes textures failed to load" << std::endl;}

    for (int i =0;i<4;i++){
        downPipe.push_back(new sf::Sprite(*downTexPipe));
        upPipe.push_back(new sf::Sprite(*upTexPipe));
        upPipe[i]->setOrigin(upPipe[i]->getTextureRect().width, upPipe[i]->getTextureRect().height);
        upPipe[i]->rotate(180);
    }
    srand(time(NULL));


    // set the first random place for the pipes
    int compteur = 500;
    bool tallLastTour = true;
    for (int i = 0; i < upPipe.size(); i++){
        
        int randomNumber;
        if (tallLastTour){
            randomNumber = rand() % 150 + 50;
            tallLastTour = !tallLastTour;
        }else{
            randomNumber = rand() % 150 + 200;
            tallLastTour = !tallLastTour;
        }
        upPipe[i]->setPosition(sf::Vector2f(compteur, (randomNumber * -1 - 80)));
        downPipe[i]->setPosition(sf::Vector2f(upPipe[i]->getPosition().x, upPipe[i]->getPosition().y + upPipe[i]->getTextureRect().height + 190 + (rand() % 70 + 20)));
        compteur += 260;
    }

    lastPipePrited = 3;
    
}
Pipe::~Pipe(){
    delete upTexPipe;
    delete downTexPipe;

    for (int i=0;i<upPipe.size();i++){
        delete upPipe[i];
    }
    for (int i=0;i<downPipe.size();i++){
        delete downPipe[i];
    }
}

void Pipe::update(bool gameIsStarted, float dt){
    if (gameIsStarted){
        for (int i=0;i<upPipe.size();i++){
            if (upPipe[i]->getPosition().x <= -100){
                //upPipe[i]->setPosition(sf::Vector2f(upPipe[upPipe.size()-1]->getPosition().x + 300, 10.0f));
                static bool tallLastTour = false;
                int randomNumber;
                if (tallLastTour){
                    randomNumber = rand() % 150 + 50;
                    tallLastTour = !tallLastTour;
                }else{
                    randomNumber = rand() % 150 + 200;
                    tallLastTour = !tallLastTour;
                }
                upPipe[i]->setPosition(sf::Vector2f(upPipe[lastPipePrited]->getPosition().x + 260, (randomNumber * -1 - 80)));
                downPipe[i]->setPosition(sf::Vector2f(upPipe[i]->getPosition().x, upPipe[i]->getPosition().y + upPipe[i]->getTextureRect().height + 190 + (rand() % 70 + 20)));
                lastPipePrited = i;
            }
            upPipe[i]->move(-100 * dt,0);
            downPipe[i]->move(-100 * dt,0);
        }
    }
}

void Pipe::draw(sf::RenderWindow & window, float dt){
    for (int i = 0;i<upPipe.size();i++){
        
        //upPipe[i]->setPosition(100, 20);
        //downPipe[i]->setPosition(100, 20);
        //upPipe[0]->setPosition(-150, 20);
        window.draw(*upPipe[i]);
        window.draw(*downPipe[i]);
    }
    
    
}

sf::FloatRect Pipe::getDownPipeRect(const sf::Sprite & pipe) const {
    return sf::FloatRect(pipe.getPosition().x , pipe.getPosition().y, pipe.getTextureRect().width , pipe.getTextureRect().height);
}

sf::FloatRect Pipe::getUpPipeRect(const sf::Sprite & pipe) const{
    return sf::FloatRect(pipe.getPosition().x, pipe.getPosition().y, pipe.getTextureRect().width , pipe.getTextureRect().height);
}