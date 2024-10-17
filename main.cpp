#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "HighScores.h"
#include "Menu.h"
#include "Player.h"
#include "Upgrade.h"
#include "SpeedUpgrade.h"
#include "FireSpeedUpgrade.h"

int main() {
    // Create an SFML window with a resolution of 800x600
    sf::RenderWindow window(sf::VideoMode(800, 600), "Asteroids Game");

    // Create a Menu object with the same width and height as the window
    Menu menu(800, 600);

    // Create a HighScores object to store scores
    HighScores highScores("high_scores.txt");

    // Create a Player object
    Player player;

    // Create a list of upgrades using smart pointers
    std::vector<std::unique_ptr<Upgrade>> upgrades;
    upgrades.emplace_back(std::make_unique<SpeedUpgrade>(sf::Vector2f(100, 100), 5.0f));          // Position (100, 100), speed increase amount 5.0
    upgrades.emplace_back(std::make_unique<FireSpeedUpgrade>(sf::Vector2f(300, 300), 10.0f));   // Position (300, 300), fire speed decrease amount 10.0

    // Run the main menu
    menu.run(window, highScores, player);

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
            // Handle other events, such as keyboard input
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::W)
                    player.moveForward();
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

        // Update the player's state
        player.update(deltaTime);

        // Check for collisions between the player and upgrades, then apply upgrades
        for (auto& upgrade : upgrades) {
            if (upgrade->isActive() && player.checkCollision(*upgrade)) {
                upgrade->apply(player);          // Apply the upgrade to the player
                upgrade->setActive(false);       // Deactivate the upgrade
            }
        }

        // Render the game
        window.clear();

        // Render the player
        player.render(window);

        // Render active upgrades
        for (auto& upgrade : upgrades) {
            if (upgrade->isActive()) {
                upgrade->render(window);             // Only render active upgrades
            }
        }

        window.display();
    }

    // No need to manually delete upgrade objects; smart pointers manage memory automatically

    return 0;
}