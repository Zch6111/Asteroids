#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include"Object.h"
#include"Upgrade.h"
class Player:public Object{
private:
int lives;// The number of lives the player has remaining.
int score;// The player’s current score.
float speed;// The player’s movement speed.
float rotationSpeed;// The speed at which the player can rotate.
float fireRate;// The rate at which the player can fire projectiles.
bool shieldActive;// Indicates whether the player’s shield is active.
std::vector<Upgrade*> upgrades;// A list of upgrades the player has collected.
float fireCooldown ;//Time remaining until the player can fire again.

public:
void handleInput(const sf::Event& input);// Processes user input (input) for movement and actions.
void fireProjectile();// Creates and fires a new projectile if the fire cooldown allows.
void applyUpgrade( Upgrade& upgrade);// Applies an upgrade’s effects to the player.
void respawn();// Resets the player’s position and state after losing a life.
//Getters:
int getLives() const;//Returns the number of lives remaining.
int getScore() const;//: Returns the current score.
bool isShieldActive() const;//: Returns whether the shield is active.
float getSpeed() const;//: Returns the player’s movement speed.
float getRotationSpeed() const;//: Returns the player’s rotation speed.
float getFireRate() const;//: Returns the player’s fire rate.
//Setters:
void setLives(int newLives);//: Sets the number of lives to newLives.
void setScore(int newScore);//: Sets the score to newScore.
void setShieldActive(bool isActive);//: Activates or deactivates the shield.
void setSpeed(float newSpeed);//: Sets the movement speed to newSpeed.
void setRotationSpeed(float newRotationSpeed);//: Sets the rotation speed to newRotationSpeed.
void setFireRate(float newFireRate);//: Sets the fire rate to newFireRate.

};
#endif