#include <iostream>
#include <SFML/Graphics.hpp>
#include "EasyEnemy.h"
#include "MediumEnemy.h"
#include <iostream>
#include "Projectile.h"

int main() {
    // create a projectile
    sf::RectangleShape* projectileShape = new sf::RectangleShape(sf::Vector2f(5.f, 10.f));
    projectileShape->setFillColor(sf::Color::Yellow);

    // initial position direction spped
    sf::Vector2f startPosition(400.f, 300.f);
    sf::Vector2f direction(1.f, 0.f); // move yo right
    float speed = 200.f;

    // create Projectile 
    Projectile projectile(projectileShape, speed, startPosition, direction, nullptr);

    // print status
    std::cout << "Initial Position: (" << projectile.getPosition().x << ", " << projectile.getPosition().y << ")\n";
    std::cout << "Initial Active Status: " << projectile.isActive() << "\n";

    // update
    float deltaTime = 1.0f; // 1秒
    projectile.update(deltaTime);

    // after status
    std::cout << "After Update Position: (" << projectile.getPosition().x << ", " << projectile.getPosition().y << ")\n";
    std::cout << "Active Status after Update: " << projectile.isActive() << "\n";

    // bound check
    projectile.checkOutOfBounds();
    std::cout << "Active Status after Out-of-Bounds Check: " << projectile.isActive() << "\n";

    // delete
    delete projectileShape;

    return 0;
}
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