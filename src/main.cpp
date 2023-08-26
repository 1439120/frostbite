#include "GameWindow.h"
#include "ScoreBoard.h"
#include "IceFloeLayer.h"
#include "Player.h"
#include "Igloo.h"
#include "IceFloeLayerImplementation.h"
#include "CollisionDetector.h"
#include "PlayerImplementation.h"

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
    player.AdjustPosition(Coordinates(screen_size.x / 2, screen_size.y * 3 / 4 + 10));
    auto igloo = Igloo(screen_size);

    /**Implementation Classes*/
    /***ICE FLOES*/
    auto _ice_floe_layer1 = IceFloeLayerImplementation(ice_floe_layer1.GetPosition(), ice_floe_layer1.GetSize(), Direction::Right);
    auto _ice_floe_layer2 = IceFloeLayerImplementation(ice_floe_layer2.GetPosition(), ice_floe_layer2.GetSize(), Direction::Left);
    auto _ice_floe_layer3 = IceFloeLayerImplementation(ice_floe_layer3.GetPosition(), ice_floe_layer3.GetSize(), Direction::Right);
    auto _ice_floe_layer4 = IceFloeLayerImplementation(ice_floe_layer4.GetPosition(), ice_floe_layer4.GetSize(), Direction::Left);
    /** PLAYER*/
    auto _player = PlayerImplementation(player.GetPosition(), player.GetSize(), Direction::Right);
    /** COLLISION DETECTOR*/
    auto collision_detector = CollisionDetector(screen_size);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Left)
                {
                    _player.MoveLeft(collision_detector);
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    _player.MoveRight(collision_detector);
                }
                else if (event.key.code == sf::Keyboard::Up)
                {
                    _player.MoveUp();
                }
                else if (event.key.code == sf::Keyboard::Down)
                {
                    _player.MoveDown();
                }
            }
        }

        // Moving the ice blocks
        auto ice_floe_1_position = _ice_floe_layer1.MovePerIceFloe(collision_detector);
        ice_floe_layer1.UpdatePerIce(ice_floe_1_position);
        auto ice_floe_2_position = _ice_floe_layer2.MovePerIceFloe(collision_detector);
        ice_floe_layer2.UpdatePerIce(ice_floe_2_position);
        auto ice_floe_3_position = _ice_floe_layer3.MovePerIceFloe(collision_detector);
        ice_floe_layer3.UpdatePerIce(ice_floe_3_position);
        auto ice_floe_4_position = _ice_floe_layer4.MovePerIceFloe(collision_detector);
        ice_floe_layer4.UpdatePerIce(ice_floe_4_position);

        collision_detector.UpdateIceFloeLayerPosition(std::vector<std::vector<Coordinates>>{
            ice_floe_1_position,
            ice_floe_2_position,
            ice_floe_3_position,
            ice_floe_4_position,
        });

        // Moving the player
        _player.AutomatedMotion(collision_detector);
        player.UpdatePosition(_player.GetPosition());

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
