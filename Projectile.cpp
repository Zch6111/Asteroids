#include"Object.h"
#include <SFML/Graphics.hpp>
#include"Projectile.h"

void Projectile::update(float deltaTime){
   setPosition(getPosition());
    

};// Moves the projectile forward based on its speed and direction.
void Projectile::checkOutOfBounds(){};// Deactivates the projectile if it leaves the screen bounds.
//Getters:
float Projectile::getSpeed() const{
    return speed;
};// Returns the projectile’s speed.
sf::Vector2f Projectile::getDirection() const{
    return direction;
};// Returns the projectile’s direction.
Object* Projectile::getSource() const{
    return source;
};// Returns a pointer to the source object.
//Setters:
void Projectile::setSpeed(float newSpeed){
    speed = newSpeed;
};// Sets the projectile’s speed to newSpeed.
void Projectile::setDirection(const sf::Vector2f& newDirection){
    direction=newDirection;
};//Sets the projectile’s direction to newDirection.
void Projectile::setSource(Object* newSource){
    source=newSource;
};//: Sets the source object to newSource.
