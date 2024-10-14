#include <SFML/Graphics.hpp>

#include "HighScores.h"
#include "Menu.h"

// Define the different states of the game
enum GameState { MAIN_MENU, HIGH_SCORES, EXIT };

int main() {
  // Create an SFML window with 800x600 resolution
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Menu");

  // Create a Menu object with the same width and height as the window
  Menu menu(800, 600);

  // Create a HighScores object with a file to store the scores
  HighScores highScores("high_scores.txt");

  // Start with the main menu
  GameState state = MAIN_MENU;

  // Main loop: runs while the window is open
  while (window.isOpen()) {
    sf::Event event;

    if (state == MAIN_MENU) {
      // Event polling loop: checks for user input and window events
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
              // Add a new high score for demo purposes
              highScores.addScore("Player1", rand() % 1000);  // Random score
            } else if (selectedItem == 1) {
              std::cout << "Info..." << std::endl;
            } else if (selectedItem == 2) {
              std::cout << "Settings..." << std::endl;
            } else if (selectedItem == 3) {
              // Switch to the high scores state
              state = HIGH_SCORES;
            } else if (selectedItem == 4) {
              // Exit the game
              state = EXIT;
            }
          }
        }
      }

      // Draw the main menu
      window.clear(sf::Color::Black);
      menu.draw(window);
      window.display();

    } else if (state == HIGH_SCORES) {
      // Handle events while in the high scores state
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          window.close();
        }

        // Press ESC to go back to the main menu
        if (event.type == sf::Event::KeyPressed &&
            event.key.code == sf::Keyboard::Escape) {
          state = MAIN_MENU;
        }
      }

      // Draw the high scores page
      window.clear(sf::Color::Black);
      highScores.draw(window);  // Draw the high scores
      window.display();

    } else if (state == EXIT) {
      // Exit the game
      window.close();
    }
  }

  return 0;
}
