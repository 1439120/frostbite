//
#ifndef ICEFLOELAYEIMPLEMENTATION_H
#define ICEFLOELAYEIMPLEMENTATION_H
#include <vector>
#include "Coordniates.h"
#include "Direction.h"
#include "CollisionDetector.h"
#include <iostream>

class IceFloeLayerImplementation
{
public:
    IceFloeLayerImplementation(Coordinates, Coordinates, Direction); //
    Coordinates MoveIceLayer(float = 0.2);
    std::vector<Coordinates> MovePerIceFloe(CollisionDetector &, float = 0.2);
    void ChangeDirection(bool);
    const Coordinates GetPosition() const;
    float GetLength() const;

private:
    std::vector<Coordinates> _current_position;
    Direction _current_direction;
    Coordinates _ice_size;
};

#endif // ICEFLOELAYEIMPLEMENTATION_H
