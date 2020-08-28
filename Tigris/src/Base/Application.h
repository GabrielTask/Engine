#include "Base/Base.h"
#include "Base/Window.h"
#include "Events/WindowEvent.h"
#include "Base/Time.h"
#include "Base/LayerStack.h"
#include <stdint.h>


namespace Tigris
{
	class TG_API Application
	{
	public:
		Application();
		void OnUpdate();
		void OnEvent(Event& e);
		const Ref<Window>& GetWindow() { return m_Window; }

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		void PopOverlay(Layer* layer);

	private:
		bool OnWindowClose(WindowClosedEvent& e);
	private:
		Ref<Window> m_Window;
		TimeInterval m_DeltaTime;
		LayerStack m_LayerStack;
		bool m_Running = true;

	public:
		static Application* Get() { return s_Instance; }
	private:
		static Application* s_Instance;
	};
	Application* CreateApplication();
}