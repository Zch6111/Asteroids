#include "Projectile.h"
#include"Update.h"
#include "Object.h"
#include <SFML/Graphics.hpp>
// Constructor for initializing the projectile
Projectile::Projectile(sf::Shape* shape, float projectileSpeed, const sf::Vector2f& startPosition, const sf::Vector2f& projectileDirection, Object* firingSource)
    : Object(shape), speed(projectileSpeed), direction(projectileDirection), source(firingSource) {
    setPosition(startPosition);  // Initialize the starting position of the projectile
}

// Update function to move the projectile forward based on its speed and direction
void Projectile::update(float deltaTime) {
    if (!isActive()) return;

    // Calculate the new position: position += direction * speed * deltaTime
    sf::Vector2f newPosition = getPosition() + direction * speed * deltaTime;
    setPosition(newPosition);

    // Update the shape position to reflect the projectile's new position
    getShape()->setPosition(newPosition);

    // Check if the projectile has gone out of bounds
    checkOutOfBounds();
}

// Check if the projectile is out of bounds, deactivate it if it is
void Projectile::checkOutOfBounds() {
    sf::Vector2f pos = getPosition();

    // Assuming screen bounds are (0, 0) to (windowWidth, windowHeight)
    const float windowWidth = 800.f;  // 
    const float windowHeight = 600.f;  // 

    // Check if the projectile is outside the screen bounds
    if (pos.x < 0 || pos.x > windowWidth || pos.y < 0 || pos.y > windowHeight) {
        setActive(false);  // Deactivate the projectile
    }
}

// Getters
float Projectile::getSpeed() const {
    return speed;
}

sf::Vector2f Projectile::getDirection() const {
    return direction;
}

Object* Projectile::getSource() const {
    return source;
}

// Setters
void Projectile::setSpeed(float newSpeed) {
    speed = newSpeed;
}

void Projectile::setDirection(const sf::Vector2f& newDirection) {
    direction = newDirection;
}

void Projectile::setSource(Object* newSource) {
    source = newSource;
}