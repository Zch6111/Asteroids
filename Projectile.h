#ifndef PROJECTILE_H
#define PROJECTILE_H
#include"Object.h"
#include <SFML/Graphics.hpp>
class Projectile :public Object{
private:

float speed;// The speed at which the projectile moves.
sf::Vector2f direction;// The direction in which the projectile travels.
Object* source;//Pointer to the object that fired the projectile.
public:
Projectile();
void update(float deltaTime);// Moves the projectile forward based on its speed and direction.
void checkOutOfBounds();// Deactivates the projectile if it leaves the screen bounds.
//Getters:
float getSpeed() const;// Returns the projectile’s speed.
sf::Vector2f getDirection() const;// Returns the projectile’s direction.
Object* getSource() const;// Returns a pointer to the source object.
//Setters:
void setSpeed(float newSpeed);// Sets the projectile’s speed to newSpeed.
void setDirection(const sf::Vector2f& newDirection);//Sets the projectile’s direction to newDirection.
void setSource(Object* newSource);//: Sets the source object to newSource.
};
#endif
