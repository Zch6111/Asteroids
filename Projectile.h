#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Object.h"

class Projectile: public Object{
public:
    Projectile(float speed, sf::Vector2f originPosition, sf::Vector2f originVelocity, float originRotation);
};

#endif