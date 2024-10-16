#include "Enemy.h"

Enemy::Enemy(sf::Shape* enemyShape)
    : Object(enemyShape), lives(1), speed(50.f), fireCooldown(0.f), fireRate(2.f), direction(0.f, 1.f) {
    projectileShape = new sf::CircleShape(5.f);
    projectileShape->setFillColor(sf::Color::Red);
}

Enemy::~Enemy() {
    delete projectileShape;
}

void Enemy::fireProjectile(std::vector<Projectile*>& projectiles) {
    if (fireCooldown <= 0.f) {
        sf::Shape* clonedShape = Projectile::cloneShape(projectileShape);
        if (clonedShape) {
            sf::Vector2f projectileVelocity = direction * speed * 2.f;
            Projectile* projectile = new Projectile(clonedShape, position, projectileVelocity);
            projectiles.push_back(projectile);
            fireCooldown = fireRate;
        }
    }
}

void Enemy::update(float deltaTime, std::vector<Projectile*>& projectiles) {
    if (!active) return;

    fireCooldown -= deltaTime;

    Object::update(deltaTime);
    updateAI(deltaTime, projectiles);
}