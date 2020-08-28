#include "TGpch.h"
#include "WindowsInput.h"
#include "GLFW/glfw3.h"
#include "Base/Application.h"

namespace Tigris
{

	bool WindowsInput::IsKeyPressed(uint32_t key)
	{
		return glfwGetKey(static_cast<GLFWwindow*>(Application::Get()->GetWindow()->GetNativeWindow()), key)== GLFW_PRESS;
	}

	bool WindowsInput::IsMousePressed(uint32_t button)
	{
		return glfwGetMouseButton(static_cast<GLFWwindow*>(Application::Get()->GetWindow()->GetNativeWindow()), button) == GLFW_PRESS;
	}

	bool WindowsInput::IsButtonPressed(uint32_t button)
	{
		return 0;
	}

	std::pair<uint32_t, uint32_t> WindowsInput::GetMousePosition()
	{
		double x, y;
		
		glfwGetCursorPos(static_cast<GLFWwindow*>(Application::Get()->GetWindow()->GetNativeWindow()), &x,&y);
		return { (uint32_t)x,(uint32_t)y };
	}

}