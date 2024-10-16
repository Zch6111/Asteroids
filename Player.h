#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Object.h"
#include "Projectile.h"

class Player: public Object{
private:
    // int lives;                           // The number of lives the player has remaining.
    // int score;                           // The player’s current score.
    float maxVelocity;                      // The player’s max movement speed.
    float acceleration;                     // The player's acceleration
    float deceleration;                     // The player's deceleration
    float playerRotationSpeed;              // The speed at which the player can rotate.
    float fireSpeed;                        // The length of time left until player can shoot again.
    float fireCooldown;                     // Time remaining until the player can fire again.
    float projectileSpeed;                  // Speed of projectile
    std::vector<Projectile*> projectiles;   // List of projectiles
    // bool shieldActive;                   // Indicates whether the player’s shield is active.
    // std::vector<UpgradeType> upgrades;   // A list of upgrades the player has collected.

public:
    Player();                               // Player Constructor
    void update(float deltaTime);           // Class object update as well as manages projectiles
    void moveFoward();                      // Moves player foward
    void moveBackward();                    // Moves player Backward
    void turnLeft();                        // Turns player Left
    void turnRight();                       // Turns player Right
    void fire();                            // Fires Projectile
    // void fireProjectile();// Creates and fires a new projectile if the fire cooldown allows.
    // void applyUpgrade(const Upgrade& upgrade);// Applies an upgrade’s effects to the player.
    // void respawn();// Resets the player’s position and state after losing a life.

//Getters:
    // int getLives();                                      // Returns the number of lives remaining.
    // int getScore();                                      // Returns the current score.
    // bool isShieldActive();                               // Returns whether the shield is active.
    float getMaxVelocity();                                 // Returns the player’s max movement speed.
    float getAcceleration();                                // Returns the player’s acceleration.
    float getDeceleration();                                // Returns the player’s deceleration.
    float getPlayerRotationSpeed();                         // Returns the player’s rotation speed.
    std::vector<Projectile*>* getProjectiles();             // Returns the list of projectiles.
    // float getFireRate();// Returns the player’s fire rate.

//Setters:
    // void setLives(int newLives);//: Sets the number of lives to newLives.
    // void setScore(int newScore);//: Sets the score to newScore.
    // void setShieldActive(bool isActive);//: Activates or deactivates the shield.
    void setMaxVelocity(float maxVelocity);                 // Sets the movement speed to newSpeed.
    void setAcceleration(float acceleration);               // Sets the movement speed to newSpeed.
    void setDeceleration(float deceleration);               // Sets the movement speed to newSpeed.
    void setPlayerRotationSpeed(float newRotationSpeed);    // Sets the rotation speed to newRotationSpeed.
    // void setFireRate(float newFireRate);//: Sets the fire rate to newFireRate.

};
#endif