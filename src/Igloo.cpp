// Player code
#include "Igloo.h"

Igloo::Igloo(Coordinates screen_size) : level(50), is_door_open(false)
{
    auto block_size = Coordinates(screen_size.x / 50, screen_size.x / 100);

    auto y_value = screen_size.y * 3 / 8 + block_size.y;
    auto x_value = screen_size.x * 3 / 4;
    auto multiplier = 1;
    // First three layers of the igloo
    for (auto i = 0u; i < 24; i++)
    {
        auto block = sf::RectangleShape(sf::Vector2f(block_size.x, block_size.y));
        block.setFillColor(sf::Color::White);

        if (i % 8 == 0 && i != 0)
        {
            y_value = y_value - block_size.y;
            multiplier = multiplier * -1;
        }
        else
        {
            x_value = x_value + block_size.x * multiplier;
        }
        block.setPosition(sf::Vector2f(x_value, y_value));
        igloo.push_back(block);
    }
    // First layers of the roof of the igloo
    y_value = y_value - block_size.y;
    x_value = screen_size.x * 3 / 4 + block_size.x;
    for (auto i = 0u; i < 6; i++)
    {
        auto block = sf::RectangleShape(sf::Vector2f(block_size.x, block_size.y));
        x_value += block_size.x;
        block.setFillColor(sf::Color::White);
        block.setPosition(sf::Vector2f(x_value, y_value));
        igloo.push_back(block);
    }

    // Last layer of the roof of the igloo
    y_value = y_value - block_size.y;
    x_value = screen_size.x * 3 / 4 + 2 * block_size.x;
    for (auto i = 0u; i < 4; i++)
    {
        auto block = sf::RectangleShape(sf::Vector2f(block_size.x, block_size.y));
        x_value += block_size.x;
        block.setFillColor(sf::Color::White);
        block.setPosition(sf::Vector2f(x_value, y_value));
        igloo.push_back(block);
    }
    OpenDoor();
}

void Igloo::BuildIgloo()
{
    level = level + 1;
}

void Igloo::Display(sf::RenderWindow *window)
{
    for (auto i = 0u; i < level; i++)
    {
        if (i >= igloo.size())
            break;
        window->draw(igloo[i]);
    }
}

bool Igloo::isDoorOpen() const
{
    return is_door_open;
}

void Igloo::OpenDoor()
{
    igloo[3].setFillColor(sf::Color::Black);
    igloo[4].setFillColor(sf::Color::Black);
    igloo[11].setFillColor(sf::Color::Black);
    igloo[12].setFillColor(sf::Color::Black);
    is_door_open = true;
}