#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

class Menu {
 private:
  sf::Font font;
  std::vector<sf::Text> menuItems;
  int selectedItem;

 public:
  Menu(float width, float height);
  void draw(sf::RenderWindow& window);
  void moveUp();
  void moveDown();
  int getSelectedItem();
};