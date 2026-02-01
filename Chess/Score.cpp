#include "Score.hpp"

using namespace ValueObject;

/*// Score class -- Implementation //*/

// Constructor
Score::Score(unsigned int score)
{
	value = score;
}

// Getter
unsigned int Score::get()
{
	return value;
}
