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

    std::vector<AsteroidCluster*> allAsteroids;

    AsteroidCluster* a1;

    sf::Vector2f velocity(5.f, 5.f);
    sf::Vector2f position(100.f, 150.f);

    a1 = new AsteroidCluster(position, velocity);

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
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                std::cout << Asteroid::getScore() << std::endl;
        }

        // update game
        for (int i=0; i < allAsteroids.size(); i++){
            allAsteroids[i]->updateCluster(deltaTime);
        }
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        for (int i=0; i < allAsteroids.size(); i++){
            for (int j=0; j < (allAsteroids[i]->getTotalAsteroids()); j++){
                window.draw(*((allAsteroids[i]->getArray())[j]->getShape()));
            }
        }
        // std::cout << a1.getTotalAsteroids() << std::endl;

        // end the current frame
        window.display();
    }

    return 0;
}
