#pragma once
#include <memory>
#include "maths.h"

namespace Tigris
{
	class Input
	{
	public:
		static bool IsKeyPressed(uint32_t key);
		static bool IsMousePressed(uint32_t button);
		static bool IsButtonPressed();
		static math::vec2 GetMousePosition();
		static void BeginMouseMark();
		static math::vec2 GetDeltaMousePosition();
	};


}