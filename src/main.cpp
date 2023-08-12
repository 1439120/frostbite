#include "GameWindow.h"
#include "ScoreBoard.h"
#include "IceFloeLayer.h"
#include "Player.h"
#include "Igloo.h"
#include "IceFloeLayerImplementation.h"
#include "CollisionDetector.h"

const auto screen_size = Coordinates(1000, 600);
const auto board_width = 3;

int main()
{

    sf::RenderWindow window(sf::VideoMode(screen_size.x, screen_size.y), "Frostbite");
    /** Display Classes*/
    auto game_window = GameWindow(screen_size);
    auto score_bored = ScoreBoard(screen_size);
    auto ice_floe_layer1 = IceFloeLayer(screen_size, Coordinates(0, 20));
    auto ice_floe_layer2 = IceFloeLayer(screen_size, Coordinates(350, 85));
    auto ice_floe_layer3 = IceFloeLayer(screen_size, Coordinates(0, 150));
    auto ice_floe_layer4 = IceFloeLayer(screen_size, Coordinates(350, 215));
    auto player = Player(screen_size);
    auto igloo = Igloo(screen_size);
    auto collision_detector = CollisionDetector(screen_size);
    player.AdjustPosition(Coordinates(screen_size.x / 2, screen_size.y * 3 / 4 + 10));

    /**Implementation Classes*/
    auto _ice_floe_layer1 = IceFloeLayerImplementation(ice_floe_layer1.GetPosition(), ice_floe_layer1.GetSize(), Direction::Right);
    auto _ice_floe_layer2 = IceFloeLayerImplementation(ice_floe_layer2.GetPosition(), ice_floe_layer2.GetSize(), Direction::Left);
    auto _ice_floe_layer3 = IceFloeLayerImplementation(ice_floe_layer3.GetPosition(), ice_floe_layer3.GetSize(), Direction::Right);
    auto _ice_floe_layer4 = IceFloeLayerImplementation(ice_floe_layer4.GetPosition(), ice_floe_layer4.GetSize(), Direction::Left);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Moving the ice blocks
        ice_floe_layer1.UpdatePerIce(_ice_floe_layer1.MovePerIceFloe(collision_detector));
        ice_floe_layer2.UpdatePerIce(_ice_floe_layer2.MovePerIceFloe(collision_detector));
        ice_floe_layer3.UpdatePerIce(_ice_floe_layer3.MovePerIceFloe(collision_detector));
        ice_floe_layer4.UpdatePerIce(_ice_floe_layer4.MovePerIceFloe(collision_detector));

        // Display objects on the screen
        window.clear();
        game_window.Display(&window);
        score_bored.Display(&window);
        ice_floe_layer1.Display(&window);
        ice_floe_layer2.Display(&window);
        ice_floe_layer3.Display(&window);
        ice_floe_layer4.Display(&window);
        player.Display(&window);
        igloo.Display(&window);
        window.display();
    }

    return 0;
}
