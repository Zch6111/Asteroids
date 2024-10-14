#ifndef MEDIUMENEMY_H
#define MEDIUMENEMY_H

#include "Enemy.h"

class MediumEnemy : public Enemy {
public:
    MediumEnemy(sf::Shape* shape); // Constructor

    void updateAI(float deltaTime) override; // Updates enemy's behavior based on AI
    void fireProjectile(std::vector<std::shared_ptr<Projectile>>& projectiles) override; // Fires a projectile
};

#endif