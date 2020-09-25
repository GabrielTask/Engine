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

		virtual void OnAtach() {}
		virtual void OnDetach() {};
		virtual void OnEvent(Event& e) {};
		virtual void OnUpdate(TimeInterval dt) {};

		virtual void OnImguiRender(TimeInterval dt) {};


	};

}