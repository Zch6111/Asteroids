#ifndef UPGRADE_H
#define UPGRADE_H

#include "Object.h"
#include "Player.h"

class Upgrade : public Object {
public:
    Upgrade(sf::Shape* objectShape, sf::Vector2f originPosition);
    virtual void apply(Player& player) = 0; // Pure virtual function
};

#endif