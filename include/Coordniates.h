//
#ifndef COORDINATES_H
#define COORDINATES_H

struct Coordinates
{
    double x;
    double y;
    Coordinates()
    {
        x = 0;
        y = 0;
    }
    Coordinates(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    Coordinates(const Coordinates &coord)
    {
        x = coord.x;
        y = coord.y;
    }
};

#endif // COORDINATES_H
