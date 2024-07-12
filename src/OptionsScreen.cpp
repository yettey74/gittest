#include "../headers/OptionsScreen.h"

OptionsScreen::OptionsScreen(float width, float height) {
    topMenu(width, height) {
    // Additional initialization if needed
}
    // Initialize game screen
    if (!font.loadFromFile("C:/windows/fonts/arial.ttf")) {
        // handle error - cannot load font
        std::cerr << "Error loading font\n";
        return;
    }

    optionsText.setFont(font);
    optionsText.setFillColor(sf::Color::Green);
    optionsText.setString("Options Screen");
    optionsText.setCharacterSize(24);
    optionsText.setPosition(width / 2.0f, height / 2.0f);
}

void OptionsScreen::handleEvent(const sf::Event &event, sf::RenderWindow &window) {
    // Handle events specific to the game screen
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        returnToMainMenu = true; // Set flag to return to main menu
    }
     topMenu.handleEvent(event, window);
}

void OptionsScreen::draw(sf::RenderWindow &window) {
    // Draw game screen content
    window.draw(optionsText);
    topMenu.draw(window);
}

bool OptionsScreen::shouldReturnToMainMenu() const {
    return returnToMainMenu;
}

void OptionsScreen::reset() {
    returnToMainMenu = false;
    // Reset any other screen-specific state if needed
}