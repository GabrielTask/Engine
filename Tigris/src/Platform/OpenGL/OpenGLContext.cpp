#include "TGpch.h"
#include "Base/Base.h"
#include "OpenGLContext.h"
#include <glfw/glfw3.h>
#include <glad/glad.h>

namespace Tigris
{
	GLFWwindow* OpenGLContext::m_WindowDefaultHandle = nullptr;

	OpenGLContext::OpenGLContext(void* window)
		:m_WindowHandle((GLFWwindow*)window)
	{
		
		Assert(window);
		glfwMakeContextCurrent(m_WindowHandle);
		Assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		
		
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

	void OpenGLContext::Unbind()
	{
		glfwMakeContextCurrent(m_WindowDefaultHandle);
	}

	void GraphicsContext::SetDefaultContext(void* window)
	{
		OpenGLContext::m_WindowDefaultHandle = (GLFWwindow*)window;
	}

}