#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "DomainException.hpp"
#include "Position.hpp"

void sfml_demo(const unsigned int&, const unsigned int& = 1);

int main()
{
    //try
    //{
    //    /*Entity::Player player("TalhaAhmad", 15);

    //    player.increment_score(1);
    //    player.decrement_score(2);

    //    std::cout << "Name:\t" << player.get_name() << '\n'
    //        << "Score:\t" << player.get_score() << std::endl;*/

    //    Utils::Position pos1(2, 3), pos2(1, 4), pos3;

    //    pos1.display("Position 1:\t");
    //    pos2.display("Position 2:\t");

    //    pos3 = pos1 + pos2;
    //    pos3.display("Addition:\t");

    //    pos3 = pos1 - pos2;
    //    pos3.display("Subtraction:\t");

    //    pos3 = Utils::Position::abs_difference(pos1, pos2);
    //    pos3.display("Abs-difference:\t");
    //}
    //catch (const Shield::DomainException& ex)
    //{
    //    std::cout << ex.what() << std::endl;
    //}
    
    sfml_demo(500, 10);
}

void sfml_demo(const unsigned int& resolution, const unsigned int& offset)
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
