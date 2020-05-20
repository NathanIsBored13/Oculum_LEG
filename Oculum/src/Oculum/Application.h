#pragma once

#include "Core.h"
#include "Event.h"
#include "Window.h"
#include "Oculum/Events/ApplicationEvents.h"

namespace Oculum
{
	class OC_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event&);
		bool OnWindowClose(WindowCloseEvent&);
	private:
		void HSVtoRGB(int, double, double, int[3]);
		std::unique_ptr<Window> window;
		bool running = true;

	};
	Application* CreateApplication();
}