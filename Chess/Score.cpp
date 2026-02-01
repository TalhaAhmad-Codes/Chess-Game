#include "Score.hpp"

using namespace ValueObject;

/*// Score class -- Implementation //*/

// Constructors
Score::Score(unsigned int score)
{
	value = score;
}

Score::Score(const Score& score)
{
	value = score.get();
}

// Getter
unsigned int Score::get() const
{
	return value;
}
