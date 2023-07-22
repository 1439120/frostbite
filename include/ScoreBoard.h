//
#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <SFML/Graphics.hpp>
#include "Coordniates.h"

class ScoreBoard
{
public:
    ScoreBoard(Coordinates); //
    void Display(sf::RenderWindow *window);

private:
    sf::Font font_vouge;
    sf::Text score;
    sf::Text temperature;
    sf::Text level;
};

#endif // GAMEWINDOW_H
