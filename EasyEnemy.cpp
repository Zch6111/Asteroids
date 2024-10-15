#include "EasyEnemy.h"
#include <SFML/Graphics.hpp>
#include <cmath>

// Constructor for EasyEnemy, initializing with 1 life and lower speed
EasyEnemy::EasyEnemy(sf::Shape* shape) : Enemy(shape, 1, 100.f) {}

// Simple AI for movement: just move forward in a straight line
void EasyEnemy::updateAI(float deltaTime) {
    if (!isActive()) return;

    sf::Vector2f direction(std::cos(getRotation() * M_PI / 180.f), std::sin(getRotation() * M_PI / 180.f));
    setPosition(getPosition() + direction * getSpeed() * deltaTime); // Move enemy forward

    getShape()->setPosition(getPosition());
    getShape()->setRotation(getRotation());
}

// Fires a single projectile with a slower fire rate
void EasyEnemy::fireProjectile(std::vector<std::shared_ptr<Projectile>>& projectiles) {
    if (getFireCooldown() > 0) return; // Check if the cooldown is still active

    // Create the projectile's shape and color it red
    sf::RectangleShape* projectileShape = new sf::RectangleShape(sf::Vector2f(5.f, 10.f));
    projectileShape->setFillColor(sf::Color::Red);

    // Calculate the direction of the projectile
    sf::Vector2f direction(std::cos(getRotation() * M_PI / 180.f), std::sin(getRotation() * M_PI / 180.f));

    // Create a new projectile and push it to the active projectiles list
    std::shared_ptr<Projectile> projectile = std::make_shared<Projectile>(projectileShape, 200.f, getPosition(), direction, this);
    projectiles.push_back(projectile);

    setFireCooldown(2.0f); // Reset the cooldown (slow fire rate)
}