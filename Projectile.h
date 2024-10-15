#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Object.h"
#include <SFML/Graphics.hpp>

class Projectile : public Object {
private:
    float speed;  // The speed at which the projectile moves
    sf::Vector2f direction;  // The direction in which the projectile travels
    Object* source;  // Pointer to the object that fired the projectile

public:
    Projectile(sf::Shape* shape, float projectileSpeed, const sf::Vector2f& startPosition, const sf::Vector2f& projectileDirection, Object* firingSource);

    // Updates the projectile's position based on its speed and direction
    void update(float deltaTime) ;

    // Deactivates the projectile if it leaves the screen bounds
    void checkOutOfBounds();

    // Getters
    float getSpeed() const;
    sf::Vector2f getDirection() const;
    Object* getSource() const;

    // Setters
    void setSpeed(float newSpeed);
    void setDirection(const sf::Vector2f& newDirection);
    void setSource(Object* newSource);
};

#endif