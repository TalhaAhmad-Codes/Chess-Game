#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.hpp"

void sfml_demo(unsigned int, unsigned int);

int main()
{
    Entity::Player player("Talha Ahmad", 15);

    player.increment_score();
    player.decrement_score();
    player.decrement_score();

    std::cout << "Name:\t" << player.get_name() << '\n'
              << "Score:\t" << player.get_score() << std::endl;
    
    //sfml_demo(500);
}

void sfml_demo(unsigned int resolution, unsigned int offset = 1)
{
    if (offset == 0)
        return;

    // Some values for the resolution of window and offset for the circile
    unsigned int resX = resolution, resY = resX;

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
