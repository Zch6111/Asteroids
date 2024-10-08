
#include <SFML/Graphics.hpp>

#include "Object.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    Object test;

    sf::Vector2f velocity(2.f, 1.5f);
    test.setVelocity(velocity);

    // run the program as long as the window is open
    while (window.isOpen())
    {
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
        test.update();
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
