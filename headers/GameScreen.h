#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "TopMenu.h"

class GameScreen {
public:
    GameScreen(float width, float height);

    void draw(sf::RenderWindow &window);
    void handleEvent(const sf::Event &event, sf::RenderWindow &window);

private:
    sf::Font font;
    sf::Text gameText;
    bool returnToMainMenu = false; // Flag to indicate if we should return to main menu
    TopMenu topMenu;

public:
    bool shouldReturnToMainMenu() const; // Getter for returnToMainMenu flag
    void reset(); // Reset screen-specific state
};

#endif // GAMESCREEN_H