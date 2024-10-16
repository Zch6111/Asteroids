#include "Projectile.h"

Projectile::Projectile(sf::Shape* projectileShape, sf::Vector2f originPosition, sf::Vector2f originVelocity)
    : Object(projectileShape, originPosition, originVelocity, 0.f, 0.f) {
    // Set up the projectile shape
    sf::CircleShape* circle = dynamic_cast<sf::CircleShape*>(projectileShape);
    if (circle) {
        circle->setRadius(5.f);
        circle->setOrigin(5.f, 5.f);
        circle->setFillColor(sf::Color::Blue);
    }
}

void Projectile::update(float deltaTime) {
    if (!active) return;

    Object::update(deltaTime);

    // Deactivate if out of bounds
    if (position.x < 0 || position.x > 800 || position.y < 0 || position.y > 600) {
        active = false;
    }
}

sf::Shape* Projectile::cloneShape(const sf::Shape* shape) {
    if (const sf::CircleShape* circle = dynamic_cast<const sf::CircleShape*>(shape)) {
        return new sf::CircleShape(*circle);
    } else if (const sf::RectangleShape* rect = dynamic_cast<const sf::RectangleShape*>(shape)) {
        return new sf::RectangleShape(*rect);
    }
    // Add other shape types if needed
    return nullptr;
}