#include <iostream>
#include <SFML/Graphics.hpp>
#include "EasyEnemy.h"
#include "MediumEnemy.h"
#include "HardEnemy.h"
#include "Projectile.h"

int main() {
    sf::CircleShape easyShape(20.f);
    easyShape.setFillColor(sf::Color::Green);

    sf::CircleShape mediumShape(25.f);
    mediumShape.setFillColor(sf::Color::Yellow);

    sf::CircleShape hardShape(30.f);
    hardShape.setFillColor(sf::Color::Red);

    EasyEnemy easyEnemy(&easyShape);
    MediumEnemy mediumEnemy(&mediumShape);
    HardEnemy hardEnemy(&hardShape);

    std::vector<std::shared_ptr<Projectile>> projectiles;

    float deltaTime = 0.1f;  // 100ms

    for (int frame = 0; frame < 10; ++frame) {
        std::cout << "Frame " << frame + 1 << std::endl;

        easyEnemy.update(deltaTime);
        easyEnemy.fireProjectile(projectiles);

        mediumEnemy.update(deltaTime);
        mediumEnemy.fireProjectile(projectiles);

        hardEnemy.update(deltaTime);
        hardEnemy.fireProjectile(projectiles);

        std::cout << "Projectiles fired: " << projectiles.size() << std::endl;
    }

    return 0;
}