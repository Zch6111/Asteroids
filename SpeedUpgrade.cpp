#include"Object.h"
#include"Player.h"
#include"Upgrade.h"
#include"SpeedUpgrade.h"
void SpeedUpgrade::applyToPlayer(Player& player)  {
        float currentSpeed = player.getSpeed();
        player.setSpeed(currentSpeed + speedIncrease);  // Increase player's speed
    }
SpeedUpgrade::SpeedUpgrade(float increaseAmount) : speedIncrease(increaseAmount) {};