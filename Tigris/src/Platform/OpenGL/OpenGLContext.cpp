#include "TGpch.h"
#include "Base/Base.h"
#include "OpenGLContext.h"
#include <glfw/glfw3.h>
#include <glad/glad.h>

namespace Tigris
{

	OpenGLContext::OpenGLContext(void* window)
		:m_WindlwHandle((GLFWwindow*)window)
	{
		
		Assert(window);

	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindlwHandle);
		Assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));
		
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindlwHandle);
	}

}