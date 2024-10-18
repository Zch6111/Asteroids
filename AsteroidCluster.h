#ifndef ASTEROIDCLUSTER_H
#define ASTEROIDCLUSTER_H

#include "Asteroid.h"
#include "Player.h"

class AsteroidCluster{
private:
    Asteroid** asteroids;
    int totalAsteroids;
    bool active;
    Player* player;
public:
    AsteroidCluster(Player* player, sf::Vector2f originPosition, sf::Vector2f originVelocity);
    void updateCluster(float deltaTime);
    void checkCluster();
    void split(Asteroid* parentAsteroid, int arrayPosition);
    Asteroid** getArray();
    int getTotalAsteroids();
};

#endif