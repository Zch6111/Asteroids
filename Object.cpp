#include"Object.h"
#include<vector>
#include <SFML/Graphics.hpp>

    void Object:: update(float deltaTime){
        //position
        position += velocity * deltaTime;

    };// Updates the object’s state based on time elapsed (deltaTime).

    bool Object::checkCollision(const Object& other) const{
        //check distance berwtween.....
        float distance = std::sqrt(
        std::pow(position.x - other.position.x, 2) + 
        std::pow(position.y - other.position.y, 2)
    );

    };// Checks if this object is colliding with another object (other).
    void Object::onCollision(Object& other){};//Handles the logic when a collision with another object occurs.
//Getters
    sf::Vector2f Object::getPosition() const{
        return position;
    };// Returns the object’s current position.
    sf::Vector2f Object::getVelocity() const{
        return velocity;
    };// Returns the object’s current velocity.
    float Object::getRotation() const{
        return rotation;
    }; //Returns the object’s current rotation angle.
    bool Object::isActive() const{
        return active;
    };// Returns whether the object is active.
//Setters
    void Object::setPosition(const sf::Vector2f& newPosition){
        position=newPosition;
    };//Sets the object’s position to newPosition.
    void Object::setVelocity(const sf::Vector2f& newVelocity){
        velocity=newVelocity;
    };// Sets the object’s velocity to newVelocity.
    void Object::setRotation(float newRotation){
        rotation=newRotation;
    };// Sets the object’s rotation to newRotation.
    void Object::setActive(bool isActive){
        active=isActive;
    };// Sets the object’s active status.
