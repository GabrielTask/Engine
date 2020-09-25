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

	math::vec2 Input::GetMousePosition()
	{
		return PlatformInput::GetMousePosition();
	}

	math::vec2 Input::GetDeltaMousePosition()
	{
		return PlatformInput::GetDeltaMousePosition();

	}

	void Input::BeginMouseMark()
	{
		PlatformInput::BeginMouseMark();
	}

}