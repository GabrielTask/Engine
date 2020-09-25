#include "TGpch.h"
#include "WindowsInput.h"
#include "GLFW/glfw3.h"
#include "Base/Application.h"

namespace Tigris
{
	math::vec2 WindowsInput::mousePos = math::vec2(0.0f);

	bool WindowsInput::IsKeyPressed(uint32_t key)
	{
		return glfwGetKey(static_cast<GLFWwindow*>(Application::Get().GetWindow()->GetNativeWindow()), key)== GLFW_PRESS;
	}

	bool WindowsInput::IsMousePressed(uint32_t button)
	{
		return glfwGetMouseButton(static_cast<GLFWwindow*>(Application::Get().GetWindow()->GetNativeWindow()), button) == GLFW_PRESS;
	}

	bool WindowsInput::IsButtonPressed(uint32_t button)
	{
		return 0;
	}

	math::vec2 WindowsInput::GetMousePosition()
	{
		double x, y;
		
		glfwGetCursorPos(static_cast<GLFWwindow*>(Application::Get().GetWindow()->GetNativeWindow()), &x,&y);
		return math::vec2(x,y);
	}

	void WindowsInput::BeginMouseMark()
	{
		mousePos = GetMousePosition();
	}

	math::vec2 WindowsInput::GetDeltaMousePosition()
	{
		return (GetMousePosition() - mousePos);
	}

}