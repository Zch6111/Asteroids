#include "FireSpeedUpgrade.h"

// Constructor creates a blue square for FireSpeedUpgrade
FireSpeedUpgrade::FireSpeedUpgrade(float increaseAmount)
    : Upgrade(new sf::RectangleShape(sf::Vector2f(20.f, 20.f))), fireRateIncrease(increaseAmount) {
    
    // Set the color to blue for fire speed upgrade
    sf::RectangleShape* shape = dynamic_cast<sf::RectangleShape*>(getShape());
    if (shape) {
        shape->setFillColor(sf::Color::Blue);
    }
}

// Applies the fire rate increase to the player
void FireSpeedUpgrade::applyToPlayer(Player& player) {
    float currentFireRate = player.getFireRate();  // Get current player fire rate
    player.setFireRate(currentFireRate - fireRateIncrease);  // Decrease cooldown, increasing fire rate
}