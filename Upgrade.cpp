#include "Upgrade.h"

#include <iostream>

Upgrade::Upgrade(Player* player, sf::Shape* objectShape, sf::Vector2f originPosition): Object(objectShape, originPosition, sf::Vector2f(0.f, 0.f), 0.f, 0.f) {
    this->player = player;
}// Initialize the upgrade object

void Upgrade::update(float deltaTime){
    if (isActive() == 0) {return;}

    Object::update(deltaTime);

    for (int i = 0; i < player->getProjectiles()->size(); i++){
        if (checkCollision((*(player->getProjectiles()))[i])){
            apply(player);
            setActive(0);
            return;
        }
    }
};