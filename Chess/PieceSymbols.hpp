#pragma once

#include "PieceEnums.hpp"

namespace Interface
{
	class PieceSymbol
	{
	public:
		static char get_symbol(PieceType, PieceGroup);
	};
}
