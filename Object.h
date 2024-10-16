#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Graphics.hpp>

class Object{
private:
    sf::Shape* shape;
    sf::Vector2f position;
    sf::Vector2f velocity;
    float rotation;
    float rotationSpeed;
    bool active;

public:
    Object(sf::Shape* objectShape);
    Object(sf::Shape* objectShape, sf::Vector2f originPosition, sf::Vector2f originVelocity, float originRotation, float originRotationSpeed);
    ~Object();
    virtual void update(float deltaTime);// Updates the object’s state based on time elapsed (deltaTime).
    void render();//Draws the object on the screen. IT IS ON MAIN LOOP
    bool checkCollision(Object other);// Checks if this object is colliding with another object (other).
    void onCollision(Object other);//Handles the logic when a collision with another object occurs.
//Getters
    sf::Vector2f getPosition();// Returns the object’s current position.
    sf::Vector2f getVelocity();// Returns the object’s current velocity.
    float getRotation(); //Returns the object’s current rotation angle.
    float getRotationSpeed();
    bool isActive();// Returns whether the object is active.
    sf::Shape* getShape();
//Setters
    void setPosition(sf::Vector2f newPosition);//Sets the object’s position to newPosition.
    void setVelocity(sf::Vector2f newVelocity);// Sets the object’s velocity to newVelocity.
    void setRotation(float newRotation);// Sets the object’s rotation to newRotation.
    void setRotationSpeed(float newRotationSpeed);
    void setActive(bool isActive);// Sets the object’s active status.






};
#endif
