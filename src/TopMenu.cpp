#include "TopMenu.h"

TopMenu::TopMenu(float width, float height) {
    // Load font
    if (!font.loadFromFile("C:/windows/fonts/arial.ttf")) {
        std::cerr << "Error loading font\n";
        return;
    }

    // Set up menu items
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::White);
    menu[0].setString("Menu Item 1");
    menu[0].setPosition(sf::Vector2f(width / 2.0f - 100.0f, 10.0f));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Menu Item 2");
    menu[1].setPosition(sf::Vector2f(width / 2.0f, 10.0f));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Menu Item 3");
    menu[2].setPosition(sf::Vector2f(width / 2.0f + 100.0f, 10.0f));

    selectedItemIndex = 0;
}

void TopMenu::draw(sf::RenderWindow &window) {
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
        window.draw(menu[i]);
    }
}

void TopMenu::setItemSelected(int index) {
    if (index >= 0 && index < MAX_NUMBER_OF_ITEMS) {
        for (int i = 0; i < MAX_NUMBER_OF_ITEMS; ++i) {
            menu[i].setFillColor(sf::Color::White);
        }
        selectedItemIndex = index;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

int TopMenu::getSelectedItem() const {
    return selectedItemIndex;
}

void TopMenu::handleEvent(sf::Event event, sf::RenderWindow &window) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left) {
            if (selectedItemIndex > 0) {
                setItemSelected(selectedItemIndex - 1);
            }
        } else if (event.key.code == sf::Keyboard::Right) {
            if (selectedItemIndex < MAX_NUMBER_OF_ITEMS - 1) {
                setItemSelected(selectedItemIndex + 1);
            }
        }
    }
}

