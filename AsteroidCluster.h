#ifndef ASTEROIDCLUSTER_H
#define ASTEROIDCLUSTER_H

#include "Asteroid.h"

class AsteroidCluster{
private:
    Asteroid** asteroids;
    int totalAsteroids;
public:
    AsteroidCluster(sf::Vector2f originPosition, sf::Vector2f originVelocity);
    void checkCluster();
    void split(Asteroid* parentAsteroid, int arrayPosition);
};

#endif