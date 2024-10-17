#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

#include "Player.h"
#include "Upgrade.h"
#include "SpeedUpgrade.h"
#include "FireSpeedUpgrade.h"

int main() {
    Player player;
    std::cout << "Initial Player Max Velocity: " << player.getMaxVelocity() << std::endl;

    std::unique_ptr<Upgrade> speedUpgrade = std::make_unique<SpeedUpgrade>(sf::Vector2f(100.f, 100.f), 20.f);
    std::unique_ptr<Upgrade> fireSpeedUpgrade = std::make_unique<FireSpeedUpgrade>(sf::Vector2f(200.f, 200.f), 10.f);

    std::cout << "Before Applying Upgrades:\n";
    std::cout << "SpeedUpgrade isActive: " << speedUpgrade->isActive() << std::endl;

    if (player.checkCollision(*speedUpgrade)) {
        speedUpgrade->apply(player);
    }

    std::cout << "After Applying SpeedUpgrade:\n";
    std::cout << "Player Max Velocity: " << player.getMaxVelocity() << std::endl;

    return 0;
}