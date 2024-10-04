#include "Menu.h"
Menu::Menu(float width, float height) {
  if (!font.loadFromFile("OpenSans-Bold.ttf")) {
    std::cerr << "Error font" << std::endl;
  }
  std::string items[] = {"Start", "Info", "Setting", "High Scores", "Exit"};
  for (int i = 0; i < 5; i++) {
    sf::Text text;
    text.setFont(font);
    text.setFillColor(i == 0 ? sf::Color::Red : sf::Color::White);
    text.setString(items[i]);
    text.setPosition(sf::Vector2f(width / 2.5, height / (5 + 1) * (i + 1)));
    menuItems.push_back(text);
  }
}
void Menu::draw(sf::RenderWindow& window) {
  for (int i = 0; i < menuItems.size(); i++) {
    window.draw(menuItems[i]);
  }
}
void Menu::moveUp() {
  if (selectedItem - 1 >= 0) {
    menuItems[selectedItem].setFillColor(sf::Color::White);
    selectedItem--;
    menuItems[selectedItem].setFillColor(sf::Color::Red);
  }
}
void Menu::moveDown() {
  if (selectedItem + 1 < menuItems.size()) {
    menuItems[selectedItem].setFillColor(sf::Color::White);
    selectedItem++;
    menuItems[selectedItem].setFillColor(sf::Color::Red);
  }
}
int Menu::getSelectedItem() { return selectedItem; }
