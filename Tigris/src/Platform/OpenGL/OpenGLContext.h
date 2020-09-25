#pragma once
#include "Graphics/GraphicsContext.h"

struct GLFWwindow;

namespace Tigris
{
	class OpenGLContext : public GraphicsContext
	{

	public:
		OpenGLContext(void* window);
		virtual void Init() override;


		virtual void SwapBuffers() override;

		void Unbind() override;



	private:
		GLFWwindow* m_WindowHandle;
	public:
		static GLFWwindow* m_WindowDefaultHandle;

	};

}

