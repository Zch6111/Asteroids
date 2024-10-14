#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "EasyEnemy.h"
#include "MediumEnemy.h"
#include "HardEnemy.h"
#include "Projectile.h"

// Helper function to simulate the game loop
void simulateEnemyBehavior(Enemy* enemy, std::vector<std::shared_ptr<Projectile>>& projectiles, float deltaTime) {
    // Call update to handle AI and cooldown
    enemy->update(deltaTime);

    // Call fireProjectile to simulate enemy trying to shoot
    enemy->fireProjectile(projectiles);
}

int main() {
    // Set up SFML shapes for enemies
    sf::CircleShape easyShape(15); // Circle shape for easy enemy
    sf::CircleShape mediumShape(20); // Circle shape for medium enemy
    sf::CircleShape hardShape(25); // Circle shape for hard enemy

    easyShape.setFillColor(sf::Color::Green);
    mediumShape.setFillColor(sf::Color::Yellow);
    hardShape.setFillColor(sf::Color::Red);

    // Create enemy objects
    EasyEnemy easyEnemy(&easyShape);
    MediumEnemy mediumEnemy(&mediumShape);
    HardEnemy hardEnemy(&hardShape);

    // Create a list to store projectiles
    std::vector<std::shared_ptr<Projectile>> projectiles;

    // Test 1: Ensure enemy objects are created correctly
    std::cout << "Testing Enemy Creation..." << std::endl;
    std::cout << "Easy Enemy - Lives: " << easyEnemy.getLives() << ", Speed: " << easyEnemy.getSpeed() << std::endl;
    std::cout << "Medium Enemy - Lives: " << mediumEnemy.getLives() << ", Speed: " << mediumEnemy.getSpeed() << std::endl;
    std::cout << "Hard Enemy - Lives: " << hardEnemy.getLives() << ", Speed: " << hardEnemy.getSpeed() << std::endl;

    // Test 2: Simulate game loop and enemy behavior
    float deltaTime = 0.1f; // 100ms per frame
    std::cout << "\nSimulating Enemy Behavior for 10 frames..." << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::cout << "\nFrame " << i + 1 << ":" << std::endl;

        std::cout << "Easy Enemy Position: " << easyEnemy.getPosition().x << ", " << easyEnemy.getPosition().y << std::endl;
        simulateEnemyBehavior(&easyEnemy, projectiles, deltaTime);

        std::cout << "Medium Enemy Position: " << mediumEnemy.getPosition().x << ", " << mediumEnemy.getPosition().y << std::endl;
        simulateEnemyBehavior(&mediumEnemy, projectiles, deltaTime);

        std::cout << "Hard Enemy Position: " << hardEnemy.getPosition().x << ", " << hardEnemy.getPosition().y << std::endl;
        simulateEnemyBehavior(&hardEnemy, projectiles, deltaTime);

        // Test 3: Check if projectiles are being fired
        std::cout << "Projectiles fired: " << projectiles.size() << std::endl;
    }

    // Test 4: Check cooldown system
    std::cout << "\nTesting Cooldown System..." << std::endl;
    std::cout << "Easy Enemy Cooldown: " << easyEnemy.getFireCooldown() << std::endl;
    std::cout << "Medium Enemy Cooldown: " << mediumEnemy.getFireCooldown() << std::endl;
    std::cout << "Hard Enemy Cooldown: " << hardEnemy.getFireCooldown() << std::endl;

    return 0;
}