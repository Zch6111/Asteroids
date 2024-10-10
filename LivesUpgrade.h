#ifndef LIVESUPGRADE_H
#define LIVESUPGRADE_H

#include "Upgrade.h"

class LivesUpgrade : public Upgrade {
public:
    // Constructor for LivesUpgrade
    LivesUpgrade();

    // Applies the life upgrade to the player
    void applyToPlayer(Player& player) override;
};

#endif