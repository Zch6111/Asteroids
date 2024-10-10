
#include <SFML/Graphics.hpp>

#include "Object.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    Object test;

    sf::Vector2f velocity(2.f, 1.5f);
    test.setVelocity(velocity);
    test.setRotationSpeed(2.f);

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
        test.update(deltaTime);
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(test.getShape());
        // end the current frame
        window.display();
    }

    return 0;
}
