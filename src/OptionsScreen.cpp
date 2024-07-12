#include <headers/OptionsScreen.h>

OptionsScreen::OptionsScreen(float width, float height) {

    // Initialize options screen here, e.g., load font
    if (!font.loadFromFile("C:/windows/fonts/arial.ttf")) {
        std::cerr << "Error loading font\n";
        // Handle error
    }

    optionsText.setFont(font);
    optionsText.setString("Options Screen");
    optionsText.setCharacterSize(24);
    optionsText.setFillColor(sf::Color::White);
    optionsText.setPosition(width / 2.0f - 100.0f, height / 2.0f);

    returnToMainMenu = false;
}

void OptionsScreen::draw(sf::RenderWindow &window) {
    window.clear();
    window.draw(optionsText);
    window.display();
}

void OptionsScreen::handleEvent(const sf::Event &event, sf::RenderWindow &window) {
    // Handle events specific to the options screen
    // For example, detect if Escape key is pressed
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