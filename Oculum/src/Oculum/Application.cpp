#include "ocpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace Oculum
{
	Application::Application()
	{
		window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		float cycle = 0;
		while (running)
		{
			int rgb[3];
			HSVtoRGB(cycle, 50, 50, rgb);
			glClearColor(rgb[0], rgb[1], rgb[2], 1);
			glClear(GL_COLOR_BUFFER_BIT);
			window->OnUpdate();
			cycle += 1;
			cycle = fmod(cycle, 360);
		}
	}

	void Application::HSVtoRGB(int H, double S, double V, int output[3]) {
		double C = S * V;
		double X = C * (1 - abs(fmod(H / 60.0, 2) - 1));
		double m = V - C;
		double Rs, Gs, Bs;

		if (H >= 0 && H < 60) {
			Rs = C;
			Gs = X;
			Bs = 0;
		}
		else if (H >= 60 && H < 120) {
			Rs = X;
			Gs = C;
			Bs = 0;
		}
		else if (H >= 120 && H < 180) {
			Rs = 0;
			Gs = C;
			Bs = X;
		}
		else if (H >= 180 && H < 240) {
			Rs = 0;
			Gs = X;
			Bs = C;
		}
		else if (H >= 240 && H < 300) {
			Rs = X;
			Gs = 0;
			Bs = C;
		}
		else {
			Rs = C;
			Gs = 0;
			Bs = X;
		}

		output[0] = (Rs + m) * 255;
		output[1] = (Gs + m) * 255;
		output[2] = (Bs + m) * 255;
	}

}