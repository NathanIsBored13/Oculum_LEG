#pragma once

#include "Core.h"

namespace Oculum
{
	class OC_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	private:
	};
	Application* CreateApplication();
}