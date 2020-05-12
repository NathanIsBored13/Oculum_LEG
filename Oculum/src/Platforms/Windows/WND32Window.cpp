#include "ocpch.h"
#include "WND32Window.h"

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

			glfwInitialized = true;
		}

		m_Window = glfwCreateWindow((int)properties.Width, (int)properties.Height, windowData.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &windowData);
		SetVSync(true);
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