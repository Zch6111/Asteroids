#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Graphics.hpp>

class Object{
private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    float rotation;
    bool active;

public:
    void update(float deltaTime);// Updates the object’s state based on time elapsed (deltaTime).
    void render();//Draws the object on the screen. IT IS ON MAIN LOOP
    bool checkCollision(const Object& other) const;// Checks if this object is colliding with another object (other).
    void onCollision(Object& other);//Handles the logic when a collision with another object occurs.
//Getters
    sf::Vector2f getPosition() const;// Returns the object’s current position.
    sf::Vector2f getVelocity() const;// Returns the object’s current velocity.
    float getRotation() const; //Returns the object’s current rotation angle.
    bool isActive() const;// Returns whether the object is active.
//Setters
    void setPosition(const sf::Vector2f& newPosition);//Sets the object’s position to newPosition.
    void setVelocity(const sf::Vector2f& newVelocity);// Sets the object’s velocity to newVelocity.
    void setRotation(float newRotation);// Sets the object’s rotation to newRotation.
    void setActive(bool isActive);// Sets the object’s active status.






};
#endif
