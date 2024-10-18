#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Object.h"
#include "Player.h"
#include "Projectile.h"
#include "Upgrade.h"
#include "SpeedUpgrade.h"
#include "FireSpeedUpgrade.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    Player player;

    sf::Vector2f originPosition(100.f,100.f);

    SpeedUpgrade upgrade1(&player, originPosition, 10.f, 0.5f, 0.5f);
    FireSpeedUpgrade upgrade2(&player, originPosition+originPosition, 10.f, 5.f);

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
        player.update(deltaTime);
        upgrade1.update(deltaTime);
        upgrade2.update(deltaTime);
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(*(player.getShape()));
        for (int i=0; i < player.getProjectiles()->size(); i++){
            window.draw(*((*(player.getProjectiles()))[i]->getShape()));
        }
        if (upgrade1.isActive()) {window.draw(*(upgrade1.getShape()));}
        if (upgrade2.isActive()) {window.draw(*(upgrade2.getShape()));}
        
        // std::cout << a1.getTotalAsteroids() << std::endl;

        // end the current frame
        window.display();
    }

    return 0;
}
