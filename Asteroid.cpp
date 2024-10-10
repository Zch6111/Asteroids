#include"Asteroid.h"
#include"Object.h"
#include<vector>
#include <SFML/Graphics.hpp>

Asteroid::Asteroid(int size): Object(new sf::CircleShape(10 + size*size*3, 7)){
    sf::Shape* shape = getShape();
    
    shape->setOrigin(10 + size*size*3, 10 + size*size*3);
    (*shape).setFillColor(sf::Color(50, 50, 50));

    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(sf::Color(255, 255, 255));
    this->size = size;
};