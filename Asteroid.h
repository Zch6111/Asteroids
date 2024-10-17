#ifndef ASTEROID_H
#define ASTEROID_H

#include "Object.h"

class Asteroid: public Object{
private:
    static int score;
    int size;
public:
    Asteroid(int size);
    Asteroid(int size, sf::Vector2f originPosition, sf::Vector2f originVelocity);
    ~Asteroid();

    static int getScore();
    static int clearScore();
    int getSize();
};


#endif