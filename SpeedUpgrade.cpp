#include "SpeedUpgrade.h"
#include "Player.h"

SpeedUpgrade::SpeedUpgrade(sf::Vector2f position)
    : Upgrade(position) {
    shape->setFillColor(sf::Color::Blue);
}

void SpeedUpgrade::applyToPlayer(Player& player) {
    player.setMaxVelocity(player.getMaxVelocity() + 50.f); // Increase player speed
    active = false;
}