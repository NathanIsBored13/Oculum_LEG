#include "ocpch.h"
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

	EventDispatcher::EventDispatcher(Event& event) : m_event(event) {}
}