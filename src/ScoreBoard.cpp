// Player code
#include "ScoreBoard.h"

ScoreBoard::ScoreBoard(Coordinates screen_size)
{
    if (!font_vouge.openFromFile("res/fonts/code_new_roman.otf"))
    {
        throw "Font failed to load";
    }
    auto height = screen_size.y * 1 / 12;
    auto width = screen_size.x * 1 / 12;

    score.emplace(font_vouge, "0");
    score->setPosition(sf::Vector2f(width * 2 - width, height / 2));
    
    temperature.emplace(font_vouge, L"45°C");
    temperature->setPosition(sf::Vector2f(width * 2 - width, height * 2));

    level.emplace(font_vouge, "0");
    level->setPosition(sf::Vector2f(width * 2 + width, height * 2));
}

void ScoreBoard::Display(sf::RenderWindow *window, int score_)
{
    score->setString(std::to_string(score_));
    level->setString(std::to_string( int(score_/100) + 1));
    window->draw(*score);
    window->draw(*temperature);
    window->draw(*level);
}