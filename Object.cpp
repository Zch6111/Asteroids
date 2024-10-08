#include"Object.h"
#include<vector>
#include <SFML/Graphics.hpp>

Object::Object(){
    test = sf::CircleShape(10.f, 32);
    sf::Vector2f zero(0.f,0.f);
    setPosition(zero);
    setVelocity(zero);
    setRotation(0);
    active = 1;
};

Object::Object(float radius, sf::Vector2f originPosition, sf::Vector2f originVelocity, float originRotation){
    test = sf::CircleShape(radius, 32);
    setPosition(originPosition);
    setVelocity(originVelocity);
    setRotation(originRotation);
    active = 1;
};

void Object::update(){
    position += velocity;
    setPosition(position);
    setRotation(rotation);
    test.setPosition(position);
};// Updates the object’s state based on time elapsed (deltaTime).

bool Object::checkCollision(Object other){
    return 0;
};// Checks if this object is colliding with another object (other).
void Object::onCollision(Object other){};//Handles the logic when a collision with another object occurs.


//Getters
sf::Vector2f Object::getPosition(){
    return position;
};// Returns the object’s current position.
sf::Vector2f Object::getVelocity(){
    return velocity;
};// Returns the object’s current velocity.
float Object::getRotation(){
    return rotation;
}; //Returns the object’s current rotation angle.
bool Object::isActive(){
    return active;
};// Returns whether the object is active.
sf::CircleShape Object::getShape(){
    return test;
};


//Setters
void Object::setPosition(sf::Vector2f newPosition){
    position=newPosition;
};//Sets the object’s position to newPosition.
void Object::setVelocity(sf::Vector2f newVelocity){
    velocity=newVelocity;
};// Sets the object’s velocity to newVelocity.
void Object::setRotation(float newRotation){
    rotation=newRotation;
};// Sets the object’s rotation to newRotation.
void Object::setActive(bool isActive){
    active=isActive;
};// Sets the object’s active status.
