#include "SpeedUpgrade.h"

SpeedUpgrade::SpeedUpgrade(sf::Vector2f originPosition, float increaseAmount)
    : Upgrade(new sf::CircleShape(10.f), originPosition), speedIncrease(increaseAmount) {
    sf::Shape* shape = getShape();
    shape->setFillColor(sf::Color::Green);
    shape->setOrigin(10.f, 10.f);
}

void SpeedUpgrade::apply(Player& player) {
    player.setMaxVelocity(player.getMaxVelocity() + speedIncrease);
    setActive(false); // Deactivate the upgrade after applying
}