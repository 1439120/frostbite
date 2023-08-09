// Player code
#include "Player.h"

Player::Player(Coordinates screen_size)
{
    if (!player_texture.loadFromFile("res/img/player.png"))
        throw "Player texture failed to load";

    player.setSize(sf::Vector2f(24.0f, screen_size.x * 1 / 20));
    player.setTexture(&player_texture);
}

void Player::Display(sf::RenderWindow *window)
{
    window->draw(player);
}

void Player::AdjustPosition(Coordinates adjust_by)
{
    auto current_pos = player.getPosition();
    player.setPosition(sf::Vector2f(adjust_by.x + current_pos.x, adjust_by.y + current_pos.y));
}
