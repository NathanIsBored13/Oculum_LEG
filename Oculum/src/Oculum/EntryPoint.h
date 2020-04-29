#pragma once

#ifdef OC_PLATFORM_WINDOWS
 
extern Oculum::Application* Oculum::CreateApplication();

int main(int argc, int argv)
{
	Oculum::Application* app = Oculum::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif