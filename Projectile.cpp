#include "Projectile.h"

Projectile::Projectile(sf::Shape* projectileShape, sf::Vector2f originPosition, sf::Vector2f originVelocity)
    : Object(projectileShape, originPosition, originVelocity, 0.f, 0.f) {
    // Initialize the projectile shape as a circle
    sf::CircleShape* circle = dynamic_cast<sf::CircleShape*>(projectileShape); // Downcast to circle shape
    if (circle) {
        circle->setRadius(5.f);            // Set radius of the projectile to 5 units
        circle->setOrigin(5.f, 5.f);       // Set origin to the center of the circle
        circle->setFillColor(sf::Color::Blue); // Set color to blue
    }
    
    // Set initial position
    setPosition(originPosition);
    setVelocity(originVelocity);
    
}

void Projectile::update(float deltaTime) {
    if (!isActive()) return;

    Object::update(deltaTime);

    // if projectile is not in screen
    if (getPosition().x < 0 || getPosition().x > 800 || getPosition().y < 0 || getPosition().y > 600) {
        setActive(false) ;
    }
}

//void Projectile::onCollision(Object& other) {
    //active = false;
    // Additional collision logic if needed
//}



sf::Shape* Projectile::cloneShape(const sf::Shape* shape) {
    //check sf::CircleShape 
    if (const sf::CircleShape* circle = dynamic_cast<const sf::CircleShape*>(shape)) {
        return new sf::CircleShape(*circle); // copy
    }
    // check sf::RectangleShape 
    else if (const sf::RectangleShape* rect = dynamic_cast<const sf::RectangleShape*>(shape)) {
        return new sf::RectangleShape(*rect); // 
    }
    
  //if can not recognize
    return nullptr; 