#include "../headers/GameScreen.h"

GameScreen::GameScreen(float width, float height) {
    // Load a font
    if (!font.loadFromFile("C:/windows/fonts/arial.ttf")) {
        // handle error - cannot load font
        std::cerr << "Error loading font\n";
        return;
    }

    // Create the options text
    gameText.setFont(font);
    gameText.setFillColor(sf::Color::White);
    gameText.setString("Game Screen\nPress Escape to return");
    gameText.setPosition(sf::Vector2f(width / 4.0f, height / 4.0f));
}

void GameScreen::draw(sf::RenderWindow &window) {
    window.draw(gameText);
}

void GameScreen::handleEvent(const sf::Event &event, sf::RenderWindow &window) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        // Close the window or return to main menu
        window.close();
    }
}
