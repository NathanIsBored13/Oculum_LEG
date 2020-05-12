#include "ocpch.h"
#include "KeyboardEvents.h"

namespace Oculum
{
	KeyEvent::KeyEvent(int keycode) : keyCode(keyCode) {}

	inline int KeyEvent::GetKeyCode() const
	{
		return keyCode;
	}

	KeyPressedEvent::KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), repeatCount(repeatCount) {}


	inline int KeyPressedEvent::GetRepeatCount() const
	{
		return repeatCount;
	}

	std::string KeyPressedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << keyCode << " (" << repeatCount << " repeats)";
		return ss.str();
	}

	KeyReleasedEvent::KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

	std::string KeyReleasedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << keyCode;
		return ss.str();
	}
}