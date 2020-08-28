#include "TGpch.h"
#include "Time.h"

namespace Tigris
{
	time_t Clock::s_TimeStamp = 0;
	tm* Clock::s_GM_Time = nullptr;
	unsigned long Clock::s_CurrentTime = 0;

	uint64_t Clock::TimeStamp = 0;
	uint32_t Clock::Second = 0;
	uint32_t Clock::Minute = 0;
	uint32_t Clock::Hour = 0;
	uint32_t Clock::mDay = 0;
	uint32_t Clock::Month = 0;
	uint32_t Clock::Year = 0;
	uint32_t Clock::wDay = 0;
	uint32_t Clock::yDay = 0;
	uint32_t Clock::isdst = 0;
}