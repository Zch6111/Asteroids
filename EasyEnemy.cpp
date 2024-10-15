#include "EasyEnemy.h"
#include <cmath>

EasyEnemy::EasyEnemy() : Enemy(new sf::RectangleShape(sf::Vector2f(30.f, 30.f))) {
    lives = 1;
    speed = 50.f;
    fireRate = 3.f;
    setRotationSpeed(30.f); // Slow rotation
    // Initialize shape
    sf::Shape* shape = getShape();
    shape->setFillColor(sf::Color::Green);
    shape->setOrigin(15.f, 15.f);
}

void EasyEnemy::updateAI(float deltaTime) {
    // Simple movement: move forward in current direction
    sf::Vector2f velocity = getVelocity();
    if (velocity == sf::Vector2f(0.f, 0.f)) {
        // Set initial velocity
        setVelocity(direction * speed);
    }
    
}