#pragma once
#include "Base/Base.h"

namespace Tigris
{
	class GraphicsContext
	{
	public:
		virtual ~GraphicsContext() = default;
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
	public:
		static Scope<GraphicsContext> Create(void* window) ;
	};

}