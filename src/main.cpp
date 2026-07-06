#include "GameWindow.h"
#include "ScoreBoard.h"
#include "IceFloeLayer.h"
#include "Player.h"
#include "Igloo.h"
#include "IceFloeLayerImplementation.h"
#include "CollisionDetector.h"
#include "PlayerImplementation.h"
#include "WelcomeWindow.h"

const auto screen_size = Coordinates(1000, 600);
const auto board_width = 3;

int main()
{

    sf::RenderWindow window(sf::VideoMode({static_cast<unsigned int>(screen_size.x), static_cast<unsigned int>(screen_size.y)}), "Frostbite");
    /** Display Classes*/
    auto game_window = GameWindow(screen_size);
    auto score_bored = ScoreBoard(screen_size);
    auto ice_floe_layer1 = IceFloeLayer(screen_size, Coordinates(0, 20));
    auto ice_floe_layer2 = IceFloeLayer(screen_size, Coordinates(350, 85));
    auto ice_floe_layer3 = IceFloeLayer(screen_size, Coordinates(0, 150));
    auto ice_floe_layer4 = IceFloeLayer(screen_size, Coordinates(350, 215));
    auto player = Player(screen_size);
    // player.UpdatePosition(Coordinates(screen_size.x / 2, screen_size.y * 3 / 4 + 10));
    auto welcome_window = WelcomeWindow();
    /* Game control constants */
    auto igloo = Igloo(screen_size);
    const auto icefloe_speed = 0.05;
    const auto player_speed = 500 * icefloe_speed;
    const auto jump_speed = player_speed * 0.1;
    auto game_status = GameState::MAIN_MENU;

    /**Implementation Classes*/
    /***ICE FLOES*/
    auto _ice_floe_layer1 = IceFloeLayerImplementation(ice_floe_layer1.GetPosition(), ice_floe_layer1.GetSize(), Direction::Right);
    auto _ice_floe_layer2 = IceFloeLayerImplementation(ice_floe_layer2.GetPosition(), ice_floe_layer2.GetSize(), Direction::Left);
    auto _ice_floe_layer3 = IceFloeLayerImplementation(ice_floe_layer3.GetPosition(), ice_floe_layer3.GetSize(), Direction::Right);
    auto _ice_floe_layer4 = IceFloeLayerImplementation(ice_floe_layer4.GetPosition(), ice_floe_layer4.GetSize(), Direction::Left);
    /** PLAYER*/
    auto _player = PlayerImplementation(player.GetPosition(), player.GetSize(), Direction::Right, icefloe_speed);
    /** COLLISION DETECTOR*/
    auto collision_detector = CollisionDetector(screen_size);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            // 1. Handle Window Closing
            if (event->is<sf::Event::Closed>())
                window.close();

            // 2. Handle Mouse Clicks
            if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mousePressed->button == sf::Mouse::Button::Left) {
                    game_status = welcome_window.handleMouseClick(mousePressed->position.x, mousePressed->position.y, &window);
                }
            }
            // 3. Handle Mouse Movement
            if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>()) {
                welcome_window.handleMouseMove(mouseMoved->position.x, mouseMoved->position.y);
            }
            // 4. Handle Keyboard Presses
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->code == sf::Keyboard::Key::Escape) {
                    if (game_status == GAME_PLAY) {
                        game_status = GameState::PAUSED;
                    }
                }
                //playing game
                if (keyPressed->code == sf::Keyboard::Key::Left)
                {
                    _player.MoveLeft(collision_detector, player_speed);
                }
                else if (keyPressed->code == sf::Keyboard::Key::Right)
                {
                    _player.MoveRight(collision_detector, player_speed);
                }
                else if (keyPressed->code == sf::Keyboard::Key::Up)
                {
                    _player.MoveUp();
                }
                else if (keyPressed->code == sf::Keyboard::Key::Down)
                {
                    _player.MoveDown(jump_speed);
                }
            }
        }

        if(game_status == GameState::GAME_PLAY){
            // Moving the ice blocks
            auto ice_floe_1_position = _ice_floe_layer1.MovePerIceFloe(collision_detector, icefloe_speed);
            ice_floe_layer1.UpdatePerIce(ice_floe_1_position);
            auto ice_floe_2_position = _ice_floe_layer2.MovePerIceFloe(collision_detector, icefloe_speed);
            ice_floe_layer2.UpdatePerIce(ice_floe_2_position);
            auto ice_floe_3_position = _ice_floe_layer3.MovePerIceFloe(collision_detector, icefloe_speed);
            ice_floe_layer3.UpdatePerIce(ice_floe_3_position);
            auto ice_floe_4_position = _ice_floe_layer4.MovePerIceFloe(collision_detector, icefloe_speed);
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
            if(_player.isOutofBounds(screen_size)) game_status = GameState::LOST;
            // Reset game ifnormation
            if(game_status == GameState::LOST){

            }
        }
        
        // Display objects on the screen
        window.clear();
        if(game_status == GameState::MAIN_MENU){
            welcome_window.drawMainMenu(&window);
        }
        else if(game_status == GameState::GAME_PLAY){
            game_window.Display(&window);
            score_bored.Display(&window);
            ice_floe_layer1.Display(&window);
            ice_floe_layer2.Display(&window);
            ice_floe_layer3.Display(&window);
            ice_floe_layer4.Display(&window);
            player.Display(&window);
            igloo.Display(&window);
            // welcome_window.drawGame(&window);
        }else if(game_status == GameState::INSTRUCTIONS){
            welcome_window.drawInstructions(&window);
        }else if(game_status == GameState::SCORE_HISTORY){
            welcome_window.drawScoreHistory(&window);
        }else{
            welcome_window.drawGamePaused(&window);
        }
        window.display();
    }

    return 0;
}
