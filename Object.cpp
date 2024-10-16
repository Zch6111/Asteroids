#include "Object.h"

Object::Object(sf::Shape* objectShape)
    : shape(objectShape), position(0.f, 0.f), velocity(0.f, 0.f), rotation(0.f), rotationSpeed(0.f), active(true) {
    shape->setPosition(position);
    shape->setRotation(rotation);
}

Object::Object(sf::Shape* objectShape, sf::Vector2f originPosition, sf::Vector2f originVelocity, float originRotation, float originRotationSpeed)
    : shape(objectShape), position(originPosition), velocity(originVelocity), rotation(originRotation), rotationSpeed(originRotationSpeed), active(true) {
    shape->setPosition(position);
    shape->setRotation(rotation);
}

Object::~Object() {
    delete shape;
}

void Object::update(float deltaTime) {
    if (!active) return;

    position += velocity * deltaTime;
    rotation += rotationSpeed * deltaTime;

    // Wrap around screen (assuming 800x600 screen size)
    if (position.x > 800) position.x = 0;
    if (position.x < 0) position.x = 800;
    if (position.y > 600) position.y = 0;
    if (position.y < 0) position.y = 600;

    shape->setPosition(position);
    shape->setRotation(rotation);
}

bool Object::checkCollision(const Object& other) {
    if (!active || !other.active) return false;

    float distance = std::hypot(position.x - other.position.x, position.y - other.position.y);
    float radiusA = shape->getGlobalBounds().width / 2.f;
    float radiusB = other.shape->getGlobalBounds().width / 2.f;
    return distance < (radiusA + radiusB);
}

void Object::onCollision(Object& other) {
    // Default collision handling (can be overridden)
}

sf::Vector2f Object::getPosition() const { return position; }
sf::Vector2f Object::getVelocity() const { return velocity; }
float Object::getRotation() const { return rotation; }
float Object::getRotationSpeed() const { return rotationSpeed; }
bool Object::isActive() const { return active; }
sf::Shape* Object::getShape() const { return shape; }

void Object::setPosition(sf::Vector2f newPosition) { position = newPosition; shape->setPosition(position); }
void Object::setVelocity(sf::Vector2f newVelocity) { velocity = newVelocity; }
void Object::setRotation(float newRotation) { rotation = newRotation; shape->setRotation(rotation); }
void Object::setRotationSpeed(float newRotationSpeed) { rotationSpeed = newRotationSpeed; }
void Object::setActive(bool isActive) { active = isActive; }

void Object::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (active) {
        target.draw(*shape, states);
    }
}