#include "SpeedUpgrade.h"
#include"Player.h"
#include"Object.h"

// Constructor creates a green square for SpeedUpgrade
SpeedUpgrade::SpeedUpgrade(float increaseAmount)
    : Upgrade(new sf::RectangleShape(sf::Vector2f(20.f, 20.f))), speedIncrease(increaseAmount) {
    
    // Set the color to green for speed upgrade
    sf::RectangleShape* shape = dynamic_cast<sf::RectangleShape*>(getShape());
    if (shape) {
        shape->setFillColor(sf::Color::Green);
    }
}

// Applies the speed increase to the player
void SpeedUpgrade::applyToPlayer(Player& player) {
    float currentSpeed = player.getSpeed();   // Get current player speed
    player.setSpeed(currentSpeed + speedIncrease);  // Increase the player's speed
}