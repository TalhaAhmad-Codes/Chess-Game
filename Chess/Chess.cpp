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
            std::cout << "Piece:\t" << Utils::Position::to_labeled_position(position) << "\n\n";

            try
            {
                auto difference = Utils::Position::abs_difference(status.To, status.From);
                difference.display("Difference:\t");

                // Piece movement
                std::string label_position;
                Utils::Position from = position, to;

                std::cout << "Target Position: ";
                std::cin >> label_position;
                to = Utils::Position::to_position(label_position);

                // Move the piece
                auto result = board.move_piece(from, to);

                // Update status
                status.From = from;
                status.To = to;
                status.Validity = result == Utils::ValidationResult::OK;
            }
            catch (const Shield::DomainException& ex)
            {
                //std::cout << "\nError:\t" << ex.what() << std::endl;
                status.Validity = false;
            }

            if (status.Validity)
                position = status.To;
        }
    }
    catch (const Shield::DomainException& ex) {
        std::cout << "\nError:\t" << ex.what() << std::endl;
    }

    /*auto position = Utils::Position::to_position("e4");
    position.display("Position:\t");
    std::cout << "Label:\t" << Utils::Position::to_labeled_position(position) << std::endl;*/
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
