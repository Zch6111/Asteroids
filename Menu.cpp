#include "Menu.h"

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
