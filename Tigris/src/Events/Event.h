#pragma once
#include <stdint.h>
#include <tuple>

namespace Tigris
{
	enum class EventType
	{
		WindowClosed, WindowResized, WindowMoved, WindowFocused, WindowUnfocused, WindowMaximized, WindowRestored,
		MouseMoved, MouseClicked, MouseReleased, MouseScrolled,
		KeyPressed, KeyReleased, KeyRepeat, CharEntered,
		Dropped
	};

	#define Type(type) 	static EventType GetStaticType() { return type; }\
	inline virtual EventType GetType()const { return GetStaticType(); }

	class Event
	{
	public:
		virtual EventType GetType()const = 0;

	};

	
	class Trigger
	{
	public:
		Trigger(Event& e) :m_Event(e) {}
		template<typename T, typename F>
		void Trig(const F& func)
		{
			if (m_Event.GetType() == T::GetStaticType())
			{
				func(*(T*)&m_Event);
			}
		}

	private:
		Event& m_Event;
	};





}