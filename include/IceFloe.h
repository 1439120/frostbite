//
#ifndef ICEFLOE_H
#define ICEFLOE_H
#include <SFML/Graphics.hpp>
#include "Coordniates.h"
#include <vector>
#include <iostream>

class IceFloe
{

public:
    IceFloe(Coordinates); //
    void Display(sf::RenderWindow *window);
    void FlipColor();
    void AdjustPosition(Coordinates);
    void UpdatePosition(Coordinates);
    void ResetPosition();
    Coordinates GetSize() const;
    Coordinates GetPosition() const;
    bool IsOriginalColor() const;

private:
    // sf::RectangleShape top_bar;
    // sf::RectangleShape second_layer;
    // sf::RectangleShape third_layer;
    // sf::RectangleShape fourth_layer;
    // sf::RectangleShape fifth_layer;
    // sf::RectangleShape sixth_layer;
    // sf::RectangleShape seventh_layer;
    std::vector<sf::RectangleShape> layers;
    float bar_width;
    float bar_height;
    bool isOriginal;
    Coordinates screen_size_;
};

#endif // ICEFLOE_H
