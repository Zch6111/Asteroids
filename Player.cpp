#include <SFML/Graphics.hpp>
#include"Object.h"
#include"Player.h"
void Player::handleInput(const sf::Event& input){};// Processes user input (input) for movement and actions.
void Player::fireProjectile(){
    if (fireCooldown <= 0) {
        // Create and fire a new projectile
        // Add projectile logic here
        fireCooldown = fireRate;  // Reset the fire cooldown
    }
};// Creates and fires a new projectile if the fire cooldown allows.
void Player::applyUpgrade(const Upgrad& upgrade){
   upgrade.applyToPlayer(*this);  // Apply the upgrade to the playe
};// Applies an upgrade’s effects to the player.
void Player::respawn(){
    setPosition(sf::Vector2f(0, 0));  // Reset player position to the center
    setVelocity(sf::Vector2f(0, 0));  // Reset velocity
    setRotation(0.0f);  // Reset rotation
    setActive(true);  // Make sure the player is active
};// Resets the player’s position and state after losing a life.
//Getters:
int Player::getLives() const{
    return lives;

};//Returns the number of lives remaining.
int Player:: getScore() const{
    return score;
};//: Returns the current score.
bool Player::isShieldActive() const{
    return shieldActive;
};//: Returns whether the shield is active.
float Player::getSpeed() const{
    return speed;
};//: Returns the player’s mo;vement speed.
float Player::getRotationSpeed() const{
    return rotationSpeed;

};//: Returns the player’s rotation speed.
float Player::getFireRate() const{
    return fireRate;
};//: Returns the player’s fire rate.
//Setters:
void Player::setLives(int newLives){
    lives=newLives;
};//: Sets the number of lives to newLives.
void Player::setScore(int newScore){
    score=newScore;
};//: Sets the score to newScore.
void Player::setShieldActive(bool isActive){
    shieldActive=isActive;
};//: Activates or deactivates the shield.
void Player::setSpeed(float newSpeed){
    speed=newSpeed;
};//: Sets the movement speed to newSpeed.
void Player::setRotationSpeed(float newRotationSpeed){
    rotationSpeed=newRotationSpeed;
};//: Sets the rotation speed to newRotationSpeed.
void Player::setFireRate(float newFireRate){
    fireRate=newFireRate;
};//: Sets the fire rate to newFireRate.