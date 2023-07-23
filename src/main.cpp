#include "GameWindow.h"
#include "Coordniates.h"
#include "ScoreBoard.h"
#include "IceFloeLayer.h"

const auto screen_size = Coordinates(1000, 600);

int main()
{

    sf::RenderWindow window(sf::VideoMode(screen_size.x, screen_size.y), "Frostbite");
    auto game_window = GameWindow(screen_size);
    auto score_bored = ScoreBoard(screen_size);
    auto ice_floe_layer1 = IceFloeLayer(screen_size, Coordinates(0, 20));
    auto ice_floe_layer2 = IceFloeLayer(screen_size, Coordinates(350, 85));
    auto ice_floe_layer3 = IceFloeLayer(screen_size, Coordinates(0, 150));
    auto ice_floe_layer4 = IceFloeLayer(screen_size, Coordinates(350, 215));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        game_window.Display(&window);
        score_bored.Display(&window);
        ice_floe_layer1.Display(&window);
        ice_floe_layer2.Display(&window);
        ice_floe_layer3.Display(&window);
        ice_floe_layer4.Display(&window);
        window.display();
    }

    return 0;
}
