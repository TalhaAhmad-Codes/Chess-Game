#include <iostream>
#include <SFML/Graphics.hpp>
#include <conio.h>

#include "Player.hpp"
#include "DomainException.hpp"
#include "Position.hpp"

#include "Piece.hpp"
#include "Board.hpp"

void sfml_demo(const unsigned int&);

struct Status
{
    Utils::Position From;
    Utils::Position To;
    bool Validity;
};

int main()
{
    try {
        Entity::Board board;
        
        // Placing piece onto board
        Utils::Position position(4, 4);
        auto cell = board.get_cell(position);
        cell->place_piece(new Entity::Piece(Interface::PieceType::BISHOP, Interface::PieceGroup::WHITE, position));

        // Status initial value
        Status status;
        status.From = position;
        status.To = position;
        status.Validity = false;

        while (true)
        {
            system("cls");

            // Display status
            std::cout << "From:\t" << Utils::Position::to_labeled_position(status.From) << std::endl;
            std::cout << "To:\t" << Utils::Position::to_labeled_position(status.To) << std::endl;
            std::cout << "Valid:\t" << status.Validity << "\n\n";

            // Display Board
            board.display(); std::cout << std::endl;

            try
            {
                // Piece movement
                std::string label_position;
                Utils::Position from, to;
                
                std::cout << "Piece Position: ";
                std::cin >> label_position;
                from = Utils::Position::to_position(label_position);

                if (board.get_cell(from)->is_empty())
                {
                    std::cout << "Empty Cell!" << std::endl;
                    _getch();
                    continue;
                }

                std::cout << "Target Position: ";
                std::cin >> label_position;
                to = Utils::Position::to_position(label_position);

                // Update status
                status.From = from;
                status.To = to;
                status.Validity = true;

                // Move the piece
                board.move_piece(from, to);

                _getch();
            }
            catch (const Shield::DomainException& ex)
            {
                //std::cout << "\nError:\t" << ex.what() << std::endl;
                status.Validity = false;
            }
        }
    }
    catch (const Shield::DomainException& ex) {
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
