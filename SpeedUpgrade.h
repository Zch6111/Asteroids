#ifndef SPEEDUPGRADE_H
#define SPEEDUPGRADE_H

#include "Upgrade.h"

class SpeedUpgrade : public Upgrade {
private:
    float speedIncrease;//how much increase

public:
   
    // Constructor to initialize position and speed increase amount
    SpeedUpgrade(sf::Vector2f originPosition, float increaseAmount);
    void apply(Player& player) override;//Applies the speed upgrade to the player
    void render(sf::RenderWindow& window) override;
};


#endif