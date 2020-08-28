#include "TGpch.h"
#include "Input.h"

#ifdef TG_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsInput.h"
using PlatformInput = Tigris::WindowsInput;
#endif

namespace Tigris
{


	bool Input::IsKeyPressed(uint32_t key)
	{
		return PlatformInput::IsKeyPressed(key);
	}

	bool Input::IsMousePressed(uint32_t button)
	{
		return PlatformInput::IsMousePressed(button);
	}

	bool Input::IsButtonPressed()
	{
		return PlatformInput::IsButtonPressed(0);
	}

	std::pair<uint32_t, uint32_t> Input::GetMousePosition()
	{
		return PlatformInput::GetMousePosition();
	}

}