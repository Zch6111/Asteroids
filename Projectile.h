#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Object.h"

class Projectile : public Object {
public:
    Projectile(sf::Shape* projectileShape, sf::Vector2f originPosition, sf::Vector2f originVelocity);
    void update(float deltaTime) ;
   // void onCollision(Object& other) override;

   static sf::Shape* cloneShape(const sf::Shape* shape);
};

#endif