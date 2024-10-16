#include <SFML/Graphics.hpp>

#include "EasyEnemy.h"
#include "Player.h"
#include "Projectile.h"
#include "SpeedUpgrade.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Asteroids Remake");
  window.setFramerateLimit(60);

  Player player;
  EasyEnemy enemy;
  enemy.setPosition(sf::Vector2f(100.f, 100.f));

  std::vector<Projectile*> projectiles;
  std::vector<Projectile*> enemyProjectiles;
  std::vector<Upgrade*> upgrades;

  SpeedUpgrade* speedUpgrade = new SpeedUpgrade(sf::Vector2f(400.f, 300.f));
  upgrades.push_back(speedUpgrade);

  sf::Clock clock;

  while (window.isOpen()) {
    float deltaTime = clock.restart().asSeconds();

    // Event Handling
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    // Input Handling
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      player.moveForward(deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      player.moveBackward(deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      player.turnLeft(deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      player.turnRight(deltaTime);

    // Update
    player.update(deltaTime);
    enemy.update(deltaTime, enemyProjectiles);
    enemy.fireProjectile(enemyProjectiles);

    for (auto& proj : projectiles) proj->update(deltaTime);
    for (auto& eProj : enemyProjectiles) eProj->update(deltaTime);

    // Collision Detection
    if (player.checkCollision(enemy)) {
      player.onCollision(enemy);
      enemy.onCollision(player);
    }

    for (auto& proj : projectiles) {
      if (proj->checkCollision(enemy)) {
        proj->onCollision(enemy);
        enemy.onCollision(*proj);
      }
    }

    for (auto& upgrade : upgrades) {
      if (player.checkCollision(*upgrade)) {
        upgrade->applyToPlayer(player);
      }
    }

    // Clean up inactive projectiles
    projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(),
                                     [](Projectile* p) {
                                       if (!p->isActive()) {
                                         delete p;
                                         return true;
                                       } else
                                         return false;
                                     }),
                      projectiles.end());

    enemyProjectiles.erase(
        std::remove_if(enemyProjectiles.begin(), enemyProjectiles.end(),
                       [](Projectile* p) {
                         if (!p->isActive()) {
                           delete p;
                           return true;
                         } else
                           return false;
                       }),
        enemyProjectiles.end());

    // Render
    window.clear();
    window.draw(player);
    window.draw(enemy);

    for (auto& proj : projectiles) window.draw(*proj);

    for (auto& eProj : enemyProjectiles) window.draw(*eProj);

    for (auto& upgrade : upgrades) window.draw(*upgrade);

    window.display();
  }

  // Clean up
  for (auto& proj : projectiles) delete proj;
  for (auto& eProj : enemyProjectiles) delete eProj;
  for (auto& upgrade : upgrades) delete upgrade;

  return 0;
}

// g++ main.cpp Player.cpp Object.cpp Enemy.cpp EasyEnemy.cpp Projectile.cpp
// Upgrade.cpp SpeedUpgrade.cpp -lsfml-graphics -lsfml-window -lsfml-system
// -std=c++11