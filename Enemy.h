#ifndef ENEMY_H
#define ENEMY_H

#include "Object.h"
#include "Projectile.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Enemy : public Object {
private:
    int lives;          // The number of hits the enemy can take before being destroyed
    float speed;        // The enemy's movement speed
    float fireCooldown; // Time remaining until the enemy can fire again

public:
    Enemy(sf::Shape* shape, int initialLives, float initialSpeed); // Constructor

    virtual void updateAI(float deltaTime) = 0; // Abstract function to be implemented by derived classes
    virtual void fireProjectile(std::vector<std::shared_ptr<Projectile>>& projectiles) = 0; // Abstract function for firing projectiles

    void update(float deltaTime); // Updates the enemy's state, including AI logic and fire cooldown

    // Getters and Setters
    int getLives() const;
    void setLives(int newLives);

    float getSpeed() const;
    void setSpeed(float newSpeed);

    float getFireCooldown() const;
    void setFireCooldown(float cooldown);
};

#endif