#pragma once
#include "Event.h"
#include <iostream>

namespace Tigris
{

	class WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent(){}
		Type(EventType::WindowClosed)
		category(EventCategory::WindowEvent)
	};

	class WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(uint32_t width, uint32_t height) :m_Width(width), m_Height(height) {}
		Type(EventType::WindowResized)
		category(EventCategory::WindowEvent)
			std::pair<uint32_t, uint32_t> GetSize() { return { m_Width,m_Height }; }
			uint32_t GetWidth() { return m_Width; }
			uint32_t GetHeight() { return m_Height; }
	private:
		uint32_t m_Width, m_Height;
	};

	class WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(uint32_t xpos, uint32_t ypos):m_Xpos(xpos),m_Ypos(ypos){}
		Type(EventType::WindowMoved)
		category(EventCategory::WindowEvent)
			std::pair<uint32_t, uint32_t> GetPos() { return{ m_Xpos, m_Ypos }; }
		uint32_t GetXpos() { return m_Xpos; }
		uint32_t GetYpos() { return m_Ypos; }
	private:
		uint32_t m_Xpos, m_Ypos;
	};

	class WindowFocusedEvent : public Event
	{
	public:
		Type(EventType::WindowFocused)
		category(EventCategory::WindowEvent)
	};

	class WindowUnfocusedEvent : public Event
	{
	public:
		Type(EventType::WindowUnfocused)
		category(EventCategory::WindowEvent)
	};

	class WindowMaximizedEvent : public Event
	{
	public:
		Type(EventType::WindowMaximized)
		category(EventCategory::WindowEvent)
	};

	class WindowRestoredEvent : public Event
	{
	public:
		Type(EventType::WindowRestored);
		category(EventCategory::WindowEvent)
	};



	class DroppedEvent : public Event
	{
	public:
		DroppedEvent(int path_count, const char* paths[]) 
			:m_Path_count(path_count), m_Paths(paths)
		{
			for (uint32_t i = 0; i < strlen(paths[0]); i++)
			{
				if (paths[0][i] == '\\')
				{
					*((char*)(&(m_Paths[0][i]))) = '/';
				}
		}
		}

		Type(EventType::Dropped);
		category(EventCategory::WindowEvent)
		const char* GetPath()const  { if (m_Index < m_Path_count)return m_Paths[m_Index++]; return nullptr; }
		const char* operator[](uint32_t index)const { return m_Paths[index]; }
	private:
		mutable uint32_t m_Index = 0;
		uint32_t m_Path_count;
		const char** m_Paths;

	};
}