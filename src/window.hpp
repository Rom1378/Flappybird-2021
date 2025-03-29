#ifndef WINDOW_HPP
#define WINDOW_HPP
#define SFML_STATIC
#include <SFML/Graphics.hpp>

class Window : public sf::RenderWindow
{
private:
    
public:
    Window(sf::Vector2u size);
    ~Window();
};


#endif