#include "FireSpeedUpgrade.h"

FireSpeedUpgrade::FireSpeedUpgrade(float increaseAmount) : fireRateIncrease(increaseAmount) {}


void FireSpeedUpgrade::applyToPlayer(Player& player) {
    float currentFireRate = player.getFireRate();  // 
    player.setFireRate(currentFireRate - fireRateIncrease);  // 
}