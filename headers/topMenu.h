#ifndef TOPMENU_H
#define TOPMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

class TopMenu {
public:
    TopMenu(float width, float height);

    void draw(sf::RenderWindow &window);
    void setItemSelected(int index);
    int getSelectedItem() const;

    void handleEvent(sf::Event event, sf::RenderWindow &window);

private:
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

    int selectedItemIndex;

    static const int MAX_NUMBER_OF_ITEMS = 3; // Adjust as needed
};

#endif // TOPMENU_H
