#ifndef UPGRADE_H
#define UPGRADE_H
#include"Object.h"
#include"Player.h"
class Upgrade :public Object{
 public:
virtual void applyToPlayer(Player& player)=0;// Applies the upgrade effect to the player.
virtual ~Upgrade() = default;
   
};
#endif