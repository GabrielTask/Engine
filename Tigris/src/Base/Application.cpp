#include "TGpch.h"
#include "Application.h"
#include "Graphics/Renderer.h"
#include "Events/KeyboardEvent.h"
#include "Events/MouseEvent.h"
#include "Events/WindowEvent.h"

namespace Tigris
{


Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		s_Instance = this;
		m_Window = Window::Create(1280, 720, "Window Test");
		m_Window->SetCallBack([](Event& e)->void {Application::Get()->OnEvent(e);});
		m_Window->SetVSync(1);

		Renderer2D::Init();
	}


	bool Application::OnWindowClose(WindowClosedEvent& e)
	{
		Application::Get()->m_Running = 0;
		return 1;
	}


	void Application::OnUpdate()
	{


	float previousTime = 0.0f;
	while (m_Running)
	{
		//----------------UpdateClock----------------//
		Clock::Tick();
		m_DeltaTime = Clock::GetClock() - previousTime;
		previousTime = Clock::GetClock();
		//-------------------------------------------//

		RenderCommand::Clear();

		//---------------UpdateLayers----------------//
		for (auto Layer : m_LayerStack)
		{
			Layer->OnUpdate(m_DeltaTime/100000.0f);
		}
		//-------------------------------------------//

		//----------------UpdateWindow----------------//
		m_Window->OnUpdate();
		//-------------------------------------------//
	}
	
	}

	void Application::OnEvent(Event& e)
	{


		for (auto layer = m_LayerStack.rbegin(); layer != m_LayerStack.rend(); ++layer)
		{
			(*layer)->OnEvent(e);
		}


		Trigger trigger(e);
		trigger.Trig<WindowClosedEvent>
			([this](WindowClosedEvent& e) {m_Running = false; });

		trigger.Trig<WindowResizedEvent>
			([this](WindowResizedEvent& e) { RenderCommand::SetViewPort(0, 0, e.GetWidth(), e.GetHeight());});

		trigger.Trig<WindowMaximizedEvent>
			([this](WindowMaximizedEvent& e) { });

		trigger.Trig<WindowRestoredEvent>
			([this](WindowRestoredEvent& e) { });

		trigger.Trig<KeyPressedEvent>
			([this](KeyPressedEvent& e) {});

		trigger.Trig<MouseMovedEvent>
			([this](MouseMovedEvent& e) {});

		trigger.Trig<MouseScrolledEvent>
			([this](MouseScrolledEvent& e) {});

		trigger.Trig<MouseButtonClickedEvent>
			([this](MouseButtonClickedEvent& e) {});


		trigger.Trig<MouseButtonReleasedEvent>
			([this](MouseButtonReleasedEvent& e) {});

		trigger.Trig<DroppedEvent>
			([this](DroppedEvent& e) {});

		trigger.Trig<CharEnteredEvent>
			([this](CharEnteredEvent& e) { });


	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAtach();
	}

	void Application::PopLayer(Layer* layer)
	{
		m_LayerStack.PopLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

	void Application::PopOverlay(Layer* layer)
	{
		m_LayerStack.PopOverlay(layer);
	}

}