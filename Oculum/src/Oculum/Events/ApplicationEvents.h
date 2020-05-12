#pragma once

#include "Oculum/Event.h"

namespace Oculum
{
	class OC_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int, unsigned int);

		inline unsigned int GetWidth() const;
		inline unsigned int GetHeight() const;
		std::string ToString() const override;

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_Width, m_Height;
	};

	class OC_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent();

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}