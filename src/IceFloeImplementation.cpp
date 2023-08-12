#include "IceFloeLayerImplementation.h"

IceFloeLayerImplementation::IceFloeLayerImplementation(Coordinates current_position, Coordinates ice_size, Direction current_direction)
    : _current_direction(current_direction), _ice_size(ice_size)

{
    // _current_position(current_position),
    for (auto i = 0.0f; i < 5; i += 1.8)
    {
        Coordinates coordinates = current_position;
        coordinates.x = coordinates.x + i * _ice_size.x / 4.6;
        _current_position.push_back(coordinates);
    }
}

Coordinates IceFloeLayerImplementation::MoveIceLayer(float speed)
{
    Coordinates adjusted_by = Coordinates(0, 0);
    if (_current_position.empty())
        return adjusted_by;

    if (_current_direction == Direction::Left)
    {
        _current_position[0].x = _current_position[0].x + speed;
        adjusted_by.x = speed;
    }
    else
    {
        _current_position[0].x = _current_position[0].x - speed;
        adjusted_by.x = -speed;
    }

    return adjusted_by;
}

void IceFloeLayerImplementation::ChangeDirection(bool change_direction)
{
    if (!change_direction)
        return;

    if (_current_direction == Direction::Left)
    {
        _current_direction = Direction::Right;
    }
    else
    {
        _current_direction = Direction::Left;
    }
}

std::vector<Coordinates> IceFloeLayerImplementation::MovePerIceFloe(CollisionDetector &collision_detector, float speed)
{

    for (auto i = 0u; i < _current_position.size(); i++)
    {
        if (_current_direction == Direction::Right)
        {
            _current_position[i].x += speed;
            if (collision_detector.RightScreenEntityCollision(_current_position[i]))
                _current_position[i].x = -_ice_size.x / 4.6;
        }
        else
        {
            _current_position[i].x -= speed;
            auto check_collision_with = _current_position[i];
            check_collision_with.x += _ice_size.x / 4.6;
            if (collision_detector.LeftScreenEntityCollision(check_collision_with))
                _current_position[i].x = collision_detector.GetScreenSize().x;
        }
    }

    return _current_position;
}

const Coordinates IceFloeLayerImplementation::GetPosition() const
{

    if (_current_position.empty())
        return Coordinates(0, 0);

    return _current_position[0];
}

float IceFloeLayerImplementation::GetLength() const
{
    return _ice_size.x;
}