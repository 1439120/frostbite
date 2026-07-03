#include "WelcomeWindow.h"

WelcomeWindow::WelcomeWindow() : currentState(MAIN_MENU) {
    if (!font.openFromFile("res/fonts/arial.ttf")) {
        // Fallback to default font if arial.ttf not found
        // You can download a font or use system font
        throw "Error loading font!";
    }
    
    loadScores();
    setupMenu();
    setupScoreHistory();
}

void WelcomeWindow::setupMenu() {
    // Title
    titleText.emplace(font, "FROSTBITE");
    titleText->setCharacterSize(60);
    titleText->setFillColor(sf::Color::Cyan);
    titleText->setStyle(sf::Text::Bold);
    titleText->setPosition(sf::Vector2f(300, 50));
    
    // Menu items
    std::vector<std::string> menuLabels = {
        "Start Game",
        "Instructions",
        "Score History",
        "Exit"
    };
    
    float yPos = 200;
    for (const auto& label : menuLabels) {
        MenuItem item;
        item.text.emplace(font, label);
        // item.text.setFont(font);
        // item.text.setString(label);
        item.text->setCharacterSize(30);
        item.text->setFillColor(sf::Color::White);
        item.text->setPosition(sf::Vector2f(350, yPos));
        item.bounds = item.text->getGlobalBounds();
        item.isHovered = false;
        menuItems.push_back(item);
        yPos += 60;
    }
}

void WelcomeWindow::setupScoreHistory() {
    scoreHistoryText.emplace(font);
    scoreHistoryText->setCharacterSize(24);
    scoreHistoryText->setFillColor(sf::Color::White);
    scoreHistoryText->setPosition(sf::Vector2f(200, 150));
    
    backButtonText.emplace(font);
    backButtonText->setString("Back to Menu");
    backButtonText->setCharacterSize(30);
    backButtonText->setFillColor(sf::Color::White);
    backButtonText->setPosition(sf::Vector2f(320, 500));
    backButtonBounds = backButtonText->getGlobalBounds();
}

void WelcomeWindow::loadScores() {
    scores.clear();
    std::ifstream file("data/scores.txt");
    if (file.is_open()) {
        int score;
        while (file >> score) {
            scores.push_back(score);
        }
        file.close();
    }
    // Sort scores in descending order
    std::sort(scores.begin(), scores.end(), std::greater<int>());
}

void WelcomeWindow::saveScore(int score) {
    scores.push_back(score);
    std::sort(scores.begin(), scores.end(), std::greater<int>());

    std::ofstream file("scores.txt");
    if (file.is_open()) {
        for (int s : scores) {
            file << s << std::endl;
        }
        file.close();
    }
}

void WelcomeWindow::updateScoreHistory() {
    std::string historyText = "=== SCORE HISTORY ===\n\n";
    if (scores.empty()) {
        historyText += "No scores recorded yet!\n";
    } else {
        for (size_t i = 0; i < scores.size() && i < 10; i++) {
            historyText += std::to_string(i + 1) + ". " + 
                        std::to_string(scores[i]) + " points\n";
        }
        if (scores.size() > 10) {
            historyText += "\n... and " + 
                        std::to_string(scores.size() - 10) + " more";
        }
    }
    scoreHistoryText->setString(historyText);
}

GameState WelcomeWindow::handleMouseClick(int mouseX, int mouseY, sf::RenderWindow *window) {
    sf::Vector2f mousePos(static_cast<float>(mouseX), static_cast<float>(mouseY));
    if (currentState == MAIN_MENU) {
        // Check each menu item
        for (size_t i = 0; i < menuItems.size(); i++) {
            if (menuItems[i].bounds.contains(mousePos)) {
                switch (i) {
                    case 0: // Start Game
                        currentState = GAME_PLAY;
                        // std::cout << "Starting game..." << std::endl;
                        // Initialize game
                        break;
                    case 1: // Instructions
                        currentState = INSTRUCTIONS;
                        break;
                    case 2: // Score History
                        currentState = SCORE_HISTORY;
                        updateScoreHistory();
                        break;
                    case 3: // Exit
                        window->close();
                        break;
                }
                break;
            }
        }
    } else if (currentState == SCORE_HISTORY || 
                currentState == INSTRUCTIONS) {
        if (backButtonBounds.contains(mousePos)) {
            currentState = MAIN_MENU;
        }
    }
    return currentState;
}

void WelcomeWindow::handleMouseMove(int mouseX, int mouseY) {
    sf::Vector2f mousePos(static_cast<float>(mouseX), static_cast<float>(mouseY));
    
    // Update hover states for menu items
    for (auto& item : menuItems) {
        item.isHovered = item.bounds.contains(mousePos);
        item.text->setFillColor(item.isHovered ? sf::Color::Yellow : sf::Color::White);
    }
    
    // Update back button hover
    if (currentState == SCORE_HISTORY || currentState == INSTRUCTIONS) {
        backButtonText->setFillColor(backButtonBounds.contains(mousePos) ? 
                                sf::Color::Yellow : sf::Color::White);
    }
}

void WelcomeWindow::drawMainMenu(sf::RenderWindow *window) {
    if (titleText.has_value()) {
        window->draw(*titleText);
    }
    for (const auto& item : menuItems) {
         if (item.text.has_value()) {
            window->draw(*item.text);
        }
    }
}

void WelcomeWindow::drawInstructions(sf::RenderWindow *window) {
    sf::Text instructionsText = sf::Text(font);
    // instructionsText.setFont(font);
    instructionsText.setString(
        "=== INSTRUCTIONS ===\n\n"
        "Welcome to Frostbite!\n\n"
        "Objective:\n"
        "Survive as long as possible in the frozen tundra\n\n"
        "Controls:\n"
        "Arrow Keys - Move your character\n"
        "Space - Jump/Action\n"
        "ESC - Pause game\n\n"
        "Tips:\n"
        "• Collect ice crystals for points\n"
        "• Avoid falling into freezing water\n"
        "• Stay warm by finding shelters\n"
        "• Score increases with survival time"
    );
    instructionsText.setCharacterSize(20);
    instructionsText.setFillColor(sf::Color::White);
    instructionsText.setPosition(sf::Vector2f(150, 100));
    
    window->draw(instructionsText);
    window->draw(*backButtonText);
}

void WelcomeWindow::drawScoreHistory(sf::RenderWindow *window) {
    window->draw(*scoreHistoryText);
    window->draw(*backButtonText);
}

void WelcomeWindow::addGameScore(int score) {
    saveScore(score);
}

void WelcomeWindow::drawGame(sf::RenderWindow *window) {
    // This is where you would draw your actual game
    // For now, we'll show a placeholder
    sf::Text gameText = sf::Text(font);
    gameText.setFont(font);
    gameText.setString("GAME IN PROGRESS\n\nPress ESC to pause");
    gameText.setCharacterSize(30);
    gameText.setFillColor(sf::Color::White);
    gameText.setPosition(sf::Vector2f(250, 250));
    window->draw(gameText);
}

void WelcomeWindow::drawGamePaused(sf::RenderWindow *window) {
    sf::Text gamePaused = sf::Text(font);
    gamePaused.setString(
        "\n\n    === Game Paused ===\n\n"
    );
    gamePaused.setCharacterSize(20);
    gamePaused.setFillColor(sf::Color::White);
    gamePaused.setPosition(sf::Vector2f(300, 100));
    
    window->draw(gamePaused);
    window->draw(*backButtonText);
}