#pragma once

#include "ocpch.h"
#include "Oculum/Window.h"

#include <GLFW/glfw3.h>

namespace Oculum
{
	class WND32Window : public Window
	{
	public:
		WND32Window(const WindowCreateStruct& props);
		virtual ~WND32Window();
		void OnUpdate() override;
		inline unsigned int GetWidth() const override { return windowData.Width; }
		inline unsigned int GetHeight() const override { return windowData.Height; }
		inline void SetEventCallback(const std::function<void(Event&)>& callback) override { windowData.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowCreateStruct& props);
		virtual void Shutdown();
		GLFWwindow* m_Window;
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
			std::function<void(Event&)> EventCallback;
		};
		WindowData windowData;
	};
}