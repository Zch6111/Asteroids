#include "Player.h"

#include <cmath>

Player::Player()
    : Object(new sf::CircleShape(20.f, 3)),
      lives(3),
      maxVelocity(200.f),
      acceleration(100.f),
      deceleration(0.98f),
      rotationSpeed(180.f) {
  shape->setOrigin(20.f, 20.f);
  shape->setFillColor(sf::Color::White);
  position = sf::Vector2f(400.f, 300.f);
  shape->setPosition(position);
}

void Player::moveForward(float deltaTime) {
  float angle = rotation * 3.14159265f / 180.f;
  sf::Vector2f dir(std::sin(angle), -std::cos(angle));
  velocity += dir * acceleration * deltaTime;
  if (std::hypot(velocity.x, velocity.y) > maxVelocity) {
    velocity = maxVelocity * dir;
  }
}

void Player::moveBackward(float deltaTime) { velocity *= deceleration; }

void Player::turnLeft(float deltaTime) {
  rotation -= rotationSpeed * deltaTime;
}

void Player::turnRight(float deltaTime) {
  rotation += rotationSpeed * deltaTime;
}

// Getters
int Player::getLives() const { return lives; }
float Player::getMaxVelocity() const { return maxVelocity; }
float Player::getAcceleration() const { return acceleration; }
float Player::getDeceleration() const { return deceleration; }
float Player::getRotationSpeed() const { return rotationSpeed; }

// Setters
void Player::setLives(int newLives) { lives = newLives; }
void Player::setMaxVelocity(float newMaxVelocity) {
  maxVelocity = newMaxVelocity;
}
void Player::setAcceleration(float newAcceleration) {
  acceleration = newAcceleration;
}
void Player::setDeceleration(float newDeceleration) {
  deceleration = newDeceleration;
}
void Player::setRotationSpeed(float newRotationSpeed) {
  rotationSpeed = newRotationSpeed;
}