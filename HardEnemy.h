#ifndef HARDENEMY_H
#define HARDENEMY_H

#include "Enemy.h"

class HardEnemy : public Enemy {
public:
    HardEnemy(sf::Shape* shape); // Constructor

    void updateAI(float deltaTime) override; // Updates enemy's behavior based on AI
    void fireProjectile(std::vector<std::shared_ptr<Projectile>>& projectiles) override; // Fires multiple projectiles
};

#endif