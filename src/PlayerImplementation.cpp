#include "PlayerImplementation.h"

PlayerImplementation::PlayerImplementation(Coordinates current_position, Coordinates size, Direction current_direction, float icefloe_speed)
    : _current_position(current_position), _current_direction(current_direction), _size(size), _icefloe_speed(icefloe_speed)

{
    is_mid_air = false;
    _vertical_motion = 0;
}

void PlayerImplementation::ResetPosition(Coordinates new_coord){
    _current_position = new_coord;
}

bool PlayerImplementation::MoveLeft(CollisionDetector &collision_detector, float speed)
{
    _current_position.x -= speed;
    if (collision_detector.RightScreenEntityCollision(_current_position, _size.x))
        return false;
    return true;
}
bool PlayerImplementation::MoveRight(CollisionDetector &collision_detector, float speed)
{
    _current_position.x += speed;
    if (collision_detector.RightScreenEntityCollision(_current_position, _size.x))
        return false;
    return true;
}
bool PlayerImplementation::MoveDown(float speed)
{
    if (!is_mid_air)
    {
        is_mid_air = true;
        _vertical_motion = 0;
        _current_position.y = _current_position.y + speed * 0.75;
        return true;
    }
    return false;
}
bool PlayerImplementation::MoveUp(float speed)
{
    if (!is_mid_air)
    {
        is_mid_air = true;
        _vertical_motion = -speed;
        return true;
    }
    return false;
}

Coordinates PlayerImplementation::GetPosition() const
{
    return _current_position;
}

void PlayerImplementation::AutomatedMotion(CollisionDetector &collision_detector)
{
    if (is_mid_air)
    {
        _current_position.y += _vertical_motion / 10;
        _vertical_motion += 0.01;
    }

    std::tuple<bool, int> collision_check = collision_detector.EntityIceFloeCollision(_current_position, _size.x, _size.y);
    if (std::get<0>(collision_check) && _vertical_motion >= 0)
    {
        is_mid_air = false;
        _vertical_motion = 0;
        if (std::get<1>(collision_check) % 2 == 0)
        {
            _current_position.x = _current_position.x + _icefloe_speed;
        }
        else
        {
            _current_position.x = _current_position.x - _icefloe_speed;
        }
    }
    else if (collision_detector.EntityWinnigBoundryCollision(_current_position, _size.y) && _vertical_motion >= 0)
    {
        is_mid_air = false;
        _vertical_motion = 0;
    }
    else if (!std::get<0>(collision_check))
    {
        MoveUp();
    }
}

bool PlayerImplementation::isOutofBounds(Coordinates screen_size) const{
    if(_current_position.x + _size.x  > screen_size.x &&
    _current_position.y + _size.y  > screen_size.y) return true;
    return false;
}