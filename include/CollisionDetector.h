//
#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H
#include "Coordniates.h"

class CollisionDetector
{
public:
    CollisionDetector(Coordinates); //
    bool ScreenEntityCollision(Coordinates, float = 0, float = 0);
    bool RightScreenEntityCollision(Coordinates, float = 0, float = 0);
    bool LeftScreenEntityCollision(Coordinates, float = 0, float = 0);
    bool DownScreenEntityCollision(Coordinates, float = 0, float = 0);
    bool UpScreenEntityCollision(Coordinates, float = 0, float = 0);
    const Coordinates GetScreenSize() const;

private:
    Coordinates _screen_size;
};

#endif // COLLISIONDETECTOR_H
