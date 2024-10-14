#include <SFML/Graphics.hpp>

#include "Menu.h"

int main() {
  // Create an SFML window with 800x600 resolution
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Menu");

  // Create a Menu object with the same width and height as the window
  Menu menu(800, 600);

  // Main loop: runs while the window is open
  while (window.isOpen()) {
    sf::Event event;

    // Event polling loop: checks for user input and window events
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        // Close the window if the "close" event is triggered
        window.close();
      }
      if (event.type == sf::Event::KeyPressed) {
        // Handle up and down arrow key inputs to navigate the menu
        if (event.key.code == sf::Keyboard::Up) {
          menu.moveUp();
        }
        if (event.key.code == sf::Keyboard::Down) {
          menu.moveDown();
        }
        if (event.key.code == sf::Keyboard::Return) {
          // Perform action based on the selected menu item
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
            // Exit the application if "Exit" is selected
            window.close();
          }
        }
      }
    }

    // Clear the window to a black background before drawing new content
    window.clear(sf::Color::Black);

    // Draw the menu on the window
    menu.draw(window);

    // Display the current frame
    window.display();
  }

  return 0;
}
