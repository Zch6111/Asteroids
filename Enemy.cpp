#include "Enemy.h"
#include <cmath>

// Constructor to initialize enemy with lives, speed, and shape
Enemy::Enemy(sf::Shape* shape, int initialLives, float initialSpeed)
    : Object(shape), lives(initialLives), speed(initialSpeed), fireCooldown(0) {}

// Updates the enemy state, reducing fire cooldown and calling AI update
void Enemy::update(float deltaTime) {
    if (fireCooldown > 0) {
        fireCooldown -= deltaTime; // Decrease the cooldown over time
    }

    updateAI(deltaTime); // Call AI logic for enemy movement and behavior
}

void Enemy::onCollision(Object& other) {
    // Enemy disappears when it collides with any object
    this->setActive(false);  // Deactivate the enemy
}

// Getters and Setters
int Enemy::getLives() const {
    return lives;
}

void Enemy::setLives(int newLives) {
    lives = newLives;
}

float Enemy::getSpeed() const {
    return speed;
}

void Enemy::setSpeed(float newSpeed) {
    speed = newSpeed;
}

float Enemy::getFireCooldown() const {
    return fireCooldown;
}

void Enemy::setFireCooldown(float cooldown) {
    fireCooldown = cooldown;
}