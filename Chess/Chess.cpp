#include <SFML/Graphics.hpp>

int main()
{
    // Some values for the resolution of window and offset for the circile
    unsigned int resX = 200, resY = resX, offset = resX / 10;

    // Setting up the main window
    sf::RenderWindow window(sf::VideoMode({ resX, resY }), "SFML works!");
    
    // Drawing a circle on the window
    sf::CircleShape shape(resX / 2 - offset);
    shape.setFillColor(sf::Color::White);   // Color of the circle

    // Window main loop -- while the window is running
    while (window.isOpen())
    {
        // Handling events
        while (const std::optional event = window.pollEvent())
        {
            // Pressing close button -- event
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Clear the window
        window.clear();

        // Draw circle shape again
        window.draw(shape);

        // Display the window screen again
        window.display();
    }
}
