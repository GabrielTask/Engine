#pragma once
#include <memory>

namespace Tigris
{
	class Input
	{
	public:
		static bool IsKeyPressed(uint32_t key);
		static bool IsMousePressed(uint32_t button);
		static bool IsButtonPressed();
		static std::pair<uint32_t, uint32_t> GetMousePosition();
	};


}