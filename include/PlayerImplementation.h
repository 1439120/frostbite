//
#ifndef PLAYEYIMPLEMENTATION_H
#define PLAYEYIMPLEMENTATION_H
#include "Coordniates.h"
#include "Direction.h"
#include "CollisionDetector.h"
#include <iostream>

class PlayerImplementation
{
public:
    PlayerImplementation(Coordinates, Coordinates, Direction); //
    bool MoveLeft(CollisionDetector &, float = 15);
    bool MoveRight(CollisionDetector &, float = 15);
    bool MoveDown(CollisionDetector &, float = 15);
    bool MoveUp(CollisionDetector &, float = 15);
    void AutomatedMotion(CollisionDetector &);
    Coordinates GetPosition() const;

private:
    Coordinates _current_position;
    Direction _current_direction;
    Coordinates _size;
    float _vertical_motion;
    bool is_mid_air;
};

#endif // PLAYEYIMPLEMENTATION_H
