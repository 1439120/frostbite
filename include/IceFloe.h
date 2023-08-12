//
#ifndef ICEFLOE_H
#define ICEFLOE_H
#include <SFML/Graphics.hpp>
#include "Coordniates.h"

class IceFloe
{

public:
    IceFloe(Coordinates); //
    void Display(sf::RenderWindow *window);
    void FlipColor();
    void AdjustPosition(Coordinates);
    void UpdatePosition(Coordinates);
    const Coordinates GetSize() const;
    const Coordinates GetPosition() const;

private:
    sf::RectangleShape top_bar;
    sf::RectangleShape second_layer;
    sf::RectangleShape third_layer;
    sf::RectangleShape fourth_layer;
    sf::RectangleShape fifth_layer;
    sf::RectangleShape sixth_layer;
    sf::RectangleShape seventh_layer;
    float bar_width;
    float bar_height;
    bool isOriginal;
};

#endif // ICEFLOE_H
