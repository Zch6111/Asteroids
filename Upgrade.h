
#ifndef UPGRADE_H
#define UPGRADE_H

#include "Player.h"
#include "Object.h"
#include "UpgradeType.h"
#include <SFML/Graphics.hpp>

class Upgrade : public Object {
private:
    UpgradeType type;  // Stores the type of the upgrade

public:
    // Constructor for upgrades, using the Object constructor to pass shape and other attributes
    Upgrade(sf::RectangleShape* objectShape, UpgradeType upgradeType) 
        : Object(objectShape), type(upgradeType) {}

    // Abstract function to apply an upgrade to the player
    virtual void applyToPlayer(Player& player) = 0;

    // Get the type of the upgrade
    UpgradeType getType() const {
        return type;
    }

    // Handle collision with other objects
    void onCollision(Object& other) override;

    virtual ~Upgrade() = default;
};

#endif