//
#ifndef ICEFLOELAYER_H
#define ICEFLOELAYER_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "IceFloe.h"

class IceFloeLayer
{
public:
    IceFloeLayer(Coordinates, Coordinates); //
    void Display(sf::RenderWindow *window);

private:
    std::vector<IceFloe> ice_floe_layer;
};

#endif // ICEFLOELAYER_H
