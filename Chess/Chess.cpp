#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "DomainException.hpp"
#include "Position.hpp"

#include "Piece.hpp"
#include "Board.hpp"

void sfml_demo(const unsigned int&);

int main()
{
    try {
        Entity::Board board;
        board.move_piece(Utils::Position(0, 2), Utils::Position(2, 4));
        board.move_piece(Utils::Position(2, 4), Utils::Position(4, 6));
        //board.move_piece(Utils::Position(4, 6), Utils::Position(5, 4));
        board.display();
    }
    catch (const Shield::DomainException ex) {
        std::cout << "\nError:\t" << ex.what() << std::endl;
    }

    /*Utils::Position from(4, 4), to(0, 7), offset = to - from;
    from.display("From:\t");
    to.display("To:\t");
    offset.display("Offset:\t");*/
}

void sfml_demo(const unsigned int& resolution)
{
    // Some values for the resolution of window and offset for the circile
    unsigned int resX = resolution, resY = resX;

    // Setting up the main window
    sf::RenderWindow window(sf::VideoMode({ resX, resY }), "SFML works!");

    // Drawing a circle on the window
    sf::CircleShape shape(resX / 2);
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
