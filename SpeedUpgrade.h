#ifndef SPEEDUPGRADE_H
#define SPEEDUPGRADE_H

#include "Upgrade.h"

class SpeedUpgrade : public Upgrade {
private:
    float maxVelocityIncrease;      // how much max velocity increases by
    float accelerationIncrease;     // how much acceleration increases by
    float decelerationMultiplier;   // how much deceleration is multiplied by
public:
    // Constructor to initialize position and speed increase amount
    SpeedUpgrade(Player* player, sf::Vector2f originPosition, float maxVelocityIncrease, float accelerationIncrease, float decelerationMultiplier);
    void apply(Player* player) override;//Applies the speed upgrade to the player
};


#endif