#pragma once

#include "Name.hpp"
#include "Score.hpp"

namespace Entity
{
	class Player
	{
	private:
		// Attributes
		ValueObject::Name name;
		ValueObject::Score score;

	public:
		// Constructor
		Player (const std::string& name, unsigned int score = 0);

		// Getters
		std::string get_name() const;
		unsigned int get_score() const;

		// Methods - Manipulate score
		void increment_score(const unsigned int& value);
		void decrement_score(const unsigned int& value);
	};
}
