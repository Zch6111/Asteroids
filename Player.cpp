#include <SFML/Graphics.hpp>
#include"Object.h"
#include"Player.h"
#include"Projectile.h"
void Player::handleInput(const sf::Event& input) {
    // Player movement: tank-style controls (rotate left/right, move forward/backward)
    
    // Rotate the player left (using the Left arrow key or A key)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        setRotation(getRotation() - rotationSpeed);  // Rotate counterclockwise
    }

    // Rotate the player right (using the Right arrow key or D key)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        setRotation(getRotation() + rotationSpeed);  // Rotate clockwise
    }

    // Move the player forward (using the Up arrow key or W key)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        // Calculate the direction based on the current rotation
        sf::Vector2f direction(std::cos(getRotation() * M_PI / 180.f), std::sin(getRotation() * M_PI / 180.f));

        // Update the player's velocity (moving forward)
        setVelocity(getVelocity() + speed * direction);  // Add to current velocity in the forward direction
    }

    // Move the player backward (using the Down arrow key or S key)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        // Calculate the direction based on the current rotation
        sf::Vector2f direction(std::cos(getRotation() * M_PI / 180.f), std::sin(getRotation() * M_PI / 180.f));

        // Update the player's velocity (moving backward)
        setVelocity(getVelocity() - speed * direction);  // Add to current velocity in the backward direction
    }

    // Player firing (using the Space key)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        fireProjectile();  // Call the function to fire a projectile if the fire cooldown allows it
    }
}
void Player::fireProjectile() {
    if (fireCooldown <= 0) {
        // Assuming the player has a shape (like a triangle for a spaceship) and the projectile moves forward
        sf::RectangleShape* projectileShape = new sf::RectangleShape(sf::Vector2f(5.f, 10.f));  // A simple rectangular bullet
        projectileShape->setFillColor(sf::Color::Yellow);

        // The direction is based on the player's current rotation
        sf::Vector2f direction(std::cos(getRotation() * M_PI / 180.f), std::sin(getRotation() * M_PI / 180.f));
        
        // Create the projectile
        Projectile* projectile = new Projectile(projectileShape, 300.f, getPosition(), direction, this);

        // Add the projectile to the game's list of active projectiles (you would need to maintain this list)
        activeProjectiles.push_back(std::shared_ptr<Projectile>(projectile));  // Assuming a list of shared_ptr
       
        fireCooldown = fireRate;  // Reset the fire cooldown
    }
}
void Player::applyUpgrade( Upgrade& upgrade){
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