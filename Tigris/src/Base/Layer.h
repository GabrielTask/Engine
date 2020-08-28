#pragma once
#include "Events/Event.h"
#include "Base/Time.h"

namespace Tigris
{
	class Layer
	{

	public:

		Layer() = default;
		~Layer() = default;

		virtual void OnAtach() = 0;
		virtual void OnDetach() = 0;
		virtual void OnEvent(Event& e) = 0;
		virtual void OnUpdate(TimeInterval dt) = 0;



	};

}