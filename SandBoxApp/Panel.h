#pragma once
#include "../Tigris/vendor/Math/maths.h"
#include "GraphicalInterface.h"

namespace Tigris
{

	class Panel
	{
	public:
		Panel() = delete;

		static void Begin(uint32_t w, uint32_t h, const math::vec2& s, const math::vec2& pos);

		static void End();


	};

}