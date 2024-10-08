#include "LivesUpgrade.h"

//
LivesUpgrade::LivesUpgrade() {}

// 
void LivesUpgrade::applyToPlayer(Player& player) {
    int currentLives = player.getLives();  // 
    player.setLives(currentLives + 1);     // 
}