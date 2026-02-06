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
        Entity::Piece piece(Interface::PieceType::ROOK, Interface::PieceGroup::WHITE, Utils::Position(4, 4));
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                Utils::Position target(i, j);
                piece.get_position().display("Current:\t");
                target.display("Target:\t\t");
                bool is_success = true;

                try
                {
                    piece.move(target);
                }
                catch (const Shield::DomainException& ex)
                {
                    is_success = false;
                }
                std::cout << "Status:\t\t";
                (is_success) ? std::cout << "Valid" : std::cout << "In-valid";
                std::cout << "\n\n";
            }
        }
        
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
