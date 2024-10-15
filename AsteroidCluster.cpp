#include "Asteroid.h"
#include "AsteroidCluster.h"

AsteroidCluster::AsteroidCluster(sf::Vector2f originPosition, sf::Vector2f originVelocity){
    asteroids = new Asteroid*[1];
    asteroids[0] = new Asteroid(3, originPosition, originVelocity);
    totalAsteroids = 1;
};

void AsteroidCluster::checkCluster(){
    for (int i = 0; i++; i < totalAsteroids){
        if (asteroids[i]->isActive() == 1) {continue;}

        split(asteroids[i], i);
    }
};

void AsteroidCluster::split(Asteroid* parentAsteroid, int arrayPosition){
    if (parentAsteroid->getSize() <= 1) {
        Asteroid** newAsteroids = new Asteroid*[totalAsteroids-1];

        int j = 0;
        for (int i = 0; i++; i < totalAsteroids){
            if (i == arrayPosition) {continue;}
            newAsteroids[j] = asteroids[i];
            j++;
        }
        
        delete parentAsteroid;
        asteroids = newAsteroids;
        totalAsteroids--;
    }
    
    Asteroid* childAsteroidA;
    childAsteroidA = new Asteroid(parentAsteroid->getSize()-1, parentAsteroid->getPosition(), parentAsteroid->getVelocity());
    Asteroid* childAsteroidB;
    childAsteroidB = new Asteroid(parentAsteroid->getSize()-1, parentAsteroid->getPosition(), parentAsteroid->getVelocity());
};