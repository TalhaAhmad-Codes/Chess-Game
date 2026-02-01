#include "Player.hpp"

using namespace Entity;
using namespace ValueObject;

/*// Player class -- Implementation //*/

// Constructor
Player::Player(const std::string& name, unsigned int score)
{
	this->name = name;
	this->score = Score(score);
}

// Getters
std::string Player::get_name() const
{
	return name.get();
}

unsigned int Player::get_score() const
{
	return score.get();
}

// Methods - Manipulate score values
void Player::increment_score(const unsigned int& value)
{
	score = Score(score.get() + value);
}

void Player::decrement_score(const unsigned int& value)
{
	score = Score(score.get() - value);
}
