#ifndef OPTIONSSCREEN_H
#define OPTIONSSCREEN_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class OptionsScreen {
public:
    OptionsScreen(float width, float height);
    void draw(sf::RenderWindow &window);
    void handleEvent(const sf::Event &event, sf::RenderWindow &window);
    bool shouldReturnToMainMenu() const; // Getter for returnToMainMenu flag
    void reset(); // Reset screen-specific state

private:
    sf::Font font;
    sf::Text optionsText;
    bool returnToMainMenu = false; // Flag to indicate if we should return to main menu
};

#endif // OPTIONSSCREEN_H