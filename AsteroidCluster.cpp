#include "Asteroid.h"
#include "AsteroidCluster.h"
#include "Player.h"
#include "Projectile.h"

#include <iostream>

AsteroidCluster::AsteroidCluster(Player* player, sf::Vector2f originPosition, sf::Vector2f originVelocity){
    asteroids = new Asteroid*[1];
    asteroids[0] = new Asteroid(3, originPosition, originVelocity);
    totalAsteroids = 1;
    active = 1;
    this->player = player;
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
        for (int j = 0; j < player->getProjectiles()->size(); j++){
            if (asteroids[i]->checkCollision((*(player->getProjectiles()))[j])){
                split(asteroids[i], i);
                player->getProjectiles()->erase(player->getProjectiles()->begin() + j);
            }
        }
        if (asteroids[i]->isActive() == 1) {continue;}

        if (asteroids[i]->checkCollision(player)){
            player->setActive(0);
        }
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