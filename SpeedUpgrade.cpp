// SpeedUpgrade.cpp
#include "SpeedUpgrade.h"

// Constructor creates a purple square for SpeedUpgrade
SpeedUpgrade::SpeedUpgrade(float increaseAmount) 
    : Upgrade(new sf::RectangleShape(sf::Vector2f(20.f, 20.f)), UpgradeType::SpeedUpgrade), speedIncrease(increaseAmount) {
    sf::RectangleShape* shape = dynamic_cast<sf::RectangleShape*>(getShape());
    if (shape) {
        shape->setFillColor(sf::Color::Blue); // Set the color to purple for speed upgrade
    }
}

// Applies the speed increase to the player
void SpeedUpgrade::applyToPlayer(Player& player) {
    player.setMaxVelocity(player.getMaxVelocity() + speedIncrease); // Increase player's max velocity
}