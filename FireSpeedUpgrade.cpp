#include "FireSpeedUpgrade.h"
#include"Player.h"

FireSpeedUpgrade::FireSpeedUpgrade(sf::Vector2f originPosition, float decreaseAmount)
    : Upgrade(new sf::CircleShape(10.f), originPosition), cooldownDecrease(decreaseAmount) {
    sf::Shape* shape = getShape();
    shape->setFillColor(sf::Color::Blue);//fill color as blue
    shape->setOrigin(10.f, 10.f);// Set the origin to the center

    shape->setPosition(originPosition); // Set the initial position
} 

void FireSpeedUpgrade::apply(Player& player) {
    player.setFireCooldown(player.getFireCooldown() - cooldownDecrease);
    if (player.getFireCooldown() < 0.f) {
        player.setFireCooldown(0.f); // Ensure fireSpeed doesn't become negative
    }
    setActive(false); // Deactivate the upgrade after applying
}