#ifndef FIRESPEEDUPGRADE_H
#define FIRESPEEDUPGRADE_H

#include "Upgrade.h"

class FireSpeedUpgrade : public Upgrade {
private:
    float fireRateIncrease;  // Amount to increase the player's fire speed

public:
    // Constructor for FireSpeedUpgrade
    FireSpeedUpgrade(float increaseAmount);

    // Applies the fire speed increase to the player
    void applyToPlayer(Player& player) override;
};

#endif