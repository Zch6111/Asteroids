#include <SFML/Graphics.hpp>
#include <iostream>

#include "Object.h"
#include "Asteroid.h"
#include "AsteroidCluster.h"

int main()
{
    Player player;
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::Vector2f velocity(1.f, 0.5f);
    sf::Vector2f position(100.f, 150.f);

    int i = 0;

    AsteroidCluster a1(&player, position, velocity);

    // run the program as long as the window is open
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        float deltaTime = 60 * elapsed.asSeconds();
        i++;
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

        // check for user input

        if (i%500 == 0){
            a1.split(a1.getArray()[0], 0);
        }

        // update game
        a1.updateCluster(deltaTime);
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        for (int i=0; i<a1.getTotalAsteroids(); i++){
            window.draw(*(a1.getArray()[i]->getShape()));
        }
        // std::cout << a1.getTotalAsteroids() << std::endl;

        // end the current frame
        window.display();
    }

    return 0;
}
