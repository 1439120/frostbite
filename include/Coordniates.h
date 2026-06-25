//
#ifndef COORDINATES_H
#define COORDINATES_H

struct Coordinates
{
    float x;
    float y;
    Coordinates()
    {
        x = 0;
        y = 0;
    }
    Coordinates(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    Coordinates(const Coordinates &coord)
    {
        x = coord.x;
        y = coord.y;
    }
    bool operator==(const Coordinates &coord)
    {
        if (this->x == coord.x && this->y == coord.y)
            return true;
        return false;
    }
    bool operator!=(const Coordinates &coord)
    {
        if (this->x != coord.x || this->y != coord.y)
            return true;
        return false;
    }
};

#endif // COORDINATES_H
