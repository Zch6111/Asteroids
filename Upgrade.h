#ifndef UPGRADE_H
#define UPGRADE_H

#include "Object.h"

class Player;

class Upgrade : public Object {
public:
    Upgrade(sf::Vector2f position);
    virtual void applyToPlayer(Player& player) = 0;
};

#endif