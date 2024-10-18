#include <SFML/Graphics.hpp>

#include "HighScores.h"
#include "Menu.h"
#include "Object.h"
#include "Player.h"
#include "Projectile.h"
#include "Asteroid.h"
#include "AsteroidCluster.h"
#include "Upgrade.h"
#include "SpeedUpgrade.h"
#include "FireSpeedUpgrade.h"


int main() {
    // Create an SFML window with 800x600 resolution
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Menu");

    // Create a Menu object with the same width and height as the window
    Menu menu(800, 600);

    // Create a HighScores object with a file to store the scores
    HighScores highScores("high_scores.txt");

    // Create Player
    Player player;

    // Create vectors for Asteroids and Upgrades
    std::vector<AsteroidCluster*> allAsteroids;
    std::vector<Upgrade*> allUpgrades;


    
    // Start with the main menu
    menu.run(window, highScores, player, allAsteroids, allUpgrades);

    return 0;
}
