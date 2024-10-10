#include "LivesUpgrade.h"

// Constructor creates a red square for LivesUpgrade
LivesUpgrade::LivesUpgrade() : Upgrade(new sf::RectangleShape(sf::Vector2f(20.f, 20.f))) {
    
    // Set the color to red for lives upgrade
    sf::RectangleShape* shape = dynamic_cast<sf::RectangleShape*>(getShape());
    if (shape) {
        shape->setFillColor(sf::Color::Red);
    }
}

// Applies the life increase to the player
void LivesUpgrade::applyToPlayer(Player& player) {
    int currentLives = player.getLives();  // Get current player lives
    player.setLives(currentLives + 1);  // Increase the player's lives
}