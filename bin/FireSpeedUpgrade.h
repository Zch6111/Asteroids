#ifndef FIRESPEEDUPGRADE_H
#define FIRESPEEDUPGRADE_H

#include "Upgrade.h"
#include "Player.h"

class FireSpeedUpgrade : public Upgrade {
private:
    float fireRateIncrease;  

public:
    // 
    FireSpeedUpgrade(float increaseAmount);

    // 
    void applyToPlayer(Player& player) override;
};

#endif