#ifndef SPEEDUPGRADE_H
#define SPEEDUPGRADE_H

#include "Upgrade.h"

class SpeedUpgrade : public Upgrade {
private:
    float speedIncrease;

public:
    SpeedUpgrade(sf::Vector2f originPosition, float increaseAmount);

    void apply(Player& player) override;
};

#endif