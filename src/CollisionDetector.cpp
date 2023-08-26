#include "CollisionDetector.h"

CollisionDetector::CollisionDetector(Coordinates screen_size)
    : _screen_size(screen_size)

{
    _ice_floe_size.x = screen_size.x * 1 / 10;
    _ice_floe_size.y = 7 * 3;
    _winning_boundry = screen_size.y + 3 - screen_size.y * 19 / 40;
}

bool CollisionDetector::ScreenEntityCollision(Coordinates position, float length, float height)
{

    if (RightScreenEntityCollision(position, length) || LeftScreenEntityCollision(position) ||
        DownScreenEntityCollision(position, height) || UpScreenEntityCollision(position))
    {
        return true;
    }

    return false;
}

bool CollisionDetector::RightScreenEntityCollision(Coordinates position, float length)
{
    if (position.x + length >= _screen_size.x)
    {
        return true;
    }

    return false;
}

bool CollisionDetector::LeftScreenEntityCollision(Coordinates position, float length)
{
    if (position.x + length <= 0)
    {
        return true;
    }

    return false;
}

bool CollisionDetector::DownScreenEntityCollision(Coordinates position, float height)
{
    if (position.y + height >= _screen_size.y)
    {
        return true;
    }

    return false;
}

bool CollisionDetector::UpScreenEntityCollision(Coordinates position, float height)
{
    if (position.y + height <= 0)
    {
        return true;
    }

    return false;
}

const Coordinates CollisionDetector::GetScreenSize() const
{
    return _screen_size;
}

void CollisionDetector::UpdateIceFloeLayerPosition(std::vector<std::vector<Coordinates>> ice_floe_layers)
{
    _ice_floe_layers = ice_floe_layers;
}

std::tuple<bool, int> CollisionDetector::EntityIceFloeCollision(Coordinates position, float length, float height)
{

    for (auto i = 0u; i < _ice_floe_layers.size(); i++)
    {
        for (auto ice_floe_layer = _ice_floe_layers[i].begin(); ice_floe_layer != _ice_floe_layers[i].end(); ice_floe_layer++)
        {

            if (position.x >= ice_floe_layer->x - 3 && position.x + length <= ice_floe_layer->x + _ice_floe_size.x)
            {
                if (position.y + height >= ice_floe_layer->y && position.y + height <= ice_floe_layer->y + _ice_floe_size.y / 7)
                    return std::tuple<bool, int>(true, i);
            }
        }
    }
    return std::tuple<bool, int>(false, -1);
}

bool CollisionDetector::EntityWinnigBoundryCollision(Coordinates position, float height)
{
    if (position.y + height <= _winning_boundry && position.y + height >= _winning_boundry - 1)
        return true;

    return false;
}