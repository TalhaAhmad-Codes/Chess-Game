#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "DomainException.hpp"
#include "Position.hpp"

#include "Piece.hpp"

void sfml_demo(const unsigned int&);

int main()
{
    try {
        const int row = 3, column = 3;
        Entity::Piece piece(Interface::PieceType::KING, Interface::PieceGroup::WHITE, Utils::Position(row, column));
        piece.display_info();

        piece.move(Utils::Position(row - 1, column + 1));
        piece.display_info();

        piece.move(Utils::Position(row + 2, column));
        piece.display_info();
    }
    catch (const Shield::DomainException ex) {
        std::cout << "\nError:\t" << ex.what() << std::endl;
    }
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
