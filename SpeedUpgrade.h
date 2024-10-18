#ifndef SPEEDUPGRADE_H
#define SPEEDUPGRADE_H

#include "Upgrade.h"

class SpeedUpgrade : public Upgrade {
private:
    const float maxVelocityIncrease = 10.f;         // how much max velocity increases by
    const float accelerationIncrease = 0.2f;        // how much acceleration increases by
    const float decelerationMultiplier = 0.5f;      // how much deceleration is multiplied by
public:
    // Constructor to initialize position and speed increase amount
    SpeedUpgrade(Player* player, sf::Vector2f originPosition);
    void apply(Player* player) override;//Applies the speed upgrade to the player
};


#endif