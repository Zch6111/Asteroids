#include "HardEnemy.h"
#include <SFML/Graphics.hpp>
#include <cmath>

// Constructor for HardEnemy, initializing with 3 lives and faster speed
HardEnemy::HardEnemy(sf::Shape* shape) : Enemy(shape, 3, 200.f) {}

// Advanced AI for movement: move forward in a straight line
void HardEnemy::updateAI(float deltaTime) {
    if (!isActive()) return;

    sf::Vector2f direction(std::cos(getRotation() * M_PI / 180.f), std::sin(getRotation() * M_PI / 180.f));
    setPosition(getPosition() + direction * getSpeed() * deltaTime); // Move enemy forward

    getShape()->setPosition(getPosition());
    getShape()->setRotation(getRotation());
}

// Fires multiple projectiles in different directions
void HardEnemy::fireProjectile(std::vector<std::shared_ptr<Projectile>>& projectiles) {
    if (getFireCooldown() > 0) return; // Check if the cooldown is still active

    // Fire three projectiles in slightly different directions
    for (int i = -1; i <= 1; ++i) {
        sf::RectangleShape* projectileShape = new sf::RectangleShape(sf::Vector2f(5.f, 10.f));
        projectileShape->setFillColor(sf::Color::Red);

        // Slightly adjust the projectile's