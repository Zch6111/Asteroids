

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Player.h"
#include "Enemy.h"
#include "EasyEnemy.h"
#include "MediumEnemy.h"
#include "HardEnemy.h"
#include "Projectile.h"
#include "Upgrade.h"
#include "LivesUpgrade.h"
#include "FireSpeedUpgrade.h"
#include "SpeedUpgrade.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "OOP Major Project");
    window.setFramerateLimit(60);

    // Create player
    Player player;

    // Create some enemies
    std::vector<std::shared_ptr<Enemy>> enemies;
    enemies.push_back(std::make_shared<EasyEnemy>(new sf::CircleShape(15.f)));
    enemies.push_back(std::make_shared<MediumEnemy>(new sf::CircleShape(20.f)));
    enemies.push_back(std::make_shared<HardEnemy>(new sf::CircleShape(25.f)));

    // Create some upgrades
    std::vector<std::shared_ptr<Upgrade>> upgrades;
    upgrades.push_back(std::make_shared<LivesUpgrade>());
    upgrades.push_back(std::make_shared<FireSpeedUpgrade>(0.1f));
    upgrades.push_back(std::make_shared<SpeedUpgrade>(5.f));

    // List of all objects for collision detection
    std::vector<std::shared_ptr<Object>> allObjects;
    allObjects.push_back(std::make_shared<Player>(player));
    for(auto& enemy : enemies) allObjects.push_back(enemy);
    for(auto& upgrade : upgrades) allObjects.push_back(upgrade);

    // List to hold projectiles
    std::vector<std::shared_ptr<Projectile>> projectiles;

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            // Handle player input for movement and firing
            if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::W)
                    player.moveForward();
                if(event.key.code == sf::Keyboard::S)
                    player.moveBackward();
                if(event.key.code == sf::Keyboard::A)
                    player.turnLeft();
                if(event.key.code == sf::Keyboard::D)
                    player.turnRight();
                if(event.key.code == sf::Keyboard::Space)
                    player.fireProjectile(projectiles);
            }
        }

        float deltaTime = clock.restart().asSeconds();

        // Update all objects
        player.update(deltaTime);
        for(auto& enemy : enemies)
            enemy->update(deltaTime);
        for(auto& upgrade : upgrades)
            upgrade->update(deltaTime);
        for(auto& projectile : projectiles)
            projectile->update(deltaTime);

        // Collision detection
        for(auto& obj1 : allObjects) {
            if(!obj1->isActive()) continue;
            for(auto& obj2 : allObjects) {
                if(obj1 == obj2 || !obj2->isActive()) continue;
                if(obj1->checkCollision(*obj2)) {
                    obj1->onCollision(*obj2);
                    obj2->onCollision(*obj1);
                }
            }
        }

        // Remove inactive objects
        allObjects.erase(std::remove_if(allObjects.begin(), allObjects.end(),
            [](const std::shared_ptr<Object>& obj) { return !obj->isActive(); }), allObjects.end());

        // Clear the window
        window.clear();

        // Render all active objects
        for(auto& obj : allObjects)
            window.draw(*obj->getShape());

        window.display();
    }

    return 0;
}