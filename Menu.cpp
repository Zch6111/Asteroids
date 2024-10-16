#include "Menu.h"
#include "Object.h"
#include "Player.h"

Menu::Menu(float width, float height) {
  // Load the font for rendering the menu text
  if (!font.loadFromFile("OpenSans-Bold.ttf")) {
    std::cerr << "Error font" << std::endl;
  }

  // Define the menu item labels
  std::string items[] = {"Start", "Info", "Setting", "High Scores", "Exit"};

  // Create and configure the menu items (5 items in total)
  for (int i = 0; i < 5; i++) {
    sf::Text text;
    text.setFont(font);

    // Highlight the first item in red, others in white
    text.setFillColor(i == 0 ? sf::Color::Red : sf::Color::White);

    // Set the text content of each menu item
    text.setString(items[i]);

    // Position each menu item vertically, with a fixed space between them
    text.setPosition(sf::Vector2f(width / 2.5, height / (5 + 1) * (i + 1)));

    // Add the configured item to the menuItems list
    menuItems.push_back(text);
  }

  // Start with the first item selected
  selectedItem = 0;
}

// Draws all the menu items on the window
void Menu::draw(sf::RenderWindow& window) {
  for (int i = 0; i < menuItems.size(); i++) {
    window.draw(menuItems[i]);  // Render each menu item
  }
}

// Moves the selection up in the menu
void Menu::moveUp() {
  if (selectedItem - 1 >= 0) {
    menuItems[selectedItem].setFillColor(
        sf::Color::White);  // Reset previous item color
    selectedItem--;         // Move selection up
    menuItems[selectedItem].setFillColor(
        sf::Color::Red);  // Highlight the new item
  }
}

// Moves the selection down in the menu
void Menu::moveDown() {
  if (selectedItem + 1 < menuItems.size()) {
    menuItems[selectedItem].setFillColor(
        sf::Color::White);  // Reset previous item color
    selectedItem++;         // Move selection down
    menuItems[selectedItem].setFillColor(
        sf::Color::Red);  // Highlight the new item
  }
}

// Returns the index of the currently selected menu item
int Menu::getSelectedItem() { return selectedItem; }

// run function which can run the menu
void Menu::run(sf::RenderWindow& window, HighScores& highScores, Player& player) {
  GameState state = MAIN_MENU;
  sf::Clock clock;
  while (window.isOpen()) {
    sf::Event event;
    
    
    if (state == MAIN_MENU) {
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
          if (event.key.code == sf::Keyboard::Up) {
            moveUp();
          }
          if (event.key.code == sf::Keyboard::Down) {
            moveDown();
          }
          if (event.key.code == sf::Keyboard::Return) {
            int selectedItem = getSelectedItem();
            if (selectedItem == 0) {
              state = GAME;
            } else if (selectedItem == 1) {
              std::cout << "Info..." << std::endl;
            } else if (selectedItem == 2) {
              std::cout << "Settings..." << std::endl;
            } else if (selectedItem == 3) {
              state = HIGH_SCORES;
            } else if (selectedItem == 4) {
              state = EXIT;
            }
          }
        }
      }
      window.clear(sf::Color::Black);
      draw(window);
      window.display();

    } else if (state == HIGH_SCORES) {
      // logic of high scores
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          window.close();
        }
        if (event.type == sf::Event::KeyPressed &&
            event.key.code == sf::Keyboard::C) {
          highScores.clear();
        }
        if (event.type == sf::Event::KeyPressed &&
            event.key.code == sf::Keyboard::Escape) {
          state = MAIN_MENU;
        }
      }
      // draw the high scores
      window.clear(sf::Color::Black);
      highScores.draw(window);
      window.display();

    } else if (state == EXIT) {
      window.close();
    } else if (state == GAME){
        sf::Time elapsed = clock.restart();
        float deltaTime = 60 * elapsed.asSeconds();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            
            // player movement
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                state = MAIN_MENU;

            // player movement
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                player.moveFoward();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                player.moveBackward();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                player.turnLeft();
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                player.turnRight();
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                player.fire();
        }

        // check for user input
        
        // update game
        player.update(deltaTime);
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(*(player.getShape()));
        // end the current frame
        window.display();
        
    }
  }
}