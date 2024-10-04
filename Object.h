#ifndef OBJECT_H
#define OBLECT_H
struct Vector2D{
    int x;
    int y;
};

class Object{
private:
    Vector2D position;
    Vector2D velocity;
    float rotation;
    bool active;

public:
    void update(float deltaTime);// Updates the object’s state based on time elapsed (deltaTime).
    void render();//Draws the object on the screen. IT IS ON MAIN LOOP
    bool checkCollision(const Object& other) const;// Checks if this object is colliding with another object (other).
    void onCollision(Object& other);//Handles the logic when a collision with another object occurs.
//Getters
    Vector2D getPosition() const;// Returns the object’s current position.
    Vector2D getVelocity() const;// Returns the object’s current velocity.
    float getRotation() const; //Returns the object’s current rotation angle.
    bool isActive() const;// Returns whether the object is active.
//Setters
    void setPosition(const Vector2D& newPosition);//Sets the object’s position to newPosition.
    void setVelocity(const Vector2D& newVelocity);// Sets the object’s velocity to newVelocity.
    void setRotation(float newRotation);// Sets the object’s rotation to newRotation.
    void setActive(bool isActive);// Sets the object’s active status.






};
#endif
