#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Object.h"
#include "Asteroid.h"
#include "AsteroidCluster.h"
#include "Player.h"
#include "Projectile.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    Player player;

    AsteroidCluster* a1;
    sf::Vector2f velocity(1.f, 1.f);
    sf::Vector2f position(100.f, 150.f);

    std::vector<AsteroidCluster*> allAsteroids;
    a1 = new AsteroidCluster(&player, position, velocity);
    allAsteroids.push_back(a1);

    // run the program as long as the window is open
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        float deltaTime = 60 * elapsed.asSeconds();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            // player movement
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                player.moveFoward();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                player.moveBackward();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                player.turnLeft();
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                player.turnRight();
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                player.fire();
        }

        // update game
        for (int i=0; i < allAsteroids.size(); i++){
            allAsteroids[i]->updateCluster(deltaTime);
        }
        player.update(deltaTime);
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        for (int i=0; i < allAsteroids.size(); i++){
            for (int j=0; j < (allAsteroids[i]->getTotalAsteroids()); j++){
                window.draw(*((allAsteroids[i]->getArray())[j]->getShape()));
            }
        }
        window.draw(*(player.getShape()));
        for (int i=0; i < player.getProjectiles()->size(); i++){
            window.draw(*((*(player.getProjectiles()))[i]->getShape()));
        }
        // std::cout << a1.getTotalAsteroids() << std::endl;

        // end the current frame
        window.display();
    }

    return 0;
}
