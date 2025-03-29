#include "window.hpp"


Window::Window(sf::Vector2u size) : sf::RenderWindow(sf::VideoMode(size.x, size.y), "flappy")
{

}

Window::~Window()
{
}