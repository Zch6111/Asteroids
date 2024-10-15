// Upgrade.cpp
#include "Upgrade.h"

// Constructor for Upgrade, initializing with a shape and upgrade type
Upgrade::Upgrade(sf::RectangleShape* objectShape, UpgradeType upgradeType)
    : Object(objectShape), type(upgradeType) {}

// Handle collision with other objects
void Upgrade::onCollision(Object& other) {
    // If the upgrade collides with a Player
    if (Player* player = dynamic_cast<Player*>(&other)) {
        applyToPlayer(*player);  // Apply the upgrade effect to the player
        setActive(false);        // Deactivate the upgrade after being picked up
    }
    // If the upgrade collides with any other object, just deactivate it
    else {
        setActive(false);        // Deactivate the upgrade for any other collision
    }
}