#include "Upgrade.h"

Upgrade::Upgrade(sf::Vector2f position)
    : Object(new sf::CircleShape(10.f), position, sf::Vector2f(0.f, 0.f), 0.f, 0.f) {
    shape->setOrigin(10.f, 10.f);
}