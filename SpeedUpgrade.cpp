#include "SpeedUpgrade.h"

SpeedUpgrade::SpeedUpgrade(Player* player, sf::Vector2f originPosition): Upgrade(player, new sf::CircleShape(15.f, 4), originPosition){
    // set shape colour/origin
    sf::Shape* shape = getShape();
    shape->setFillColor(sf::Color::Blue);  // Set the color to blue
    shape->setOrigin(10.f, 10.f);  // Set the origin to the center

    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(sf::Color(255, 255, 255));
}

void SpeedUpgrade::apply(Player* player) {
    player->setMaxVelocity(player->getMaxVelocity() + maxVelocityIncrease);
    player->setAcceleration(player->getAcceleration() + accelerationIncrease);
    player->setDeceleration(player->getDeceleration() * decelerationMultiplier);
    setActive(false); // Deactivate the upgrade after applying
}