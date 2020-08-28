#pragma once

namespace Tigris
{
	class WindowsInput
	{
	public:
		static bool IsKeyPressed(uint32_t key);
		static bool IsMousePressed(uint32_t button);
		static bool IsButtonPressed(uint32_t button);
		static std::pair<uint32_t, uint32_t> GetMousePosition();
	};
}

