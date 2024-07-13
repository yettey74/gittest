#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "headers/OptionsScreen.h"
#include "headers/GameScreen.h"
#include "headers/AudioManager.h"
#include "headers/NetworkManager.h"
#include "headers/Time.h"

enum ScreenType { MAIN_MENU, GAME, OPTIONS };

class MainMenu {
public:

    MainMenu(float width, float height) {
        if (!font.loadFromFile("C:/windows/fonts/arial.ttf")) {
            std::cerr << "Error loading font\n";
            return;
        }

        menu[0].setFont(font);
        menu[0].setFillColor(sf::Color::Red);
        menu[0].setString("Start Game");
        menu[0].setPosition(sf::Vector2f(width / 2.0f, height / 3.0f));

        menu[1].setFont(font);
        menu[1].setFillColor(sf::Color::White);
        menu[1].setString("Options");
        menu[1].setPosition(sf::Vector2f(width / 2.0f, height / 2.0f));

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
        return -1;
    }

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[2];

    static const int MAX_NUMBER_OF_ITEMS = 2;
};

int main() {    

    Time gameClock;

    // Set the initial year and month
    // Set the initial year, month, and day
    // gameClock.setCurrentYear(-400);
    // gameClock.setCurrentMonth(1);   // Start from January
    // gameClock.setCurrentDay(1);     // Start from the first day of the month

    // Loop from the initial year, month, and day (400 BC, January, 1st) to the current year, month, and day
    for (int year = -400; year <= gameClock.getCurrentYear(); ++year) {
        for (int month = 1; month <= 12; ++month) {
            int daysInMonth = gameClock.getDaysInMonth(month);
            for (int day = 1; day <= daysInMonth; ++day) {
                std::cout << "Day: ";
                if (day < 10) {
                    std::cout << "0";  // Ensure two-digit format (e.g., 01, 02, ..., 31)
                }
                std::cout << day << " ";

                std::cout << "Month: ";
                if (month < 10) {
                    std::cout << "0";  // Ensure two-digit format (e.g., 01, 02, ..., 12)
                }
                std::cout << month << " ";
                
                std::cout << "Year: ";
                if (year < 0) {
                    std::cout << -year << " BC";
                } else {
                    std::cout << year;
                }
                std::cout << std::endl;

                // Advance the day in your game logic
                gameClock.advanceDay();
            }
            // Advance the month after printing all days in the month
            gameClock.advanceSeason();  // Assuming each season corresponds to 3 months
        }
        // Advance the year after printing all months in the year
        gameClock.advanceYear();
    
    return 0;
    }


    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game");

    MainMenu mainMenu(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y));
    OptionsScreen optionsScreen(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y));
    GameScreen gameScreen(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y));

    ScreenType currentScreen = MAIN_MENU;

    while (window.isOpen()) {
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
                            currentScreen = GAME;
                        } else if (selectedItem == 1) {
                            currentScreen = OPTIONS;
                        }
                    }
                } else if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        int selectedItem = mainMenu.getMenuItemIndexAtPosition(mousePos);
                        if (selectedItem == 0) {
                            currentScreen = GAME;
                        } else if (selectedItem == 1) {
                            currentScreen = OPTIONS;
                        }
                    }
                }
            } else if (currentScreen == GAME) {
                gameScreen.handleEvent(event, window);
                if (gameScreen.shouldReturnToMainMenu()) {
                    currentScreen = MAIN_MENU;
                    gameScreen.reset();
                }
            } else if (currentScreen == OPTIONS) {
                optionsScreen.handleEvent(event, window);
                if (optionsScreen.shouldReturnToMainMenu()) {
                    currentScreen = MAIN_MENU;
                    optionsScreen.reset();
                }
            }
        }

        window.clear();
        if (currentScreen == MAIN_MENU) {
            mainMenu.draw(window);
        } else if (currentScreen == OPTIONS) {
            optionsScreen.draw(window);
        } else if (currentScreen == GAME) {
            gameScreen.draw(window);
        }
        window.display();
    }

    return 0;
}
