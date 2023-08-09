//
#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Coordniates.h"

class Player
{
public:
    Player(Coordinates); //
    void Display(sf::RenderWindow *window);
    void AdjustPosition(Coordinates);

private:
    sf::RectangleShape player;
    sf::Texture player_texture;
};

#endif // PLAYER_H
