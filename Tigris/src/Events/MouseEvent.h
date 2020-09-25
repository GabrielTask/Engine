#pragma once
#include "Event.h"


namespace Tigris
{
	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float xpos, float ypos):m_Xpos(xpos), m_Ypos(ypos){}
		Type(EventType::MouseMoved)
		category(EventCategory::MouseEvent)
		std::pair<float, float> GetPos()const { return{ m_Xpos, m_Ypos }; }
		float GetXpos()const { return m_Xpos; }
		float GetYpos()const { return m_Ypos; }
	private:
		float m_Xpos, m_Ypos;
	};


	class MouseButtonEvent : public Event
	{
	public:
		MouseButtonEvent(uint32_t button):m_Button(button){}
		uint32_t GetButton()const { return m_Button; }
	private:
		uint32_t m_Button;
	};

	class MouseButtonClickedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonClickedEvent(uint32_t button):MouseButtonEvent(button){}
		Type(EventType::MouseClicked)
		category(EventCategory::MouseEvent)

	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(uint32_t button) :MouseButtonEvent(button) {}
		Type(EventType::MouseReleased)
		category(EventCategory::MouseEvent)


	};



	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xoffset, float yoffset):m_Xoffset(xoffset),m_Yoffset(yoffset)  {}
		Type(EventType::MouseScrolled)
		category(EventCategory::MouseEvent)
		std::pair<float, float> GetOffset()const { return{ m_Xoffset, m_Yoffset }; }
		float GetXoffset()const { return m_Xoffset; }
		float GetYoffset()const { return m_Yoffset; }
	private:
		float m_Xoffset, m_Yoffset;
	};


}