#ifndef FIRESPEEDUPGRADE_H
#define FIRESPEEDUPGRADE_H
#include"Player.h"
#include "Upgrade.h"

class FireSpeedUpgrade : public Upgrade {
private:
    const float fireSpeedDecrease = 10.f;
    const float projectileSpeedIncrease = 5.f;

public:
    FireSpeedUpgrade(Player* player, sf::Vector2f originPosition);

    void apply(Player* player) override;
};

#endif