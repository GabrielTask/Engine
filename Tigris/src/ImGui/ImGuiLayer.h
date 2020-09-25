#pragma once
#include "Base/Base.h"
#include "Base/Layer.h"

namespace Tigris
{
	class TG_API ImGuiLayer : public Layer
	{

	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		void OnAtach() override;


		void OnDetach() override;


		void OnEvent(Event& e) override;


		void Begin();
		void End();
	private:
		bool m_BlockEvents = true;

	};

}