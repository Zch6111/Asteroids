#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"

class Player : public Object {
private:
    int lives;
    float maxVelocity;
    float acceleration;
    float deceleration;
    float rotationSpeed;

public:
    Player();
    void moveForward(float deltaTime);
    void moveBackward(float deltaTime);
    void turnLeft(float deltaTime);
    void turnRight(float deltaTime);

    // Getters
    int getLives() const;
    float getMaxVelocity() const;
    float getAcceleration() const;
    float getDeceleration() const;
    float getRotationSpeed() const;

    // Setters
    void setLives(int newLives);
    void setMaxVelocity(float newMaxVelocity);
    void setAcceleration(float newAcceleration);
    void setDeceleration(float newDeceleration);
    void setRotationSpeed(float newRotationSpeed);
};

#endif