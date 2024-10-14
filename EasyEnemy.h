#ifndef EASYENEMY_H
#define EASYENEMY_H
#include"Enemy.h"



class EasyEnemy : public Enemy {
public:
    EasyEnemy(sf::Shape* shape); // Constructor

    void updateAI(float deltaTime) override; // Updates enemy's behavior based on AI
    void fireProjectile(std::vector<std::shared_ptr<Projectile>>& projectiles) override; // Fires a projectile
};

#endif