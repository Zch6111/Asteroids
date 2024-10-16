#ifndef ENEMY_H
#define ENEMY_H

#include <vector>

#include "Object.h"
#include "Projectile.h"

class Enemy : public Object {
 protected:
  int lives;    // The number of hits the enemy can take before being destroyed
  float speed;  // The enemy's movement speed
  float fireCooldown;          // Time remaining until the enemy can fire again
  float fireRate;              // Rate at which the enemy fires projectiles
  sf::Vector2f direction;      // Direction in which the enemy moves
  sf::Shape* projectileShape;  // Shape of the enemy's projectile

 public:
  Enemy(sf::Shape* enemyShape);
  virtual ~Enemy();

  virtual void updateAI(float deltaTime,
                        std::vector<Projectile*>& projectiles) = 0;
  void fireProjectile(std::vector<Projectile*>& projectiles);
  void update(float deltaTime, std::vector<Projectile*>& projectiles);

  // Getters and Setters...
};

#endif