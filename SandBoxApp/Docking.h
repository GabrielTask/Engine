#pragma once

#include "../Tigris/vendor/Math/maths.h"

namespace Tigris
{
	class Anchor
	{
	public:
	private:
		math::vec2 m_Position;
		math::vec2 m_Size;
	};

	class DockSpace
	{
	public:
		DockSpace() = delete ;
		static void Begin();

	private:

	};

}