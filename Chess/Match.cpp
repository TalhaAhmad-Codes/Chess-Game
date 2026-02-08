#include "Match.hpp"

using namespace std;
using namespace Utils;
using namespace Logic;
using namespace Entity;
using namespace Interface;

/*// Match class -- Implementation //*/

// Constructors
Match::Match(Player* player1, Player* player2)
{
	players[0] = player1;
	players[1] = player2;
	board = new Board();
	turn = 0;
}

Match::Match(Player* player1, Player* player2, Board* board, int turn)
{
	players[0] = player1;
	players[1] = player2;
	this->board = board;
	this->turn = turn;
}

// Getter
int Match::get_turn() const
{
	return turn;
}

// Method - Update turn
void Match::update_turn()
{
	turn ^= 1;
}

// Method - Move the piece
ValidationResult Match::move_piece(Position& from, Position& to)
{
	return board->move_piece(from, to);
}
