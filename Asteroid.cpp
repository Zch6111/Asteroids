#include"Asteroid.h"
#include"Object.h"
#include<vector>
#include <SFML/Graphics.hpp>

Asteroid::Asteroid(): Object(new sf::CircleShape(25.f, 7)){
    sf::Shape* shape = getShape();
    shape->setOrigin(25.f,25.f);
    (*shape).setFillColor(sf::Color(150, 50, 250));
};