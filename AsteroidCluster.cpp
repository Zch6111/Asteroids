#include "Asteroid.h"
#include "AsteroidCluster.h"

#include <iostream>

AsteroidCluster::AsteroidCluster(sf::Vector2f originPosition, sf::Vector2f originVelocity){
    asteroids = new Asteroid*[1];
    asteroids[0] = new Asteroid(3, originPosition, originVelocity);
    totalAsteroids = 1;
    active = 1;
};

void AsteroidCluster::updateCluster(float deltaTime){
    if (active == 0){return;}
    checkCluster();

    for (int i = 0; i < totalAsteroids; i++){
        asteroids[i]->update(deltaTime);
    }
};

void AsteroidCluster::checkCluster(){
    for (int i = 0; i < totalAsteroids; i++){
        if (asteroids[i]->isActive() == 1) {continue;}

        split(asteroids[i], i);
    }
};

void AsteroidCluster::split(Asteroid* parentAsteroid, int arrayPosition){
    if (active == 0) {return;}
    if (parentAsteroid->getSize() <= 1 && totalAsteroids <= 1){
        std::cout << Asteroid::getScore() << " deleting final asteroid" << std::endl;
        delete parentAsteroid;
        active = 0;
        totalAsteroids--;
        return;
    }

    if (parentAsteroid->getSize() <= 1) {
        std::cout << Asteroid::getScore() << " deleting mini" << std::endl;
        Asteroid** newAsteroids = new Asteroid*[totalAsteroids-1];

        int j = 0;
        for (int i = 0; i < totalAsteroids; i++){
            if (i == arrayPosition) {continue;}
            newAsteroids[j] = asteroids[i];
            j++;
        }
        
        delete parentAsteroid;
        asteroids = newAsteroids;
        totalAsteroids--;
    } else {
        std::cout << Asteroid::getScore() << " deleting big asteroid" << std::endl;
        sf::Vector2f newVelocity(parentAsteroid->getVelocity().y, -parentAsteroid->getVelocity().x);

        Asteroid* childAsteroidA;
        childAsteroidA = new Asteroid(parentAsteroid->getSize()-1, parentAsteroid->getPosition(), parentAsteroid->getVelocity()+newVelocity);
        Asteroid* childAsteroidB;
        childAsteroidB = new Asteroid(parentAsteroid->getSize()-1, parentAsteroid->getPosition(), parentAsteroid->getVelocity()-newVelocity);

        Asteroid** newAsteroids = new Asteroid*[totalAsteroids+1];

        int j = 0;
        for (int i = 0; i < totalAsteroids; i++){
            if (i == arrayPosition) {continue;}
            newAsteroids[j] = asteroids[i];
            j++;
        }

        newAsteroids[j] = childAsteroidA;
        newAsteroids[j+1] = childAsteroidB;

        delete parentAsteroid;
        asteroids = newAsteroids;
        totalAsteroids++;
    }
};

Asteroid** AsteroidCluster::getArray(){
    return asteroids;
};
int AsteroidCluster::getTotalAsteroids(){
    return totalAsteroids;
};