// FireSpeedUpgrade.cpp
#include "FireSpeedUpgrade.h"

// Constructor creates an orange square for FireSpeedUpgrade
FireSpeedUpgrade::FireSpeedUpgrade(float increaseAmount) 
    : Upgrade(new sf::RectangleShape(sf::Vector2f(20.f, 20.f)), UpgradeType::FireRateUpgrade), fireRateIncrease(increaseAmount) {
    sf::RectangleShape* shape = dynamic_cast<sf::RectangleShape*>(getShape());
    if (shape) {
        shape->setFillColor(sf::Color::Blue); // Set the color to orange for fire speed upgrade
    }
}

// Applies the fire speed increase to the player
void FireSpeedUpgrade::applyToPlayer(Player& player) {
    player.setFireRate(player.getFireRate() - fireRateIncrease); // Decrease cooldown, increasing fire rate
}