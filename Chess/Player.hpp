#pragma once

#include "Name.hpp"
#include "Score.hpp"

namespace Entity
{
	class Player
	{
	private:
		// Attributes
		ValueObject::Name* name;
		ValueObject::Score* score;

	public:
		// Constructor
		Player (std::string name, unsigned int score = 1);

		// Getters
		std::string get_name();
		unsigned int get_score();

		// Methods - Manipulate score
		void increment_score(unsigned int value = 1);
		void decrement_score(unsigned int value = 1);

		// Desctructor
		~Player();
	};
}
