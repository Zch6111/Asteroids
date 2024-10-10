#ifndef UPGRADE_H
#define UPGRADE_H

#include "Player.h"
#include "Object.h"
#include <SFML/Graphics.hpp>

class Upgrade : public Object {
public:
    // Constructor for upgrades, using the Object constructor to pass shape and other attributes
    Upgrade(sf::RectangleShape* objectShape);

    // Abstract function to apply an upgrade to the player
    virtual void applyToPlayer(Player& player) = 0;

    virtual ~Upgrade() = default;
};

#endif