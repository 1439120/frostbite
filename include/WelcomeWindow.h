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
    SCORE_HISTORY,
    PAUSED,
    GAME_OVER,
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
        // game over
        std::optional<sf::Text> gameOverTitle;
        std::optional<sf::Text> finalScoreText;
        std::optional<sf::Text> highScoreText;
        std::vector<MenuItem> gameOverItems;
        void setupGameOverMenu();

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
        void drawGamePaused(sf::RenderWindow *window);
        void drawGame(sf::RenderWindow *window);
        void drawGameOver(int score, int highScor, sf::RenderWindow *window);
    
        // Method to add score from game
        void addGameScore(int score);
};

#endif