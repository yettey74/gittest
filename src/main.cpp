#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
// #include <SFML\System.hpp>
// #include <SFML\Audio.hpp>
// #include <SFML\Network.hpp>
#include <iostream>

enum ScreenType { MAIN_MENU, GAME, OPTIONS };

class MainMenu {
public:
    MainMenu(float width, float height) {
    // Load a font
    sf::Font font;
    if (!font.loadFromFile("C:/windows/fonts/arial.ttf")) {
        // handle error - cannot load font
        return;
    }

        menu[0].setFont(font);
        menu[0].setFillColor(sf::Color::Red);
        menu[0].setString("Start Game");
        menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

        menu[1].setFont(font); 
        menu[1].setFillColor(sf::Color::White);
        menu[1].setString("Options");
        menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

        selectedItemIndex = 0;
    }

    void draw(sf::RenderWindow &window) {
        for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
            window.draw(menu[i]);
        }
    }

    void MoveUp() {
        if (selectedItemIndex - 1 >= 0) {
            menu[selectedItemIndex].setFillColor(sf::Color::White);
            selectedItemIndex--;
            menu[selectedItemIndex].setFillColor(sf::Color::Red);
        }
    }

    void MoveDown() {
        if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
            menu[selectedItemIndex].setFillColor(sf::Color::White);
            selectedItemIndex++;
            menu[selectedItemIndex].setFillColor(sf::Color::Red);
        }
    }

    int GetPressedItem() {
        return selectedItemIndex;
    }

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[2];

    static const int MAX_NUMBER_OF_ITEMS = 2;
};

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game");

    // Load a font from a specific path
    sf::Font font;
    if (!font.loadFromFile("C:/Path/To/Your/Font/arial.ttf")) {
        // Handle error - cannot load font
        return 1;
    }

    // Create a text object
    sf::Text text;
    text.setFont(font);
    text.setString("Hello SFML!");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(100.f, 50.f);

    // Game loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();

        // Draw the text
        window.draw(text);

        // Draw something (e.g., a circle)
        sf::CircleShape shape(50.f);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(100.f, 100.f);
        window.draw(shape);

        // Display what was drawn
        window.display();
    }

    return 0;
}