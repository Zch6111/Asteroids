// LivesUpgrade.cpp
#include "LivesUpgrade.h"

// Constructor creates a blue square for LivesUpgrade
LivesUpgrade::LivesUpgrade() 
    : Upgrade(new sf::RectangleShape(sf::Vector2f(20.f, 20.f)), UpgradeType::LivesUpgrade) {
    sf::RectangleShape* shape = dynamic_cast<sf::RectangleShape*>(getShape());
    if (shape) {
        shape->setFillColor(sf::Color::Blue); // Set the color to blue for lives upgrade
    }
}

// Applies the life increase to the player
void LivesUpgrade::applyToPlayer(Player& player) {
    player.setLives(player.getLives() + 1); // Increase player's lives by 1
}