#pragma once
#include <stdint.h>
#include <tuple>
#include <ostream>

namespace Tigris
{
	enum class EventType
	{
		WindowClosed, WindowResized, WindowMoved, WindowFocused, WindowUnfocused, WindowMaximized, WindowRestored,
		MouseMoved, MouseClicked, MouseReleased, MouseScrolled,
		KeyPressed, KeyReleased, KeyRepeat, CharEntered,
		Dropped
	};

	enum EventCategory
	{
		WindowEvent = 1<<0,
		MouseEvent= 1 << 1,
		KeyBoardEvent = 1 << 2
	};


	#define Type(type) 	static EventType GetStaticType() { return type; }\
	inline virtual EventType GetType()const { return GetStaticType(); }\
	virtual const char* GetName() const override { return #type; }
	
	#define category(category) virtual int GetCategoryFlags() const override {return category;}

	class Event
	{
	public:
		virtual EventType GetType()const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

		bool Handled = 0;
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


	//std::ostream& operator<<(std::ostream& os, const Event& e)
	//{
	//	os << e.ToString();
	//	return os;
	//}


}