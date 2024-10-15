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
    if (active==0) {return;} // stop function if the object is not active

    position += velocity*deltaTime; // times velocity by deltatime to account for any lag
    setPosition(position);
    rotation += rotationSpeed*deltaTime; // times rotationSpeed by deltatime to account for any lag
    setRotation(rotation);
    
    // Wrap the object around the screen
    if (position.x > 800){
        position.x -= 800;
    }
    if (position.x < 0){
        position.x += 800;
    }
    if (position.y > 600){
        position.y -= 600;
    }
    if (position.y < 0){
        position.y += 600;
    }

    // apply position and rotation to object
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
}; // Returns the object’s current position.
sf::Vector2f Object::getVelocity(){
    return velocity;
}; // Returns the object’s current velocity.
float Object::getRotation(){
    return rotation;
}; // Returns the object’s current rotation angle.
float Object::getRotationSpeed(){
    return rotationSpeed;
}; // Returns the object’s current rotation speed.
bool Object::isActive(){
    return active;
}; // Returns whether the object is active.
sf::Shape* Object::getShape(){
    return shape;
};// Returns object's shape pointer.


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
};// Sets the object’s rotationSpeed to newRotationSpeed.
void Object::setActive(bool isActive){
    active=isActive;
};// Sets the object’s active status.
