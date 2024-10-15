#ifndef UPGRADE_H
#define UPGRADE_H

#include "Object.h"
#include <SFML/Graphics.hpp>

class Player;

class Upgrade : public Object {
public:
    Upgrade(sf::Vector2f position); // Constructor to initialize the upgrade
    virtual void applyToPlayer(Player& player) = 0; // Pure virtual function for applying upgrades
};

#endif