#pragma once

#ifdef OC_PLATFORM_WINDOWS
 
extern Oculum::Application* Oculum::CreateApplication();

int main(int argc, int argv)
{
	Oculum::Log::Init();
	Oculum::Application* app = Oculum::CreateApplication();
	OC_CORE_INFO("Engine initialised");
	app->Run();
	delete app;
	return 0;
}

#endif