#include "TGpch.h"
#include "Base/Base.h"
#include "WindowsWindow.h"

#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include "Events/WindowEvent.h"
#include "Events/KeyboardEvent.h"
#include "Events/MouseEvent.h"
#include "Graphics/RenderCommand.h"

static bool GLFW_INITIALIZED = false;



namespace Tigris
{

	WindowsWindow::WindowsWindow(uint32_t width, uint32_t height, const char* name)
	{
		m_Data.m_Width = width;
		m_Data.m_Height = height;
		m_Data.m_Name = name;

		if(!GLFW_INITIALIZED)
		Assert(glfwInit());

		m_NativeWindow = glfwCreateWindow(width, height, name, nullptr, nullptr);
	
		m_Context = GraphicsContext::Create(m_NativeWindow);
		m_Context->Init();

		RenderCommand::SetViewPort(0, 0, width, height);
		RenderCommand::SetClearColor({ 80.0f / 255.0f,183.5f / 255.0f,226.0f / 255.0f,1.0f });

		glfwSetWindowUserPointer(m_NativeWindow, &m_Data);
		InitBack();

	}

	WindowsWindow::~WindowsWindow()
	{
		printf("Working\n");
		glfwDestroyWindow(m_NativeWindow);
		glfwTerminate();
	}

	void WindowsWindow::OnUpdate()
	{
		m_Context->SwapBuffers();
		/* Poll for and process events */
		glfwPollEvents();
	}

	void WindowsWindow::SetCallBack(void(*callbackFunc) (Event& e))
	{
		
		m_Data.m_CallbackFunc = callbackFunc;
	}

	const char* WindowsWindow::GetName() const
	{
		return m_Data.m_Name;
	}

	float WindowsWindow::GetAspectRatio() const
	{
		return (float)m_Data.m_Width / (float)m_Data.m_Height;
	}

	std::pair<uint32_t, uint32_t> WindowsWindow::GetSize() const
	{
		return { m_Data.m_Width, m_Data.m_Height };
	}

	void WindowsWindow::SetVSync(bool value)
	{
		glfwSwapInterval((unsigned int)value);
		m_Data.m_IsVsync = value;

	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.m_IsVsync;
	}

	void* WindowsWindow::GetNativeWindow()
	{
		return m_NativeWindow;
	}

	void WindowsWindow::InitBack()
	{
		glfwSetWindowCloseCallback(m_NativeWindow, [](GLFWwindow* window)
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
				WindowClosedEvent e;
				data->m_CallbackFunc(e);
			});

		glfwSetWindowSizeCallback(m_NativeWindow, [](GLFWwindow* window, int width, int height)
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
				data->m_Width = width;
				data->m_Height = height;
				WindowResizedEvent e(width, height);
				data->m_CallbackFunc(e);
			});

		glfwSetWindowPosCallback(m_NativeWindow, [](GLFWwindow* window, int xpos, int ypos)
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
				WindowMovedEvent e(xpos, ypos);
				data->m_CallbackFunc(e);
			});

		glfwSetWindowRefreshCallback(m_NativeWindow, [](GLFWwindow * window)
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
			});

		glfwSetWindowFocusCallback(m_NativeWindow, [](GLFWwindow* window, int focused)
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
				if (focused)
				{
					WindowFocusedEvent e;
					data->m_CallbackFunc(e);
					return;
				}
				WindowUnfocusedEvent e;
				data->m_CallbackFunc(e);
			});

		glfwSetWindowMaximizeCallback(m_NativeWindow, [](GLFWwindow* window, int maximized)
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
				if (maximized)
				{
					WindowMaximizedEvent e;
					data->m_CallbackFunc(e);
					return;
				}
				WindowRestoredEvent e;
				data->m_CallbackFunc(e);
			});

		glfwSetKeyCallback(m_NativeWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
				if (action == GLFW_PRESS)
				{
					KeyPressedEvent e(key);
					data->m_CallbackFunc(e);
					return;
				}
				if (action == GLFW_RELEASE)
				{
					KeyReleasedEvent e(key);
					data->m_CallbackFunc(e);
				}

		});


		glfwSetMouseButtonCallback(m_NativeWindow, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);

				if (action == GLFW_PRESS)
				{
					MouseButtonClickedEvent e(button);
					data->m_CallbackFunc(e);
					return;
				}

				if (action == GLFW_RELEASE)
				{
					MouseButtonReleasedEvent e(button);
					data->m_CallbackFunc(e);
					return;
				}

			});
			
		glfwSetCursorPosCallback(m_NativeWindow, [](GLFWwindow* window, double xpos, double ypos)
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
				MouseMovedEvent e((float)xpos, (float)ypos);
				data->m_CallbackFunc(e);

			});


		glfwSetScrollCallback(m_NativeWindow, [](GLFWwindow* window, double xoffset, double yoffset)
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent e((float)xoffset, (float)yoffset);
				data->m_CallbackFunc(e);
			});


		glfwSetDropCallback(m_NativeWindow, [](GLFWwindow* window, int path_count, const char* paths[])
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
				DroppedEvent e(path_count, paths);
				data->m_CallbackFunc(e);
			});
		

		glfwSetCursorEnterCallback(m_NativeWindow, [](GLFWwindow* window, int entered) {});
		glfwSetCharCallback(m_NativeWindow, [](GLFWwindow* window, unsigned int codepoint) {});
		
	}

}
