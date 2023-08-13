//
#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H
#include "Coordniates.h"
#include <vector>
#include <tuple>
#include <iostream>

class CollisionDetector
{
public:
    CollisionDetector(Coordinates); //
    bool ScreenEntityCollision(Coordinates, float = 0, float = 0);
    bool RightScreenEntityCollision(Coordinates, float = 0, float = 0);
    bool LeftScreenEntityCollision(Coordinates, float = 0, float = 0);
    bool DownScreenEntityCollision(Coordinates, float = 0, float = 0);
    bool UpScreenEntityCollision(Coordinates, float = 0, float = 0);
    void UpdateIceFloeLayerPosition(std::vector<std::vector<Coordinates>>);
    std::tuple<bool, int> EntityIceFloeCollision(Coordinates, float = 0, float = 0);
    bool EntityWinnigBoundryCollision(Coordinates, float = 0, float = 0);
    const Coordinates GetScreenSize() const;

private:
    Coordinates _screen_size;
    std::vector<std::vector<Coordinates>> _ice_floe_layers;
    Coordinates _ice_floe_size;
    float _winning_boundry;
};

#endif // COLLISIONDETECTOR_H
