#ifndef LIVESUPGRADE_H
#define LIVESUPGRADE_H

#include "Upgrade.h"
#include "Player.h"

class LivesUpgrade : public Upgrade {
public:
   
    LivesUpgrade();


    void applyToPlayer(Player& player) override;
};

#endif