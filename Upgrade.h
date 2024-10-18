#ifndef UPGRADE_H
#define UPGRADE_H

#include "Object.h"
#include "Player.h"

class Upgrade : public Object {
private:
    Player* player;
public:
    Upgrade(Player* player, sf::Shape* objectShape, sf::Vector2f originPosition);   // Constructor initializes the upgrade with shape and position
    virtual void apply(Player* player) = 0;                                         // Pure virtual function
    void update(float deltaTime);                                                                  // Checks for collision
};

#endif