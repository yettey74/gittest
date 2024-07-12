#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class GameScreen {
public:
    GameScreen(float width, float height);
    void draw(sf::RenderWindow &window);
    void handleEvent(const sf::Event &event, sf::RenderWindow &window);

private:
    sf::Font font;
    sf::Text gameText;
};

#endif // GAMESCREEN_H