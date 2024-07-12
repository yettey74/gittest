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

private:
    sf::Font font;
    sf::Text optionsText;
};

#endif // OPTIONSSCREEN_H
