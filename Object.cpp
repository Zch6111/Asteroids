#include"Object.h"
#include<vector>
#include <SFML/Graphics.hpp>

Object::Object(sf::Shape* objectShape){
    shape = objectShape;
    sf::Vector2f zero(0.f,0.f);
    setPosition(zero);
    setVelocity(zero);
    setRotation(0);
    setRotationSpeed(0);
    active = 1;
};

Object::Object(sf::Shape* objectShape, sf::Vector2f originPosition, sf::Vector2f originVelocity, float originRotation, float originRotationSpeed){
    shape = objectShape;
    setPosition(originPosition);
    setVelocity(originVelocity);
    setRotation(originRotation);
    setRotation(originRotationSpeed);
    active = 1;
};

void Object::update(float deltaTime){
    if (active==0) {return;}

    position += velocity*deltaTime;
    setPosition(position);
    rotation += rotationSpeed*deltaTime;
    setRotation(rotation);
    (*shape).setPosition(position);
    (*shape).setRotation(rotation);
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
sf::Shape* Object::getShape(){
    return shape;
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
void Object::setRotationSpeed(float newRotationSpeed){
    rotationSpeed=newRotationSpeed;
};
void Object::setActive(bool isActive){
    active=isActive;
};// Sets the object’s active status.
