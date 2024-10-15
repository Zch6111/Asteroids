// SpeedUpgrade.h
#ifndef SPEEDUPGRADE_H
#define SPEEDUPGRADE_H

#include "Upgrade.h"

class SpeedUpgrade : public Upgrade {
private:
    float speedIncrease;  // Amount to increase player's speed

public:
    // Constructor for SpeedUpgrade
    SpeedUpgrade(float increaseAmount);

    // Applies the speed increase to the player
    void applyToPlayer(Player& player) override;
};

#endif // SPEEDUPGRADE_H