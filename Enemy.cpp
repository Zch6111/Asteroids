#include "Enemy.h"
#include "Projectile.h"

Enemy::Enemy(sf::Shape* enemyShape) : Object(enemyShape) {
    lives = 1;
    speed = 50.f;
    fireRate = 2.f;
    fireCooldown = 0.f;
    direction = sf::Vector2f(0.f, 1.f); // Default direction
    projectileShape = new sf::CircleShape(5.f);
    projectileShape->setFillColor(sf::Color::Red);
}

Enemy::~Enemy() {
    delete projectileShape;
}

void Enemy::fireProjectile(std::vector<Object*>& projectiles) {
    if (fireCooldown <= 0.f) {
        // Use the cloneShape method to clone the shape
        sf::Shape* clonedShape = Projectile::cloneShape(projectileShape);
        if (clonedShape) {
            // Create a new projectile with the cloned shape
            Projectile* projectile = new Projectile(clonedShape, getPosition(), direction * speed * 2.f);
            projectiles.push_back(projectile);
        }
        fireCooldown = fireRate; // Reset the cooldown
    }
}

void Enemy::update(float deltaTime) {
 
}

//void Enemy::onCollision(Object& other) {
    // Decrease lives or deactivate
    //lives--;
    //if (lives <= 0) {
       // active = false;
   // }
//}

// Getters
int Enemy::getLives() {
    return lives;
}

float Enemy::getSpeed() {
    return speed;
}

float Enemy::getFireRate() {
    return fireRate;
}

sf::Vector2f Enemy::getDirection() {
    return direction;
}

// Setters
void Enemy::setLives(int newLives) {
    lives = newLives;
}

void Enemy::setSpeed(float newSpeed) {
    speed = newSpeed;
}

void Enemy::setFireRate(float newFireRate) {
    fireRate = newFireRate;
}

void Enemy::setDirection(sf::Vector2f newDirection) {
    direction = newDirection;
}