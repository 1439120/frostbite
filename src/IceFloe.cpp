// Player code
#include "IceFloe.h"

IceFloe::IceFloe(Coordinates screen_size) : bar_width(screen_size.x * 1 / 10), bar_height(3), isOriginal(true)
{

    auto height = screen_size.y - screen_size.y * 19 / 40 + screen_size.y * 1 / 50;
    height += 25;

    top_bar.setSize(sf::Vector2f(bar_width, bar_height));
    top_bar.setFillColor(sf::Color(89, 164, 240)); // light blue
    top_bar.setPosition(sf::Vector2f(bar_width, height));

    height += bar_height;
    second_layer.setSize(sf::Vector2f(bar_width, bar_height));
    second_layer.setFillColor(sf::Color(89, 164, 240)); // light blue
    second_layer.setPosition(sf::Vector2f(bar_width - bar_height * 2, height));

    height += bar_height;
    third_layer.setSize(sf::Vector2f(bar_width, bar_height));
    third_layer.setFillColor(sf::Color(89, 164, 240)); // light blue
    third_layer.setPosition(sf::Vector2f(bar_width - (bar_height * 2 + bar_height / 2), height));

    height += bar_height;
    fourth_layer.setSize(sf::Vector2f(bar_width, bar_height));
    fourth_layer.setFillColor(sf::Color(89, 164, 240)); // light blue
    fourth_layer.setPosition(sf::Vector2f(bar_width - (bar_height * 4 + bar_height / 2), height));

    height += bar_height;
    fifth_layer.setSize(sf::Vector2f(bar_width, bar_height));
    fifth_layer.setFillColor(sf::Color(89, 164, 240)); // light blue
    fifth_layer.setPosition(sf::Vector2f(bar_width - (bar_height * 4 - bar_height / 3), height));

    height += bar_height;
    sixth_layer.setSize(sf::Vector2f(bar_width, bar_height));
    sixth_layer.setFillColor(sf::Color(89, 164, 240)); // light blue
    sixth_layer.setPosition(sf::Vector2f(bar_width - (bar_height * 4 + bar_height * 3 / 2), height));

    height += bar_height;
    seventh_layer.setSize(sf::Vector2f(bar_width, bar_height));
    seventh_layer.setFillColor(sf::Color(89, 164, 240)); // light blue
    seventh_layer.setPosition(sf::Vector2f(bar_width - (bar_height * 4 + bar_height * 5), height));
}

void IceFloe::Display(sf::RenderWindow *window)
{
    window->draw(top_bar);
    window->draw(second_layer);
    window->draw(third_layer);
    window->draw(fourth_layer);
    window->draw(fifth_layer);
    window->draw(sixth_layer);
    window->draw(seventh_layer);
}

void IceFloe::FlipColor()
{
    if (isOriginal)
    {
        top_bar.setFillColor(sf::Color::White);
        second_layer.setFillColor(sf::Color::White);
        third_layer.setFillColor(sf::Color::White);
        fourth_layer.setFillColor(sf::Color::White);
        fifth_layer.setFillColor(sf::Color::White);
        sixth_layer.setFillColor(sf::Color::White);
        seventh_layer.setFillColor(sf::Color::White);
    }
    else
    {
        top_bar.setFillColor(sf::Color(89, 164, 240));
        second_layer.setFillColor(sf::Color(89, 164, 240));
        third_layer.setFillColor(sf::Color(89, 164, 240));
        fourth_layer.setFillColor(sf::Color(89, 164, 240));
        fifth_layer.setFillColor(sf::Color(89, 164, 240));
        sixth_layer.setFillColor(sf::Color(89, 164, 240));
        seventh_layer.setFillColor(sf::Color(89, 164, 240));
    }
    isOriginal = !isOriginal;
}

void IceFloe::AdjustPosition(Coordinates adjust_by)
{
    auto current_pos = top_bar.getPosition();
    top_bar.setPosition(sf::Vector2f(adjust_by.x + current_pos.x, adjust_by.y + current_pos.y));

    current_pos = second_layer.getPosition();
    second_layer.setPosition(sf::Vector2f(adjust_by.x + current_pos.x, adjust_by.y + current_pos.y));

    current_pos = third_layer.getPosition();
    third_layer.setPosition(sf::Vector2f(adjust_by.x + current_pos.x, adjust_by.y + current_pos.y));

    current_pos = fourth_layer.getPosition();
    fourth_layer.setPosition(sf::Vector2f(adjust_by.x + current_pos.x, adjust_by.y + current_pos.y));

    current_pos = fifth_layer.getPosition();
    fifth_layer.setPosition(sf::Vector2f(adjust_by.x + current_pos.x, adjust_by.y + current_pos.y));

    current_pos = sixth_layer.getPosition();
    sixth_layer.setPosition(sf::Vector2f(adjust_by.x + current_pos.x, adjust_by.y + current_pos.y));

    current_pos = seventh_layer.getPosition();
    seventh_layer.setPosition(sf::Vector2f(adjust_by.x + current_pos.x, adjust_by.y + current_pos.y));
}

const Coordinates IceFloe::GetSize() const
{
    return Coordinates(bar_width, bar_height);
}