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
const Coordinates IceFloeLayer::GetSize() const
{
    // x value of last block plus its width minus x value of first block = length
    // height of block
    auto x_value = ice_floe_layer[2].GetPosition().x + ice_floe_layer[2].GetSize().x - ice_floe_layer[0].GetPosition().x;
    auto y_value = ice_floe_layer[0].GetPosition().y;
    return Coordinates(x_value, y_value);
}

const Coordinates IceFloeLayer::GetPosition() const
{
    return ice_floe_layer[0].GetPosition();
}

void IceFloeLayer::AdjustPosition(Coordinates adjust_by)
{
    for (auto ice_floe = ice_floe_layer.begin(); ice_floe != ice_floe_layer.end(); ice_floe++)
    {
        ice_floe->AdjustPosition(adjust_by);
    }
}

void IceFloeLayer::UpdatePosition(Coordinates new_position)
{
    for (auto ice_floe = ice_floe_layer.begin(); ice_floe != ice_floe_layer.end(); ice_floe++)
    {
        ice_floe->UpdatePosition(new_position);
    }
}

void IceFloeLayer::AdjustPerIce(std::vector<Coordinates> adjusted_by_per_ice)
{
    for (auto i = 0u; i < ice_floe_layer.size(); i++)
    {
        ice_floe_layer[i].AdjustPosition(adjusted_by_per_ice[i]);
    }
}

void IceFloeLayer::UpdatePerIce(std::vector<Coordinates> new_position_per_ice)
{
    for (auto i = 0u; i < ice_floe_layer.size(); i++)
    {
        ice_floe_layer[i].UpdatePosition(new_position_per_ice[i]);
    }
}