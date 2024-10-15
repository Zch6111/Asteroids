#include "Upgrade.h"
#include <SFML/Graphics.hpp>

Upgrade::Upgrade(sf::Vector2f position) : Object(new sf::CircleShape(10.f), position, sf::Vector2f(0.f, 0.f), 0.f, 0.f) {
    // Set the origin to the center of the circle
    sf::Shape* shape = getShape();
    shape->setOrigin(10.f, 10.f); // Circle has radius of 10, so origin is set to the center
}