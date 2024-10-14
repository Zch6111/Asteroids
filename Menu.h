#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

class Menu {
 private:
  sf::Font font;                    // Font used for rendering menu text
  std::vector<sf::Text> menuItems;  // List of menu items (Start, Info, etc.)
  int selectedItem;                 // Index of the currently selected item

 public:
  // Constructor: Initializes the menu with given window width and height
  Menu(float width, float height);

  // Draws the menu items on the provided SFML window
  void draw(sf::RenderWindow& window);

  // Moves selection up in the menu (wrapping at the top)
  void moveUp();

  // Moves selection down in the menu (wrapping at the bottom)
  void moveDown();

  // Returns the index of the currently selected menu item
  int getSelectedItem();
};
