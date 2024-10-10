
#include <SFML/Graphics.hpp>

#include "Object.h"
#include "Asteroid.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    Object* test1 = new Asteroid(3);
    Object* test2 = new Asteroid(2);

    sf::Vector2f velocity(1.f, 0.5f);
    sf::Vector2f position(100.f, 150.f);
    test1->setVelocity(velocity);
    test1->setRotationSpeed(1.f);


    test2->setVelocity(velocity);
    test2->setRotationSpeed(2.f);
    test2->setPosition(position);

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
        }

        // check for user input

        // update game
        test1->update(deltaTime);
        test2->update(deltaTime);
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(*(test1->getShape()));
        window.draw(*(test2->getShape()));
        // end the current frame
        window.display();
    }

    return 0;
}
