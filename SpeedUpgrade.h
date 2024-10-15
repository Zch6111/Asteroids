#ifndef SPEEDUPGRADE_H
#define SPEEDUPGRADE_H

#include "Upgrade.h"

class SpeedUpgrade : public Upgrade {
public:
    SpeedUpgrade(sf::Vector2f position); // Constructor with position
    void applyToPlayer(Player& player) override;
};

#endif