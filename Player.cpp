#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#include"Object.h"
#include"Player.h"

const sf::Vector2f centreOfScreen(400.f, 300.f);
const sf::Vector2f ScreenWidth(800.f, 0);
const sf::Vector2f ScreenHeight(0, 600.f);
const sf::Vector2f zero(0, 0);

Player::Player(): Object(new sf::CircleShape(20, 3)){
    sf::Shape* shape = getShape(); // get shape pointer
    shape->setOrigin(20, 20); // set the point of rotation to the centre of the shape
    setPosition(centreOfScreen); // place the ship in the centre of the screen
    // colour the ship
    (*shape).setFillColor(sf::Color(0, 150, 0));
    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(sf::Color(255, 255, 255));
    // initialise variables
    maxVelocity = 10.f;
    acceleration = 0.1f;
    deceleration = 0.8f;
    playerRotationSpeed = 4.f;
    fireCooldown = 0.f;
    fireSpeed = 50.f;
    projectileSpeed = 5.f;
};

void Player::update(float deltaTime){
    Object::update(deltaTime); // Call object update funtion

    // Wrap the object around the screen
    if (getPosition().x > 800){
        setPosition(getPosition() - ScreenWidth);
    }
    if (getPosition().x < 0){
        setPosition(getPosition() + ScreenWidth);
    }
    if (getPosition().y > 600){
        setPosition(getPosition() - ScreenHeight);
    }
    if (getPosition().y < 0){
        setPosition(getPosition() + ScreenHeight);
    }

    if (fireCooldown>0){
        fireCooldown -= deltaTime;
    } // if the player has not cooled down yet, decreases it's firecooldown timer

    for (int i=0; i < projectiles.size(); i++){
        if (projectiles[i]->isActive() == 0){
            projectiles.erase(projectiles.begin() + i);
            continue;
        }
        projectiles[i]->update(deltaTime);
    }

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
void Player::fire(){
    if (fireCooldown > 0) {return;} // check if player can fire a projectile

    // create a projectile with a pointer
    Projectile* newProjectile;
    newProjectile = new Projectile(projectileSpeed, getPosition(), getRotation());
    projectiles.push_back(newProjectile); // add projectile to projectiles vector

    fireCooldown = fireSpeed; // reset fire cooldown
};

void Player::reset(){
    // reset position;
    setPosition(centreOfScreen);
    setVelocity(zero);
    setRotation(0);
    // reset variables
    maxVelocity = 10.f;
    acceleration = 0.1f;
    deceleration = 0.8f;
    playerRotationSpeed = 4.f;
    fireCooldown = 0.f;
    fireSpeed = 50.f;
    projectileSpeed = 5.f;
    projectiles.clear();
};


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
std::vector<Projectile*>* Player::getProjectiles(){
    return &projectiles;
};//: Returns the player’s rotation speed.
float Player::getFireSpeed(){
    return fireSpeed;
};// Returns the player’s fire speed.
float Player::getProjectileSpeed(){
    return projectileSpeed;
};// Returns the player’s projectile speed.


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
void Player::setFireSpeed(float fireSpeed){
    this->fireSpeed = fireSpeed;
};// Sets the player’s fire speed.
void Player::setProjectileSpeed(float projectileSpeed){
    this->projectileSpeed = projectileSpeed;
};// Sets the player’s projectile speed.