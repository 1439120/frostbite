// Player code
#include "IceFloeLayer.h"

IceFloeLayer::IceFloeLayer(Coordinates screen_size, Coordinates adjust_by)
{
    auto ice_floe1 = IceFloe(screen_size);
    ice_floe1.AdjustPosition(Coordinates(adjust_by.x, adjust_by.y));
    ice_floe_layer.push_back(ice_floe1);

    auto ice_floe2 = IceFloe(screen_size);
    ice_floe2.AdjustPosition(Coordinates(1.8 * ice_floe2.GetSize().x + adjust_by.x, adjust_by.y));
    ice_floe_layer.push_back(ice_floe2);

    auto ice_floe3 = IceFloe(screen_size);
    ice_floe3.AdjustPosition(Coordinates(3.6 * ice_floe2.GetSize().x + adjust_by.x, adjust_by.y));
    ice_floe_layer.push_back(ice_floe3);
}

void IceFloeLayer::Display(sf::RenderWindow *window)
{
    for (auto ice_floe = ice_floe_layer.begin(); ice_floe != ice_floe_layer.end(); ice_floe++)
    {
        ice_floe->Display(window);
    }
}