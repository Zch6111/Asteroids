#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Object.h"

class Projectile: public Object{
public:
    Projectile(float speed, sf::Vector2f playerPosition, float playerRotation);
};

#endif