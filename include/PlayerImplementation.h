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
    PlayerImplementation(Coordinates, Coordinates, Direction, float=0.05); //
    bool MoveLeft(CollisionDetector &, float = 15);
    bool MoveRight(CollisionDetector &, float = 15);
    bool MoveDown(float = 3);
    bool MoveUp(float = 4);
    void AutomatedMotion(CollisionDetector &);
    Coordinates GetPosition() const;
    bool isOutofBounds(Coordinates) const;
    void ResetPosition(Coordinates);

private:
    Coordinates _current_position;
    Direction _current_direction;
    Coordinates _size;
    float _vertical_motion;
    bool is_mid_air;
    float _icefloe_speed;
};

#endif // PLAYEYIMPLEMENTATION_H
