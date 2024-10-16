#include "EasyEnemy.h"

EasyEnemy::EasyEnemy()
    : Enemy(new sf::RectangleShape(sf::Vector2f(30.f, 30.f))) {
  lives = 1;
  speed = 50.f;
  fireRate = 3.f;
  rotationSpeed = 30.f;

  shape->setFillColor(sf::Color::Green);
  shape->setOrigin(15.f, 15.f);
}

void EasyEnemy::updateAI(float deltaTime,
                         std::vector<Projectile*>& projectiles) {
  // Simple movement: move forward in current direction
  if (velocity == sf::Vector2f(0.f, 0.f)) {
    velocity = direction * speed;
  }
  // Fire projectile
  fireProjectile(projectiles);
}