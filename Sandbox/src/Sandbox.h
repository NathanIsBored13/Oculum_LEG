#pragma once

#include <Oculum.h>

class Sandbox : public Oculum::Application
{
public:
	Sandbox();
	~Sandbox();
};

Oculum::Application* Oculum::CreateApplication();