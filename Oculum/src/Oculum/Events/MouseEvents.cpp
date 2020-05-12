#include "MouseEvents.h"

#include <sstream>

namespace Oculum
{
	MouseMovedEvent::MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}

	inline float MouseMovedEvent::GetX() const
	{
		return m_MouseX;
	}

	inline float MouseMovedEvent::GetY() const
	{
		return m_MouseY;
	}

	std::string MouseMovedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
		return ss.str();
	}

	MouseScrolledEvent::MouseScrolledEvent(float xOffset, float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {}

	inline float MouseScrolledEvent::GetXOffset() const
	{
		return m_XOffset;
	}

	inline float MouseScrolledEvent::GetYOffset() const
	{
		return m_YOffset;
	}

	std::string MouseScrolledEvent::ToString() const
	{
		std::stringstream ss;
		ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
		return ss.str();
	}

	MouseButtonEvent::MouseButtonEvent(int mouseButton) : mouseButton(mouseButton) {}

	int MouseButtonEvent::GetMouseButton()
	{
		return mouseButton;
	}
	
	MouseButtonPressedEvent::MouseButtonPressedEvent(int mouseButton) : MouseButtonEvent(mouseButton) {}

	std::string MouseButtonPressedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "MouseButtonPressedEvent: " << mouseButton;
		return ss.str();

	}

	MouseButtonReleasedEvent::MouseButtonReleasedEvent(int mouseButton) : MouseButtonEvent(mouseButton) {}

	std::string MouseButtonReleasedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "MouseButtonReleasedEvent: " << mouseButton;
		return ss.str();
	}
}