#include "GameWindow.h"
#include "Coordniates.h"
#include "ScoreBoard.h"

int main()
{
    auto screen_size = Coordinates(1020, 600);
    sf::RenderWindow window(sf::VideoMode(screen_size.x, screen_size.y), "Frostbite");
    GameWindow game_window = GameWindow(screen_size);
    ScoreBoard score_bored = ScoreBoard(screen_size);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // window.draw(shape);
        game_window.Display(&window);
        score_bored.Display(&window);
        window.display();
    }

    return 0;
}
