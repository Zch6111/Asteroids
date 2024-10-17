#include"Asteroid.h"
#include"Object.h"
#include<vector>
#include <SFML/Graphics.hpp>

int Asteroid::score = 0;
const sf::Vector2f ScreenWidth(800.f, 0);
const sf::Vector2f ScreenHeight(0, 600.f);

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

void Asteroid::update(float deltaTime){
    Object::update(deltaTime); // Call object update funtion

    // Wrap the object around the screen
    if (getPosition().x > 800){
        setPosition(getPosition() - ScreenWidth);
    }
    if (getPosition().x < 0){
        setPosition(getPosition() + ScreenWidth);
    }
    if (getPosition().y > 600){
        setPosition(getPosition() - ScreenHeight);
    }
    if (getPosition().y < 0){
        setPosition(getPosition() + ScreenHeight);
    }

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