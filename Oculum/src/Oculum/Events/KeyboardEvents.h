#pragma once

#include "Oculum/Event.h"

namespace Oculum
{
	class OC_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const;
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int);

		int keyCode;
	};

	class OC_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int, int);

		inline int GetRepeatCount() const;

		std::string ToString() const override;

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int repeatCount;
	};

	class OC_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int);

		std::string ToString() const override;

		EVENT_CLASS_TYPE(KeyReleased)
	};
};