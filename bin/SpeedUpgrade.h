#ifndef SPEEDUPGRADE_H
#define SPEEDUPGRADE_H
#include"Object.h"
#include"Player.h"
#include"Upgrade.h"
class SpeedUpgrade :public Upgrade{
 public:
void applyToPlayer(Player& player)override;// Applies the upgrade effect to the player.
   
};
#endif