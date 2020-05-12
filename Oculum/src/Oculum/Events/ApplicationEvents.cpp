#include "ApplicationEvent.h"

#include <sstream>

namespace Oculum
{
	WindowResizeEvent::WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}

	inline unsigned int WindowResizeEvent::GetWidth() const
	{
		return m_Width;
	}
	inline unsigned int WindowResizeEvent::GetHeight() const
	{
		return m_Height;
	}

	std::string WindowResizeEvent::ToString() const
	{
		std::stringstream ss;
		ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
		return ss.str();
	}

	WindowCloseEvent::WindowCloseEvent() {}
}