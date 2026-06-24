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
    std::optional<sf::Text> score;
    std::optional<sf::Text> temperature; 
    std::optional<sf::Text> level;
};

#endif // SCOREBOARD_H
