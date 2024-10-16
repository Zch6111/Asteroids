#ifndef ASTEROID_H
#define ASTEROID_H

#include "Object.h"

class Asteroid: public Object{
private:
    int size;
public:
    Asteroid(int size);
    Asteroid(int size, sf::Vector2f originPosition, sf::Vector2f originVelocity);

    int getSize();
};

#endif