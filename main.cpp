#include <SFML/Graphics.hpp>

#include "Menu.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Menu");
  Menu menu(800, 600);

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
          menu.moveUp();
        }
        if (event.key.code == sf::Keyboard::Down) {
          menu.moveDown();
        }
        if (event.key.code == sf::Keyboard::Return) {
          int selectedItem = menu.getSelectedItem();
          if (selectedItem == 0) {
            std::cout << "Starting Game..." << std::endl;
          } else if (selectedItem == 1) {
            std::cout << "Info..." << std::endl;
          } else if (selectedItem == 2) {
            std::cout << "Setting..." << std::endl;
          } else if (selectedItem == 3) {
            std::cout << "High Scores..." << std::endl;
          } else if (selectedItem == 4) {
            window.close();
          }
        }
      }
    }
    window.clear(sf::Color::Black);
    menu.draw(window);
    window.display();
  }
  return 0;
}