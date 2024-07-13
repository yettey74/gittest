#include "headers/OptionsScreen.h"

OptionsScreen::OptionsScreen(float width, float height) {
    if (!font.loadFromFile("C:/windows/fonts/arial.ttf")) {
        std::cerr << "Error loading font\n";
    }

    optionsText.setFont(font);
    optionsText.setString("Options Screen");
    optionsText.setCharacterSize(24);
    optionsText.setFillColor(sf::Color::White);
    optionsText.setPosition(width / 2.0f - 100.0f, height / 2.0f);

    returnToMainMenu = false;
}

void OptionsScreen::draw(sf::RenderWindow &window) {
    window.draw(optionsText);
}

void OptionsScreen::handleEvent(const sf::Event &event, sf::RenderWindow &window) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        returnToMainMenu = true;
    }
}

bool OptionsScreen::shouldReturnToMainMenu() const {
    return returnToMainMenu;
}

void OptionsScreen::reset() {
    returnToMainMenu = false;
}
