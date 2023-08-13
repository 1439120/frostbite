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
    void UpdatePosition(Coordinates);
    const Coordinates GetSize() const;
    const Coordinates GetPosition() const;

private:
    sf::RectangleShape player;
    sf::Texture player_texture;
    Coordinates size;
};

#endif // PLAYER_H
