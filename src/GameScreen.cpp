#include "headers/GameScreen.h"

GameScreen::GameScreen(float width, float height) {

    // Initialize game screen here, e.g., load font
    if (!font.loadFromFile("C:/windows/fonts/arial.ttf")) {
        std::cerr << "Error loading font\n";
        // Handle error
    }

    gameText.setFont(font);
    gameText.setString("Game Screen");
    gameText.setCharacterSize(24);
    gameText.setFillColor(sf::Color::White);
    gameText.setPosition(width / 2.0f - 100.0f, height / 2.0f);

    returnToMainMenu = false;
}

void GameScreen::draw(sf::RenderWindow &window) {
    window.clear();
    window.draw(gameText);
    window.display();
}

void GameScreen::handleEvent(const sf::Event &event, sf::RenderWindow &window) {
    // Handle events specific to the game screen
    // For example, detect if Escape key is pressed
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        returnToMainMenu = true;
    }
}

bool GameScreen::shouldReturnToMainMenu() const {
    return returnToMainMenu;
}

void GameScreen::reset() {
    returnToMainMenu = false;
}