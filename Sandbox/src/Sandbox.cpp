#include "Sandbox.h"

Sandbox::Sandbox()
{

}

Sandbox::~Sandbox()
{

}

Oculum::Application* Oculum::CreateApplication()
{
	return new Sandbox();
}