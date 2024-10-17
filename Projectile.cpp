#include <SFML/Graphics.hpp>
#include <cmath>
#include "Projectile.h"
#include "Object.h"

const sf::Vector2f zero(0, 0);

Projectile::Projectile(float speed, sf::Vector2f playerPosition, float playerRotation): Object(new sf::CircleShape(2.5f, 4), playerPosition, zero, playerRotation, 0.f){
    sf::Shape* shape = getShape();
    
    sf::Vector2f direction(std::sin(playerRotation * M_PI / 180.f), -std::cos(playerRotation * M_PI / 180.f)); // Get the direction of the player as a vector of length one

    setVelocity(speed*direction);

    shape->setOrigin(5.f,5.f);
    (*shape).setFillColor(sf::Color(255, 255, 0));

    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(sf::Color(140, 140, 140));
};

void Projectile::update(float deltaTime){
    Object::update(deltaTime); // Call object update funtion

    // Wrap the object around the screen
    if (getPosition().x > 800){
        setActive(0);
    }
    if (getPosition().x < 0){
        setActive(0);
    }
    if (getPosition().y > 600){
        setActive(0);
    }
    if (getPosition().y < 0){
        setActive(0);
    }

};
