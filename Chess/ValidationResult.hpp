#pragma once

namespace Utils
{
	enum ValidationResult
	{
		// Basic
		OK = 0,
		INVALID_MOVE = 1,
		UNCLEAR_PATH = 2,
		EMPTY_CELL = 3
	};
}
