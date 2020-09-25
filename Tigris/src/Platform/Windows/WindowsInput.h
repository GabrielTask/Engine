#pragma once
#include "maths.h"

namespace Tigris
{
	class WindowsInput
	{
	public:
		static bool IsKeyPressed(uint32_t key);
		static bool IsMousePressed(uint32_t button);
		static bool IsButtonPressed(uint32_t button);
		static math::vec2 GetMousePosition();
		static void BeginMouseMark();

		static math::vec2 GetDeltaMousePosition();

	private:

		static math::vec2 mousePos;
	};
}

