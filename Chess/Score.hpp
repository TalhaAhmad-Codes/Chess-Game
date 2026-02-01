#pragma once

namespace ValueObject
{
	class Score
	{
	private:
		// Attribute
		unsigned int value;

	public:
		// Constructors
		Score(unsigned int score = 0);
		Score(const Score& obj);

		// Getter
		unsigned int get() const;
	};
}
