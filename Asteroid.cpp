#include"Asteroid.h"
#include"Object.h"
#include<vector>
#include <SFML/Graphics.hpp>

int Asteroid::score = 0;

Asteroid::Asteroid(int size): Object(new sf::CircleShape(10 + size*size*3, 7)){
    sf::Shape* shape = getShape();
    
    shape->setOrigin(10 + size*size*3, 10 + size*size*3);
    (*shape).setFillColor(sf::Color(50, 50, 50));

    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(sf::Color(255, 255, 255));
    this->size = size;
};
Asteroid::Asteroid(int size, sf::Vector2f originPosition, sf::Vector2f originVelocity): Object(new sf::CircleShape(10 + size*size*3, 7), originPosition, originVelocity, originPosition.x*originPosition.y, 2.f){
    sf::Shape* shape = getShape();
    
    shape->setOrigin(10 + size*size*3, 10 + size*size*3);
    (*shape).setFillColor(sf::Color(50, 50, 50));

    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(sf::Color(255, 255, 255));
    this->size = size;
};
Asteroid::~Asteroid(){
    score += 25 + 15*size;
};

int Asteroid::getScore(){
    return score;
};
int Asteroid::clearScore(){
    score = 0;
};
int Asteroid::getSize(){
    return size;
};