#include "ocpch.h"
#include "WND32Window.h"

#include "Oculum/Events/ApplicationEvents.h"
#include "Oculum/Events/KeyboardEvents.h"
#include "Oculum/Events/MouseEvents.h"

namespace Oculum
{
	static bool glfwInitialized = false;

	Window* Window::Create(const WindowCreateStruct& props)
	{
		return new WND32Window(props);
	}

	WND32Window::WND32Window(const WindowCreateStruct& props)
	{
		Init(props);
	}

	WND32Window::~WND32Window()
	{
		Shutdown();
	}

	void WND32Window::GLFWErrorCallback(int error, const char* description)
	{
		OC_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}


	void WND32Window::Init(const WindowCreateStruct& properties)
	{
		windowData.Title = properties.Title;
		windowData.Width = properties.Width;
		windowData.Height = properties.Height;

		OC_CORE_INFO("Creating window {0} ({1}, {2})", properties.Title, properties.Width, properties.Height);

		if (!glfwInitialized)
		{
			int success = glfwInit();
			OC_CORE_ASSERT(success, "Could not intialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			glfwInitialized = true;
		}

		m_Window = glfwCreateWindow((int)properties.Width, (int)properties.Height, windowData.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &windowData);
		SetVSync(true);

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;

				WindowResizeEvent event(width, height);
				data.EventCallback(event);
			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.EventCallback(event);
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent event(key, 0);
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent event(key);
						data.EventCallback(event);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent event(key, 1);
						data.EventCallback(event);
						break;
					}
				}
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent event(button);
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent event(button);
						data.EventCallback(event);
						break;
					}
				}
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);
			});
	}

	void WND32Window::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WND32Window::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WND32Window::SetVSync(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}
		windowData.VSync = enabled;
	}

	bool WND32Window::IsVSync() const
	{
		return windowData.VSync;
	}
}