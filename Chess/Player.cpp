#include "Player.hpp"

using namespace Entity;
using namespace ValueObject;

/*// Player class -- Implementation //*/

// Constructor
Player::Player(std::string name, unsigned int score)
{
	this->name = new Name(name);
	this->score = new Score(score);
}

// Getters
std::string Player::get_name() const
{
	return name->get();
}

unsigned int Player::get_score() const
{
	return score->get();
}

// Methods - Manipulate score values
void Player::increment_score(unsigned int value)
{
	score = new Score(score->get() + value);
}

void Player::decrement_score(unsigned int value)
{
	score = new Score(score->get() - value);
}

// Destructor
Player::~Player()
{
	delete name;
	delete score;
}
