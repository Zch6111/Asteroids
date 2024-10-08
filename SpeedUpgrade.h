#ifndef SPEEDUPGRADE_H
#define SPEEDUPGRADE_H
#include"Object.h"
#include"Player.h"
#include"Upgrade.h"
class SpeedUpgrade :public Upgrade{
    private:
    float speedIncrease;
 public:
 SpeedUpgrade(float increaseAmount);
void applyToPlayer(Player& player)override;// Applies the upgrade effect to the player.
   
};
#endif