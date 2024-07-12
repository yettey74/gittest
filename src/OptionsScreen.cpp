#include "OptionsScreen.h"

OptionsScreen::OptionsScreen(float width, float height) {
    // Load a font
    if (!font.loadFromFile("C:/windows/fonts/arial.ttf")) {
        // handle error - cannot load font
        std::cerr << "Error loading font\n";
        return;
    }

    // Create the options text
    optionsText.setFont(font);
    optionsText.setFillColor(sf::Color::White);
    optionsText.setString("Options Screen\nPress Escape to return");
    optionsText.setPosition(sf::Vector2f(width / 4.0f, height / 4.0f));
}

void OptionsScreen::draw(sf::RenderWindow &window) {
    window.draw(optionsText);
}

void OptionsScreen::handleEvent(const sf::Event &event, sf::RenderWindow &window) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        // Close the window or return to main menu
        window.close();
    }
}
