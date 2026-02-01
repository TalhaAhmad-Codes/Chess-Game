#pragma once

namespace ValueObject
{
	class Score
	{
	private:
		// Attribute
		unsigned int value;

	public:
		// Constructor
		Score(unsigned int score = 0);

		// Getter
		unsigned int get();
	};
}
