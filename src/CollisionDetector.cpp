#include "CollisionDetector.h"

CollisionDetector::CollisionDetector(Coordinates screen_size)
    : _screen_size(screen_size)

{
}

bool CollisionDetector::ScreenEntityCollision(Coordinates position, float length, float height)
{

    if (RightScreenEntityCollision(position, length, height) || LeftScreenEntityCollision(position, length, height) ||
        DownScreenEntityCollision(position, length, height) || UpScreenEntityCollision(position, length, height))
    {
        return true;
    }

    return false;
}

bool CollisionDetector::RightScreenEntityCollision(Coordinates position, float length, float height)
{
    if (position.x + length >= _screen_size.x)
    {
        return true;
    }

    return false;
}

bool CollisionDetector::LeftScreenEntityCollision(Coordinates position, float length, float height)
{
    if (position.x <= 0)
    {
        return true;
    }

    return false;
}

bool CollisionDetector::DownScreenEntityCollision(Coordinates position, float length, float height)
{
    if (position.y + height >= _screen_size.y)
    {
        return true;
    }

    return false;
}

bool CollisionDetector::UpScreenEntityCollision(Coordinates position, float length, float height)
{
    if (position.y <= 0)
    {
        return true;
    }

    return false;
}

const Coordinates CollisionDetector::GetScreenSize() const
{
    return _screen_size;
}