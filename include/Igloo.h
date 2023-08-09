//
#ifndef IGLOO_H
#define IGLOO_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Coordniates.h"

class Igloo
{
public:
    Igloo(Coordinates); //
    void Display(sf::RenderWindow *window);
    void BuildIgloo();
    bool isDoorOpen() const;

private:
    std::vector<sf::RectangleShape> igloo;
    unsigned int level;
    bool is_door_open;
    void OpenDoor();
};

#endif // IGLOO_H
