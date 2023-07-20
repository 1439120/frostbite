//
#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <SFML/Graphics.hpp>
#include "Coordniates.h"

class GameWindow
{
public:
    GameWindow(Coordinates); // Creates game view based on screen size
    void Display(sf::RenderWindow *window);

private:
    sf::RectangleShape top_bar;
    sf::RectangleShape pinkish_bar;
    sf::RectangleShape yellow_bar;
    sf::RectangleShape orange_bar;
    sf::RectangleShape grey_bar;
    sf::RectangleShape black_bar;
    sf::RectangleShape blue_bar;
};

#endif // GAMEWINDOW_H
