#pragma once
#include "Event.h"

namespace Tigris
{
	class KeyEvent : public Event
	{
	public:
		KeyEvent(uint32_t key):m_Key(key) {}
		uint32_t GetKey()const { return m_Key; }
	private:
		uint32_t m_Key;


	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(uint32_t key):KeyEvent(key) {}
		Type(EventType::KeyPressed)
		
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(uint32_t key) :KeyEvent(key) {}
		Type(EventType::KeyReleased)
	};

	class KeyRepeatEvent : public KeyEvent
	{
	public:
		KeyRepeatEvent(uint32_t key) :KeyEvent(key) {}
		Type(EventType::KeyRepeat)
	};

	class CharEnteredEvent : public Event
	{
	public:
		CharEnteredEvent(uint32_t codepoint) :
			m_CodePoint(codepoint){}
		Type(EventType::CharEntered)
		uint32_t GetCodePoint()const { return m_CodePoint; }
	private:
		uint32_t m_CodePoint;
	};


}