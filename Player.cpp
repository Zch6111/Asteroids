#include <SFML/Graphics.hpp>
#include <cmath>

#include"Object.h"
#include"Player.h"

const sf::Vector2f centreOfScreen(400.f, 300.f);

Player::Player(): Object(new sf::CircleShape(20, 3)){
    sf::Shape* shape = getShape();
    shape->setOrigin(20, 20);
    (*shape).setFillColor(sf::Color(50, 50, 50));
    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(sf::Color(255, 255, 255));
    setPosition(centreOfScreen);
    maxVelocity = 10.f;
    maxRotationSpeed = 10.f;
};

void Player::handleInput(sf::Event input){
    // Player movement: tank-style controls (rotate left/right, move forward/backward)
    
    // Rotate the player left (using the Left arrow key or A key)
    if (input.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || input.type == sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (getRotationSpeed() < maxRotationSpeed){
            setRotationSpeed(getRotationSpeed() + 0.5f);
        }
    }

    // Rotate the player right (using the Right arrow key or D key)
    if (input.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || input.type == sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (getRotationSpeed() < - maxRotationSpeed){
            setRotationSpeed(getRotationSpeed() -0.5f);
        }
    }

    // Move the player forward (using the Up arrow key or W key)
    if (input.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || input.type == sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        sf::Vector2f direction(std::cos(getRotation() * M_PI / 180.f), std::sin(getRotation() * M_PI / 180.f));
        sf::Vector2f newVelocity = getVelocity() + direction;
        float potentialMagnitude = sqrtf(powf(newVelocity.x, 2) + powf(newVelocity.y, 2));
        if (potentialMagnitude < maxVelocity){
            setVelocity(newVelocity);
        }
    }

    // Move the player backward (using the Down arrow key or S key)
    if (input.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || input.type == sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        sf::Vector2f direction(std::cos(getRotation() * M_PI / 180.f), std::sin(getRotation() * M_PI / 180.f));
        sf::Vector2f newVelocity = getVelocity() + direction;
        float potentialMagnitude = sqrtf(powf(newVelocity.x, 2) + powf(newVelocity.y, 2));
        if (potentialMagnitude < maxVelocity){
            setVelocity(newVelocity);
        }
    }
};// Processes user input (input) for movement and actions.

//Getters:
float Player::getMaxVelocity() const{
    return maxVelocity;
};//: Returns the player’s mo;vement speed.
float Player::getMaxRotationSpeed() const{
    return maxRotationSpeed;

};//: Returns the player’s rotation speed.

//Setters:
void Player::setMaxVelocity(float maxVelocity){
    this->maxVelocity = maxVelocity;
};//: Sets the movement speed to newSpeed.
void Player::setMaxRotationSpeed(float maxRotationSpeed){
    this->maxRotationSpeed = maxRotationSpeed;
};//: Sets the rotation speed to newRotationSpeed.