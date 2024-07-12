#include "../headers/GameScreen.h"

GameScreen::GameScreen(float width, float height) {
    : topMenu(width, height) {
    // Additional initialization if needed
    }
    // Initialize game screen
    if (!font.loadFromFile("C:/windows/fonts/arial.ttf")) {
        // handle error - cannot load font
        std::cerr << "Error loading font\n";
        return;
    }

    gameText.setFont(font);
    gameText.setFillColor(sf::Color::Red);
    gameText.setString("Game Screen");
    gameText.setCharacterSize(24);
    gameText.setPosition(width / 2.0f, height / 2.0f);
}

void GameScreen::handleEvent(const sf::Event &event, sf::RenderWindow &window) {
    // Handle events specific to the game screen
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        returnToMainMenu = true; // Set flag to return to main menu
    }
    // Handle top menu events
    topMenu.handleEvent(event, window);
}

void GameScreen::draw(sf::RenderWindow &window) {
    // Draw game screen content
    window.draw(gameText);
    topMenu.draw(window);
}

bool GameScreen::shouldReturnToMainMenu() const {
    return returnToMainMenu;
}

void GameScreen::reset() {
    returnToMainMenu = false;
    // Reset any other screen-specific state if needed
}
