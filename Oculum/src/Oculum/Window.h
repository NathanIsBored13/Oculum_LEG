#pragma once

#include "ocpch.h"
#include "Core.h"
#include "Event.h"

namespace Oculum
{
	struct WindowCreateStruct
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowCreateStruct(const std::string& title = "Oculum", unsigned int width = 1280, unsigned int height = 720) : Title(title), Width(width), Height(height) {}
	};

	class OC_API Window
	{
	public:
		virtual ~Window() {}
		virtual void OnUpdate() = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const std::function<void(Event&)>& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowCreateStruct& props = WindowCreateStruct());
	};
}