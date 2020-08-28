#include "Menu.h"
#include <utility>



void MenuLayer::OnAtach()
{
	auto [width, height] = Tigris::Application::Get()->GetWindow()->GetSize();
	m_Camera.SetOrthoProjection(-(width / 2.0f), width / 2.0f, -(height / 2.0f), height / 2.0f, -1.0f, 1.0f);
	m_Camera.GetViewProjection() = m_Camera.GetProjection();
}

void MenuLayer::OnDetach()
{
	
}

void MenuLayer::OnEvent(Tigris::Event& e)
{
	Tigris::Trigger trigger(e);
	trigger.Trig<Tigris::KeyPressedEvent>([](Tigris::KeyPressedEvent& e)->bool
		{
			return true;
		});

}

void MenuLayer::OnUpdate(Tigris::TimeInterval dt)
{

	Tigris::Renderer2D::BeginBatch(m_Camera);

	Tigris::Renderer2D::DrawQuad({ 0.0f,0.0f,0.0f }, { 50.0f,50.0f,0.0f}, 0xff00ffff);


	Tigris::Renderer2D::EndBatch();
}

