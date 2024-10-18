#ifndef FIRESPEEDUPGRADE_H
#define FIRESPEEDUPGRADE_H
#include"Player.h"
#include "Upgrade.h"

class FireSpeedUpgrade : public Upgrade {
private:
    float fireSpeedDecrease;
    float projectileSpeedIncrease;

public:
    FireSpeedUpgrade(Player* player, sf::Vector2f originPosition, float fireSpeedDecrease, float projectileSpeedIncrease);

    void apply(Player* player) override;
};

#endif