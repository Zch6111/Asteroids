#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Object.h"
#include "Projectile.h"

class Player: public Object{
private:
    float maxVelocity;                      // The player’s max movement speed.
    float acceleration;                     // The player's acceleration
    float deceleration;                     // The player's deceleration
    float playerRotationSpeed;              // The speed at which the player can rotate.
    float fireSpeed;                        // The length of time left until player can shoot again.
    float fireCooldown;                     // Time remaining until the player can fire again.
    float projectileSpeed;                  // Speed of projectile
    std::vector<Projectile*> projectiles;   // List of projectiles

public:
    Player();                               // Player Constructor
    void update(float deltaTime);           // Class object update as well as manages projectiles
    void moveFoward();                      // Moves player foward
    void moveBackward();                    // Moves player Backward
    void turnLeft();                        // Turns player Left
    void turnRight();                       // Turns player Right
    void fire();                            // Fires Projectile
    void reset();                           // resets the player's variables

//Getters:
    float getMaxVelocity();                                 // Returns the player’s max movement speed.
    float getAcceleration();                                // Returns the player’s acceleration.
    float getDeceleration();                                // Returns the player’s deceleration.
    float getPlayerRotationSpeed();                         // Returns the player’s rotation speed.
    float getFireSpeed();                                   // Returns the player’s fire speed.
    float getProjectileSpeed();                             // Returns the player’s projectile speed.
    std::vector<Projectile*>* getProjectiles();             // Returns the list of projectiles.

//Setters:
    void setMaxVelocity(float maxVelocity);                 // Sets the movement speed to newSpeed.
    void setAcceleration(float acceleration);               // Sets the movement speed to newSpeed.
    void setDeceleration(float deceleration);               // Sets the movement speed to newSpeed.
    void setPlayerRotationSpeed(float newRotationSpeed);    // Sets the rotation speed to newRotationSpeed.
    void setFireSpeed(float fireSpeed);                    // Sets the player’s fire speed.
    void setProjectileSpeed(float projectileSpeed);        // Sets the player’s projectile speed.

};
#endif