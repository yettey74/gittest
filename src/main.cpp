#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "headers/OptionsScreen.h"  // Include the OptionsScreen header
#include "headers/GameScreen.h"  // Include the OptionsScreen header

enum ScreenType { MAIN_MENU, GAME, OPTIONS };

class MainMenu {
public:
    MainMenu(float width, float height) {
        // Load a font
        if (!font.loadFromFile("C:/windows/fonts/arial.ttf")) {
            // handle error - cannot load font
            std::cerr << "Error loading font\n";
            return;
        }

        menu[0].setFont(font);
        menu[0].setFillColor(sf::Color::Red);
        menu[0].setString("Start Game");
        menu[0].setPosition(sf::Vector2f(width / 2.0f, height / (MAX_NUMBER_OF_ITEMS + 1.0f) * 1.0f));

        menu[1].setFont(font);
        menu[1].setFillColor(sf::Color::White);
        menu[1].setString("Options");
        menu[1].setPosition(sf::Vector2f(width / 2.0f, height / (MAX_NUMBER_OF_ITEMS + 1.0f) * 2.0f));

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

    int getMenuItemIndexAtPosition(sf::Vector2i position) {
        for (int i = 0; i < MAX_NUMBER_OF_ITEMS; ++i) {
            if (menu[i].getGlobalBounds().contains(static_cast<float>(position.x), static_cast<float>(position.y))) {
                return i;
            }
        }
        return -1;  // No menu item at this position
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

    // Create the main menu and options screen
    MainMenu mainMenu(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y));
    OptionsScreen optionsScreen(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y));
    GameScreen gameScreen(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y));

    // Load and play the audio
    sf::Music music;
    if (!music.openFromFile("C:\\project\\cpp\\gittest\\src\\audio\\orchestral.mp3")) {
        std::cerr << "Error loading audio file\n";
        return -1;
    }
    music.setLoop(true);
    music.play();

    ScreenType currentScreen = MAIN_MENU;

    // Game loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (currentScreen == MAIN_MENU) {
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Up) {
                        mainMenu.MoveUp();
                    } else if (event.key.code == sf::Keyboard::Down) {
                        mainMenu.MoveDown();
                    } else if (event.key.code == sf::Keyboard::Enter) {
                        int selectedItem = mainMenu.GetPressedItem();
                        if (selectedItem == 0) {
                            //std::cout << "Start Game selected" << std::endl;
                            currentScreen = GAME;
                        } else if (selectedItem == 1) {
                            //std::cout << "Options selected" << std::endl;
                            currentScreen = OPTIONS;
                        }
                    }
                } else if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        int selectedItem = mainMenu.getMenuItemIndexAtPosition(mousePos);
                        if (selectedItem == 0) {
                            //std::cout << "Start Game selected" << std::endl;
                            currentScreen = GAME;
                        } else if (selectedItem == 1) {
                            //std::cout << "Options selected" << std::endl;
                            currentScreen = OPTIONS;
                        }
                    }
                }
            } 
        }

        // Clear the window
        window.clear();

        // Draw the appropriate screen
        if (currentScreen == MAIN_MENU) {
            mainMenu.draw(window);
        } else if (currentScreen == OPTIONS) {
            optionsScreen.draw(window);
        } else if (currentScreen == GAME ) {
            gameScreen.draw(window);
        }

        // Display what was drawn
        window.display();
    }

    return 0;
}
