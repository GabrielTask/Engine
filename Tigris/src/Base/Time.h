#pragma once
#include <Time.h>
#include <iostream>
#include <windows.h>

namespace Tigris
{


	class Clock
	{
	public:

		static uint64_t TimeStamp;
		static uint32_t Second;
		static uint32_t Minute;
		static uint32_t Hour;
		static uint32_t mDay;
		static uint32_t Month;
		static uint32_t Year;
		static uint32_t wDay;
		static uint32_t yDay;
		static uint32_t isdst;
		
	
		static uint64_t GetClock() { return s_CurrentTime; }
	
		static void Tick()
		{
			
			s_TimeStamp = time(0);
			s_GM_Time = gmtime(&s_TimeStamp);

			TimeStamp = s_TimeStamp;
			Second = s_GM_Time->tm_sec;
			Minute = s_GM_Time->tm_min;
			Hour = s_GM_Time->tm_hour;
			mDay = s_GM_Time->tm_mday;
			Month = s_GM_Time->tm_mon;
			Year = s_GM_Time->tm_year;
			wDay = s_GM_Time->tm_wday;
			yDay = s_GM_Time->tm_yday;
			isdst = s_GM_Time->tm_isdst;

			QueryPerformanceCounter((LARGE_INTEGER*)&s_CurrentTime);


		}
	
	private:
		static unsigned long s_CurrentTime;
		static tm* s_GM_Time;
		static time_t s_TimeStamp;

	};

	



	

	class TimeInterval
	{
	public:
		TimeInterval() = default;
		TimeInterval(float value):m_DeltaTime(value){}
		operator float&() { return m_DeltaTime; }
	private:

		float m_DeltaTime;
	};
}