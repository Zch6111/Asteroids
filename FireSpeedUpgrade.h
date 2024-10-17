#ifndef FIRESPEEDUPGRADE_H
#define FIRESPEEDUPGRADE_H
#include"Player.h"
#include "Upgrade.h"

class FireSpeedUpgrade : public Upgrade {
private:
    float cooldownDecrease;

public:
    FireSpeedUpgrade(sf::Vector2f originPosition, float decreaseAmount);

    void apply(Player& player) override;
};

#endif