#include "SpeedUpgrade.h"

SpeedUpgrade::SpeedUpgrade(Player* player, sf::Vector2f originPosition, float maxVelocityIncrease, float accelerationIncrease): Upgrade(player, new sf::CircleShape(10.f, 4), originPosition){
    // set increase/decrease variables
    this->maxVelocityIncrease = maxVelocityIncrease;
    this->accelerationIncrease = accelerationIncrease;

    // set shape colour/origin
    sf::Shape* shape = getShape();
    shape->setFillColor(sf::Color::Blue);  // Set the color to blue
    shape->setOrigin(10.f, 10.f);  // Set the origin to the center
}

void SpeedUpgrade::apply(Player* player) {
    player->setMaxVelocity(player->getMaxVelocity() + maxVelocityIncrease);
    player->setAcceleration(player->getAcceleration() + accelerationIncrease);
    setActive(false); // Deactivate the upgrade after applying
}