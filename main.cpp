#include <SFML/Graphics.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::RectangleShape shape(sf::Vector2(100.f,50.f));
    shape.setPosition(150.f,150.f);

    float i = 0.f;

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

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        i+=0.001f;

        shape.rotate(i);

        window.draw(shape);

        // end the current frame
        window.display();
    }

    return 0;
}