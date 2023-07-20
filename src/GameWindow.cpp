// Player code
#include "GameWindow.h"

GameWindow::GameWindow(Coordinates screen_size)
{
    // top bar
    float height = 0;
    top_bar.setSize(sf::Vector2f(screen_size.x, screen_size.y * 1 / 4));
    top_bar.setFillColor(sf::Color(3, 127, 252)); // light blue
    top_bar.setPosition(sf::Vector2f(0, height));
    // pinkish bar
    height += screen_size.y * 1 / 4;
    pinkish_bar.setSize(sf::Vector2f(screen_size.x, screen_size.y * 1 / 30));
    pinkish_bar.setFillColor(sf::Color(186, 2, 207)); // pink
    pinkish_bar.setPosition(sf::Vector2f(0, height));
    // yellow bar
    height += screen_size.y * 1 / 30;
    yellow_bar.setSize(sf::Vector2f(screen_size.x, screen_size.y * 1 / 50));
    yellow_bar.setFillColor(sf::Color(219, 200, 31)); // yellow
    yellow_bar.setPosition(sf::Vector2f(0, height));
    // orange bar
    height += screen_size.y * 1 / 50;
    orange_bar.setSize(sf::Vector2f(screen_size.x, screen_size.y * 1 / 50));
    orange_bar.setFillColor(sf::Color(219, 164, 11)); // orange
    orange_bar.setPosition(sf::Vector2f(0, height));
    // grey bar
    height += screen_size.y * 1 / 50;
    grey_bar.setSize(sf::Vector2f(screen_size.x, screen_size.y * 1 / 5));
    grey_bar.setFillColor(sf::Color(145, 142, 134)); // grey
    grey_bar.setPosition(sf::Vector2f(0, height));
    // black bar
    height += screen_size.y * 1 / 5;
    black_bar.setSize(sf::Vector2f(screen_size.x, screen_size.y * 1 / 50));
    black_bar.setFillColor(sf::Color(10, 10, 10)); // black
    black_bar.setPosition(sf::Vector2f(0, height));
    // blue bar
    height += screen_size.y * 1 / 50;
    blue_bar.setSize(sf::Vector2f(screen_size.x, screen_size.y * 19 / 40));
    blue_bar.setFillColor(sf::Color(18, 6, 153)); // blue
    blue_bar.setPosition(sf::Vector2f(0, height));
}

void GameWindow::Display(sf::RenderWindow *window)
{
    window->draw(top_bar);
    window->draw(pinkish_bar);
    window->draw(yellow_bar);
    window->draw(orange_bar);
    window->draw(grey_bar);
    window->draw(black_bar);
    window->draw(blue_bar);
}