#pragma once

#include "Match.hpp"

namespace Logic
{
	class Game
	{
	private:
		Match match;
	
	public:
		Game(Match);

		void start();
	};
}
