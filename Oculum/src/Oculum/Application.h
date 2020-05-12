#pragma once

#include "Core.h"

#include <vector>

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