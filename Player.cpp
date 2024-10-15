#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include"Projectile.h"
#include"Enemy.h"

#include"Object.h"
#include"Player.h"

const sf::Vector2f centreOfScreen(400.f, 300.f);

Player::Player(): Object(new sf::CircleShape(20, 3)){
    sf::Shape* shape = getShape(); // get shape pointer
    shape->setOrigin(20, 20); // set the point of rotation to the centre of the shape
    setPosition(centreOfScreen); // place the ship in the centre of the screen
    // colour the ship
    (*shape).setFillColor(sf::Color(50, 50, 50));
    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(sf::Color(255, 255, 255));
    // initialise variables
    maxVelocity = 10.f;
    acceleration = 0.1f;
    deceleration = 0.8f;
    playerRotationSpeed = 4.f;
};


void Player::moveFoward(){
    sf::Vector2f direction(std::sin(getRotation() * M_PI / 180.f), -std::cos(getRotation() * M_PI / 180.f)); // Get the direction of the player as a vector of length one
    sf::Vector2f newVelocity = getVelocity() + acceleration*direction; // Add it to the current velocity to get the potential velocity
    float potentialMagnitude = sqrtf(powf(newVelocity.x, 2) + powf(newVelocity.y, 2)); // Get the magnitude of the new velocity
    if (potentialMagnitude < maxVelocity){
        setVelocity(newVelocity);
    } // If the magnitude of the potential velocity is less than maximum velocity, set the current velocity as the new velocity
    else {
        setVelocity((maxVelocity/potentialMagnitude)*newVelocity);
    }
};
void Player::moveBackward(){
    float velocityMagnitude = sqrtf(powf(getVelocity().x, 2) + powf(getVelocity().y, 2)); // Get the magnitude of the velocity
    if (velocityMagnitude > 0.f){
        setVelocity(deceleration*getVelocity());
    } // If the magnitude of the current velocity is greater than zero, decrease the velocity by 80%
};
void Player::turnLeft(){
    setRotation(getRotation() - playerRotationSpeed); // turn the player left by the playerRotationSpeed 
};
void Player::turnRight(){
    setRotation(getRotation() + playerRotationSpeed); // turn the player right by the playerRotationSpeed
};

void Player::fireProjectile(std::vector<std::shared_ptr<Projectile>>& projectiles) {
    // check cooldown
    if (fireCooldown <= 0) {
        // circle projectile
        sf::CircleShape* projectileShape = new sf::CircleShape(5.f);  // diameter=5
        projectileShape->setFillColor(sf::Color::Yellow);              // color in yellow

        // calculaterotation
        sf::Vector2f direction(std::sin(getRotation() * M_PI / 180.f), -std::cos(getRotation() * M_PI / 180.f));

        //create projectile
        std::shared_ptr<Projectile> newProjectile = std::make_shared<Projectile>(
            projectileShape, 300.f, getPosition(), direction, this  // this means it is from player
        );

        // store projectile
        projectiles.push_back(newProjectile);

        // reset fire cooldown
        fireCooldown = fireRate;
    }
};

void Player::applyUpgrade(const Upgrade& upgrade) {
    switch (upgrade.getType()) {
        case UpgradeType::SpeedUpgrade:
            setMaxVelocity(getMaxVelocity() + 5.f);  // Increase max velocity
            std::cout << "Speed Upgrade Applied! New Max Velocity: " << getMaxVelocity() << std::endl;
            break;

        case UpgradeType::FireRateUpgrade:
            setFireRate(getFireRate() - 0.1f);  // Increase fire rate
            std::cout << "Fire Rate Upgrade Applied! New Fire Rate: " << getFireRate() << std::endl;
            break;

        case UpgradeType::LivesUpgrade:
            setLives(getLives() + 1);  // Increase lives
            std::cout << "Lives Upgrade Applied! New Lives: " << getLives() << std::endl;
            break;

        default:
            break;  // Handle any unexpected upgrades
    }
}

void Player::onCollision(Object& other) {
    // If the player collides with an Upgrade
    if (Upgrade* upgrade = dynamic_cast<Upgrade*>(&other)) {
        upgrade->applyToPlayer(*this);  // Apply the upgrade effect to the player
        other.setActive(false);  // Deactivate the upgrade after being picked up
    }
    // If the player collides with a Projectile
    else if (Projectile* projectile = dynamic_cast<Projectile*>(&other)) {
        // Check if the projectile was fired by an enemy (to avoid friendly fire)
        if (projectile->getSource() != this) {
            this->setLives(this->getLives() - 1);  // Decrease player's lives
            if (this->getLives() <= 0) {
                this->setActive(false);  // Set player to inactive if lives reach zero (player dies)
            }
            projectile->setActive(false);  // Deactivate the projectile after it hits the player
        }
    }
    // If the player collides with an Enemy
    else if (dynamic_cast<Enemy*>(&other)) {
        this->setLives(this->getLives() - 1);  // Decrease player's lives
        if (this->getLives() <= 0) {
            this->setActive(false);  // Set player to inactive if lives reach zero (player dies)
        }
    }
}

//Getters:
float Player::getMaxVelocity(){
    return maxVelocity;
};//: Returns the player’s movement speed.
float Player::getAcceleration(){
    return acceleration;
};//: Returns the player’s movement speed.
float Player::getDeceleration(){
    return deceleration;
};//: Returns the player’s movement speed.
float Player::getPlayerRotationSpeed(){
    return playerRotationSpeed;

};//: Returns the player’s rotation speed.

//Setters:
void Player::setMaxVelocity(float maxVelocity){
    this->maxVelocity = maxVelocity;
};//: Sets the movement speed to newSpeed.
void Player::setAcceleration(float acceleration){
    this->acceleration = acceleration;
};//: Sets the movement speed to newSpeed.
void Player::setDeceleration(float deceleration){
    this->deceleration = deceleration;
};//: Sets the movement speed to newSpeed.
void Player::setPlayerRotationSpeed(float playerRotationSpeed){
    this->playerRotationSpeed = playerRotationSpeed;
};//: Sets the rotation speed to newRotationSpeed.