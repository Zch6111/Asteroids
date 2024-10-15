#ifndef ENEMY_H
#define ENEMY_H

#include "Object.h"

class Enemy : public Object {
protected:
    int lives;            // The number of hits the enemy can take before being destroyed
    float speed;          // The enemy's movement speed
    float fireCooldown;   // Time remaining until the enemy can fire again
    float fireRate;       // Rate at which the enemy fires projectiles
    sf::Vector2f direction; // Direction in which the enemy moves
    sf::Shape* projectileShape; // Shape of the enemy's projectile

public:
    Enemy(sf::Shape* enemyShape);
    ~Enemy();

    virtual void updateAI(float deltaTime) = 0; // Pure virtual function for AI behavior
    void fireProjectile(std::vector<Object*>& projectiles); // Fires a projectile
    void update(float deltaTime) ;
    //void onCollision(Object& other) override;

    // Getters
    int getLives();
    float getSpeed();
    float getFireRate();
    sf::Vector2f getDirection();

    // Setters
    void setLives(int newLives);
    void setSpeed(float newSpeed);
    void setFireRate(float newFireRate);
    void setDirection(sf::Vector2f newDirection);
};

#endif