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
    const Coordinates GetSize() const;
    const Coordinates GetPosition() const;
    void AdjustPosition(Coordinates);
    void UpdatePosition(Coordinates);
    void AdjustPerIce(std::vector<Coordinates>);
    void UpdatePerIce(std::vector<Coordinates>);

private:
    std::vector<IceFloe> ice_floe_layer;
};

#endif // ICEFLOELAYER_H
