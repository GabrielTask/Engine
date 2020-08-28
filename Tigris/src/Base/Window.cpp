#include "TGpch.h"
#include "Base/Base.h"
#include "Window.h"

#ifdef TG_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
using PlatformWindow = Tigris::WindowsWindow;
#endif

namespace Tigris
{
	Ref<Window> Window::Create(uint32_t width, uint32_t height, const char* name)
	{
		return CreateRef<PlatformWindow>(width, height, name);
	}
}

