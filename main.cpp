#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <iostream>

#include "Player.h"
#include "Upgrade.h"
#include "SpeedUpgrade.h"

int main() {
    // Create an SFML window with 800x600 resolution
    sf::RenderWindow window(sf::VideoMode(800, 600), "Asteroids Game");

    // Create a player object
    Player player;

    // Set the player’s initial position at the center of the screen
    player.setPosition(sf::Vector2f(400.f, 300.f));

    // Create a list of upgrades (only the player can interact with them)
    std::vector<std::unique_ptr<Upgrade>> upgrades;

    // Add a SpeedUpgrade at position (200, 200) with a speed increase of 5.0
    upgrades.emplace_back(std::make_unique<SpeedUpgrade>(sf::Vector2f(200.f, 200.f), 5.0f));

    // Main game loop
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Handle player input for movement and actions
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::W)
                    player.moveFoward();
                if (event.key.code == sf::Keyboard::S)
                    player.moveBackward();
                if (event.key.code == sf::Keyboard::A)
                    player.turnLeft();
                if (event.key.code == sf::Keyboard::D)
                    player.turnRight();
                if (event.key.code == sf::Keyboard::Space)
                    player.fire();
            }
        }

        // Update player state
        player.update(deltaTime);

        // Check for collisions between the player and upgrades
        for (auto& upgrade : upgrades) {
            if (upgrade->isActive() && player.checkCollision(*upgrade)) {
                std::cout << "Player collected a SpeedUpgrade!" << std::endl;
                upgrade->apply(player);   // Apply the upgrade effect
                upgrade->setActive(false); // Set the upgrade to inactive
            }
        }

        // Render section
        window.clear(sf::Color::Black);  // Clear the window with a black background

        // Render the player
        player.render(window);

        // Render all active upgrades
        for (auto& upgrade : upgrades) {
            if (upgrade->isActive()) {
                upgrade->render(window);  // Only render active upgrades
            }
        }

        window.display();  // Display the rendered frame
    }

    return 0;
}