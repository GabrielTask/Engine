#include <Tigris.h>
#include <Base/EntryPoint.h>
#include <array>
#include <thread>
#include "Menu.h"
using namespace std::chrono_literals;

int n = 0;

//constexpr type operator"" name(unsigned long long _Val) noexcept{return 2 * _Val;}

class ExempleLayer : public Tigris::Layer 
{

public:
	void OnAtach() override
	{

		float aspc = Tigris::Application::Get()->GetWindow()->GetAspectRatio();
		m_Camera.SetOrthoProjection(-aspc, aspc, -1.0f, 1.0f, 0.0f, 1.0f);

		m_Camera.SetVelocity({ 0.01f,0.01f,0.0f });
		textureMap = Tigris::Texture2D::Create("D:/users/GABRIEL/Programming/c++/Engine/EngineEditor/src/assets/target_top.png");

		for (uint32_t j = 0; j < textureMap->GetWidth() / 64; j++)
			for (uint32_t i = 0; i < textureMap->GetHeight() / 64; i++)
			{
				textures[textureMap->GetHeight() / 64 * j + i] = Tigris::SubTexture2D::Create(textureMap, math::vec2(j, i), math::vec2(64.0f));
			}

	}


	void OnDetach() override
	{
	}


	void OnEvent(Tigris::Event& e) override
	{
		Tigris::Trigger t(e);

		t.Trig<Tigris::KeyReleasedEvent>([this](const Tigris::KeyReleasedEvent& e)->bool
			{
				switch (e.GetKey())
				{
				case 263:
					n--; break;
				case 262:
					n++; break;
				default:
					break;
				}

		return true;
			});

		t.Trig<Tigris::WindowResizedEvent>([this](const Tigris::WindowResizedEvent& e)->bool
			{
				float aspc = Tigris::Application::Get()->GetWindow()->GetAspectRatio();
				m_Camera;
				
				m_Camera.SetOrthoProjection(-aspc, aspc, -1.0f, 1.0f, -1.0f, 1.0f);
			
		return true;
			});

		t.Trig<Tigris::MouseScrolledEvent>([this](const Tigris::MouseScrolledEvent& e)->bool
			{
				float off = e.GetYoffset()/18.0f;
				m_Camera.Zoom({ off,off,0.0f });
				return true;
			});


		t.Trig<Tigris::DroppedEvent>([this](const Tigris::DroppedEvent& e)-> bool {

			textureMap = Tigris::Texture2D::Create(e.GetPath());

			for (uint32_t j = 0; j < textureMap->GetWidth() / 64; j++)
				for (uint32_t i = 0; i < textureMap->GetHeight() / 64; i++)
				{
					textures[textureMap->GetHeight() / 64 * j + i] = Tigris::SubTexture2D::Create(textureMap, math::vec2(j, i), math::vec2(64.0f));
				}

			return true;
			});

	}



	void OnUpdate(Tigris::TimeInterval dt) override
	{
		if (Tigris::Input::IsKeyPressed('L'))m_Camera.Rotate(0.1f);
		else if (Tigris::Input::IsKeyPressed('K'))m_Camera.Rotate(-0.1f);

		m_Camera.OnUpdate(dt);
		Tigris::Renderer2D::BeginBatch(m_Camera.GetCamera());

		for (int32_t j = 0; j < textureMap->GetWidth() / 64; j++)
			for (int32_t i = 0; i < textureMap->GetHeight() / 64; i++)
			{
				Tigris::Renderer2D::DrawRotated({ j,i,0.0f }, {1.0f,1.0f,0.0f},textures[textureMap->GetHeight() / 64 * j + i],3.1415936757/4.0f);
				Tigris::Renderer2D::DrawQuad({ -j,i,0.0f }, {1.0f,1.0f,0.0f},0xBB3378FF);
			}

		Tigris::Renderer2D::EndBatch();

	}


private:
	Tigris::CameraController m_Camera;
	Tigris::Ref<Tigris::Texture2D> textureMap;
	Tigris::Ref<Tigris::Texture2D> as;
	std::array<Tigris::Ref<Tigris::SubTexture2D>, 8*8> textures;


};


class Editor : public Tigris::Application 
{
public:
	Editor()
	{
		//PushLayer(new MenuLayer());	
		PushLayer(new ExempleLayer());	
	}
private:

};

Tigris::Application* CreateAppication()
{
	return new Editor();
 }