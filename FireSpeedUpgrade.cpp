#include "FireSpeedUpgrade.h"
#include"Player.h"

FireSpeedUpgrade::FireSpeedUpgrade(Player* player, sf::Vector2f originPosition, float fireSpeedDecrease, float projectileSpeedIncrease): Upgrade(player, new sf::CircleShape(10.f,4), originPosition){
    // set increase/decrease variables
    this->fireSpeedDecrease = fireSpeedDecrease;
    this->projectileSpeedIncrease = projectileSpeedIncrease;

    // set shape colour/origin
    sf::Shape* shape = getShape();
    shape->setFillColor(sf::Color::Blue);//fill color as blue
    shape->setOrigin(10.f, 10.f);// Set the origin to the center
} 

void FireSpeedUpgrade::apply(Player* player) {
    player->setFireSpeed(player->getFireSpeed() - fireSpeedDecrease);
    player->setProjectileSpeed(player->getProjectileSpeed() - projectileSpeedIncrease);
    if (player->getFireSpeed() < 0.f) {
        player->setFireSpeed(0.f); // Ensure fireSpeed doesn't become negative
    }
    setActive(false); // Deactivate the upgrade after applying
}