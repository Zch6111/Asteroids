#include <iostream>
#include "Projectile.h"

int main() {
    // create
    sf::RectangleShape* projectileShape = new sf::RectangleShape(sf::Vector2f(5.f, 10.f));
    projectileShape->setFillColor(sf::Color::Yellow);

    // initial postition direction and speed
    sf::Vector2f startPosition(400.f, 300.f);
    sf::Vector2f direction(1.f, 0.f);
    
    float speed = 200.f;

    //  Projectile example
    Projectile projectile(projectileShape, speed, startPosition, direction, nullptr);

    // status
    std::cout << "Initial Position: (" << projectile.getPosition().x << ", " << projectile.getPosition().y << ")\n";
    std::cout << "Initial Active Status: " << projectile.isActive() << "\n";

    // update
    float deltaTime = 1.0f; // 1 second
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