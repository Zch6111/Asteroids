#include "SpeedUpgrade.h"
#include "Player.h"

SpeedUpgrade::SpeedUpgrade(sf::Vector2f position) : Upgrade(position) {
    sf::Shape* shape = getShape();
    shape->setFillColor(sf::Color::Blue); // Set color to blue for speed upgrade
}
 
void SpeedUpgrade::applyToPlayer(Player& player) {
    player.setMaxVelocity(player.getMaxVelocity() + 2.f); // Increase player speed
    setActive(false); // Deactivate the upgrade after use
}