#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

// Menu items
struct MenuItem {
    std::optional<sf::Text> text;
    sf::Rect<float> bounds;
    bool isHovered;
};

// Screen states
enum GameState {
    MAIN_MENU,
    INSTRUCTIONS,
    GAME_PLAY,
    SCORE_HISTORY
};

class WelcomeWindow {
    private:
        sf::Font font;
        std::vector<MenuItem> menuItems;
        std::optional<sf::Text> titleText;
        GameState currentState;
        // Score history
        std::vector<int> scores;
        std::optional<sf::Text> scoreHistoryText;
        std::optional<sf::Text> backButtonText;
        sf::Rect<float> backButtonBounds;

    public:
        WelcomeWindow();
        void setupMenu();
        void setupScoreHistory();
        void loadScores();    
        void saveScore(int score);
        void updateScoreHistory();
        GameState handleMouseClick(int mouseX, int mouseY, sf::RenderWindow *window);
        void handleMouseMove(int mouseX, int mouseY);
        void drawMainMenu(sf::RenderWindow *window);
        void drawInstructions(sf::RenderWindow *window);
        void drawScoreHistory(sf::RenderWindow *window);

        // void run() {
        //     while (window.isOpen()) {
        //         sf::Event event;
        //         while (window.pollEvent(event)) {
        //             if (event.type == sf::Event::Closed) {
        //                 window.close();
        //             }
        //             else if (event.type == sf::Event::MouseButtonPressed) {
        //                 if (event.mouseButton.button == sf::Mouse::Left) {
        //                     handleMouseClick(event.mouseButton.x, event.mouseButton.y);
        //                 }
        //             }
        //             else if (event.type == sf::Event::MouseMoved) {
        //                 handleMouseMove(event.mouseMove.x, event.mouseMove.y);
        //             }
        //             else if (event.type == sf::Event::KeyPressed) {
        //                 if (event.key.code == sf::Keyboard::Escape) {
        //                     if (currentState == GAME_PLAY) {
        //                         // Pause game or return to menu
        //                         std::cout << "Game paused" << std::endl;
        //                     }
        //                 }
        //             }
        //         }
                
        //         window.clear(sf::Color(30, 30, 80)); // Dark blue background
                
        //         // Draw based on current state
        //         switch (currentState) {
        //             case MAIN_MENU:
        //                 drawMainMenu();
        //                 break;
        //             case INSTRUCTIONS:
        //                 drawInstructions();
        //                 break;
        //             case SCORE_HISTORY:
        //                 drawScoreHistory();
        //                 break;
        //             case GAME_PLAY:
        //                 // Here you would call your game rendering
        //                 drawGame();
        //                 break;
        //         }
                
        //         window.display();
        //     }
        // }
        
        // void drawGame() {
        //     // This is where you would draw your actual game
        //     // For now, we'll show a placeholder
        //     sf::Text gameText;
        //     gameText.setFont(font);
        //     gameText.setString("GAME IN PROGRESS\n\nPress ESC to pause");
        //     gameText.setCharacterSize(30);
        //     gameText.setFillColor(sf::Color::White);
        //     gameText.setPosition(250, 250);
        //     window.draw(gameText);
        // }
    
        // Method to add score from game
        void addGameScore(int score);
};

#endif