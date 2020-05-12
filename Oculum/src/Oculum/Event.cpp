#include "Event.h"

namespace Oculum
{
	std::string Event::ToString() const
	{
		return GetName();
	}

	void Event::Handled()
	{
		handled = true;
	}

	bool Event::IsHandled()
	{
		return handled;
	}

	EventDispatcher::EventDispatcher(Event& event) : event(event) {}

	template<typename T>
	bool EventDispatcher::Dispatch(std::function<bool(T&)> func)
	{
		if (event.GetEventType() == T::GetStaticType())
		{
			if (func(*(T*)&m_Event))
			{
				event.Handled();
			}
			return true;
		}
		return false;
	}
}