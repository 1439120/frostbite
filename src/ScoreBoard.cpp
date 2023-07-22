// Player code
#include "ScoreBoard.h"

ScoreBoard::ScoreBoard(Coordinates screen_size)
{
    if (!font_vouge.loadFromFile("res/fonts/Vogue.ttf"))
    {
        throw "Font failed to load";
    }
    auto height = screen_size.y * 1 / 12;
    auto width = screen_size.x * 1 / 12;
    score.setFont(font_vouge);
    score.setString("0");
    score.setPosition(sf::Vector2f(width * 2 - width, height / 2));
    temperature.setFont(font_vouge);
    temperature.setString("0 \u00B0");
    temperature.setPosition(sf::Vector2f(width * 2 - width, height * 2));
    level.setFont(font_vouge);
    level.setString("0");
    level.setPosition(sf::Vector2f(width * 2 + width, height * 2));
}

void ScoreBoard::Display(sf::RenderWindow *window)
{
    window->draw(score);
    window->draw(temperature);
    window->draw(level);
}