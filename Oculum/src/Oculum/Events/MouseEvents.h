#pragma once

#include "Oculum/Event.h"

namespace Oculum
{
	class OC_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float, float);
		inline float GetX() const;
		inline float GetY() const;
		std::string ToString() const override;

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_MouseX, m_MouseY;
	};

	class OC_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float, float);
		inline float GetXOffset() const;
		inline float GetYOffset() const;

		std::string ToString() const override;

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;
	};

	class OC_API MouseButtonEvent : public Event
	{
	public:
		int GetMouseButton();
		EVENT_CLASS_CATEGORY(Event::Catagory::EventCategoryInput | Event::Catagory::EventCategoryMouse)
	protected:
		MouseButtonEvent(int);
		int mouseButton;
	};

	class OC_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int);
		virtual std::string ToString() const override;
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class OC_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button);

		std::string ToString() const override;

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}