#pragma once

#include "Core.h"

#include <functional>
#include <string>

namespace Oculum
{
	#define EVENT_CLASS_TYPE(type) static Event::Type GetStaticType() { return Event::Type::##type; }\
		virtual Event::Type GetType() const override { return GetStaticType(); }\
		virtual const char* GetName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class OC_API Event
	{
	public:
		enum class Type
		{
			None = 0,
			WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
			KeyPressed, KeyReleased,
			MouseMoved,
			MouseButtonPressed, MouseButtonReleased, MouseScrolled
		};

		enum Catagory
		{
			None = 0,
			EventCategoryApplication = 1,
			EventCategoryInput = 2,
			EventCategoryKeyboard = 4,
			EventCategoryMouse = 8,
		};

		virtual Type GetType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const;
		void Handled();
		bool IsHandled();
	private:
		bool handled = false;
	};


	class EventDispatcher
	{
	public:
		EventDispatcher(Event&);
		template<typename T>
		bool Dispatch(std::function<bool(T&)> func);
	private:
		Event& event;
	};
}