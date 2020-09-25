#include <Tigris.h>
#include <Base/EntryPoint.h>
#include "GraphicalInterface.h"
#include "Panel.h"
#include "../imgui/imgui.h"

#include "Physics/a.h"


#include <thread>
#include <Mmsystem.h>
#include <mciapi.h>
//these two headers are already included in the <Windows.h> header
#pragma comment(lib, "Winmm.lib")

float WIDTH = 0;
float HEIGHT = 0;
float Size = 45.0f;

float MouseX0 = 0.0f;
float MouseY0 = 0.0f;

float MouseX1 = 0.0f;
float MouseY1 = 0.0f;

int32_t dmx;
int32_t dmy;

bool first = 1;
extern float d;
extern float e;
extern float f;
extern float g;
uint32_t moved = 0;
char ShallMove;
bool on = 0;

Body2D Body1;
Body2D Body2;
uint16_t volume = 0;

Tigris::Ref<Tigris::Texture> Circle;
Tigris::Ref<Tigris::Texture> Forest;

		constexpr float size = 45.0f;


		void moveToFace1();
		void moveToFace2();
		void moveToFace3();
		void moveToFace4();
		void moveToFace5();
		HWAVEOUT hWaveOut = 0;

		void Play()
		{
		
			mciSendString(L"open D:/users/GABRIEL/Programming/c++/Engine/clack.wav alias MyFile", NULL, 0, 0);
			waveOutSetVolume(hWaveOut, volume);
			mciSendString(L"play MyFile ", NULL, 0, 0);
		}
		std::thread it;
class BeginLayer : public Tigris::Layer
{
public:
	
	void OnAtach() override
	{
		
		//mciSendString(L"close MyFile", NULL, 0, 0);
		Forest = Tigris::Texture2D::Create("D:/users/GABRIEL/Programming/c++/Engine/forest.jpg");
		Face = GraphicalInterface(Tigris::Application::Get().GetWindow(), 9.0f*size, 16.0f*size);
		Face.Resize(9.0f * Size, 16.0f * Size);
		m_CamController.SetOrthoProjection(-(Tigris::Application::Get().GetWindow()->GetSize().first / 2.0f), (Tigris::Application::Get().GetWindow()->GetSize().first / 2.0f), -(Tigris::Application::Get().GetWindow()->GetSize().second / 2.0f), (Tigris::Application::Get().GetWindow()->GetSize().second / 2.0f), -100.0f, 100.0f);
		Circle = Tigris::Texture2D::Create("D:/users/GABRIEL/Programming/c++/Engine/EngineEditor/src/assets/Circle.png");
		Body1 = Body2D({ 0.0f,0.0f }, { 50.0f,50.0f }, 50.0f);
		//Body2 = Body2D({ 0.0f,50.0f }, { 50.0f,50.0f }, 50.0f, 0.0f);
	}


	void OnDetach() override
	{
	}


	void OnEvent(Tigris::Event& e) override
	{
		Face.OnEvent(e);
		Tigris::Trigger trigger(e);
		trigger.Trig<Tigris::MouseButtonClickedEvent>([&](Tigris::MouseButtonClickedEvent& e)
			{
				if (e.GetButton() == 0)
				{

					if (IsWithin(MouseX1, MouseY1, Face.m_Position.x- Face.m_Width /2.0f, Face.m_Position.y - Face.m_Height / 2.0f, Face.m_Width, Face.m_Height ))
					{
						Tigris::RenderCommand::SetClearColor({ 1.0f , 0.5f, 0.2f, 1.0f });
						Face.IsFocused = true;
					}

					else Face.IsFocused = false;
				}
			});

		trigger.Trig<Tigris::MouseButtonReleasedEvent>([&](Tigris::MouseButtonReleasedEvent& e)
			{
				if (e.GetButton() == 0)
				{
					moved = 0; 
					switch (ShallMove)
					{
					case 1:moveToFace1();break;
					case 2:moveToFace2();break;
					case 3:moveToFace3();break;
					case 4:moveToFace4();break;
					case 5:moveToFace5();break;
					}
					ShallMove = 0;
				}});

		trigger.Trig<Tigris::MouseMovedEvent>([&](Tigris::MouseMovedEvent& e)
		{
				moved ++;
		});

		trigger.Trig<Tigris::WindowResizedEvent>([&](Tigris::WindowResizedEvent& e) 
			{
				WIDTH = e.GetWidth();
				HEIGHT = e.GetHeight();
				float nh = Face.m_Height;
				float nw = Face.m_Height;
				if (HEIGHT < Face.m_Height)
					nh = HEIGHT;
				if (WIDTH < Face.m_Width)
					nw = WIDTH;
				Face.Resize(nw, nh);
			});

	}

	float xx;
	void moveToFace1()
	{
		Face.Resize(9.0f * size, 16.0f * size);
		Face.m_Position = { -xx + (Face.m_Width / 2.0f),0.0f };
		Face.IsSelected = false;
	}

	void moveToFace2()
	{
		Face.Resize(9.0f * size, 16.0f * size);
		Face.m_Position = { xx - (Face.m_Width / 2.0f),0.0f };
		Face.IsSelected = false;
	}	

	void moveToFace3()
	{
		Face.Resize(16.0f * size, 9.0f * size);
		Face.m_Position = { 0.0f,(Face.m_Height / 2.0f) - 45.0f };
		Face.IsSelected = false;
	}

	void moveToFace4()
	{
		Face.Resize(16.0f * size, 9.0f * size);
		Face.m_Position = { 0.0f,-(Face.m_Height / 2.0f) };
		Face.IsSelected = false;
	}

	void moveToFace5()
	{
		Face.Resize(Tigris::Application::Get().GetWindow()->GetSize().first, Tigris::Application::Get().GetWindow()->GetSize().second);
		Face.m_Position = { 0.0f,0.0f };
		Face.IsSelected = false;
	}


	void Docking()
	{

		static bool firti = true;

		if (Face.IsSelected)
		{
			if (firti)
			{
				Face.Resize(9.0f * Size, 16.0f * Size);
				MouseX0 = MouseX1;
				MouseY0 = MouseY1;
				firti = false;
			}

			dmx = MouseX1 - MouseX0;
			dmy = MouseY1 - MouseY0;
			MouseX0 = MouseX1;
			MouseY0 = MouseY1;
		}
		else firti = true;


		constexpr float wide = 50.0f;
		constexpr float narrow = 30.0f;
		float xPos = Tigris::Application::Get().GetWindow()->GetSize().first / 2.0f - wide / 2.0f - 8.0f;
		float yPos = Tigris::Application::Get().GetWindow()->GetSize().second / 2.0f - narrow / 2.0f - 18.0f;

		xx = Tigris::Application::Get().GetWindow()->GetSize().first / 2.0f;

		uint32_t color = 0x1122EEFF;
		uint32_t c1 = 0;
		uint32_t c2 = 0;
		uint32_t c3 = 0;
		uint32_t c4 = 0;
		uint32_t c5 = 0;
		if (Face.IsSelected && (moved || on))
		{
			Face.m_Position.x += dmx;
			Face.m_Position.y += dmy;
			on = true;
			if (IsWithin(MouseX1, MouseY1, -xPos - narrow / 2.0f, -wide / 2.0f, narrow, wide))
			{
				c1 = 0x11111100;
				ShallMove = 1;
				Tigris::Renderer2D::DrawQuad({ -xx + (Face.m_Width / 2.0f),0.0f }, { 9.0f * size, 16.0f * size }, 0x11112288);
			}
			else if (IsWithin(MouseX1, MouseY1, xPos - narrow / 2.0f, -wide / 2.0f, narrow, wide))
			{
				c2 = 0x11111100;
				ShallMove = 2;
				Tigris::Renderer2D::DrawQuad({ xx - (Face.m_Width / 2.0f),0.0f }, { 9.0f * size, 16.0f * size }, 0x11112288);
			}
			else if (IsWithin(MouseX1, MouseY1, -wide / 2.0f, yPos - narrow / 2.0f, wide, narrow))
			{
				c3 = 0x11111100;
				ShallMove = 3;
				Tigris::Renderer2D::DrawQuad({ 0.0f, (Face.m_Height / 2.0f) - 45.0f }, { 16.0f * size, 9.0f * size }, 0x11112288);

			}
			else if (IsWithin(MouseX1, MouseY1, -wide / 2.0f, -yPos - narrow / 2.0f, wide, narrow))
			{
				c4 = 0x11111100;
				ShallMove = 4;
				Tigris::Renderer2D::DrawQuad({ 0.0f,-(Face.m_Height / 2.0f) }, { 16.0f * size, 9.0f * size }, 0x11112288);

			}
			else if (IsWithin(MouseX1, MouseY1, -wide / 2.0f, -wide / 2.0f, wide, wide))
			{
				c5 = 0x11111100;
				ShallMove = 5;
				Tigris::Renderer2D::DrawQuad({ 0.0f,0.0f }, { 16.0f * size, 9.0f * size }, 0x11112288);

			}

			else
			{


				if (Face.m_Position.y + Face.m_Height / 2.0f > (float)(int)Tigris::Application::Get().GetWindow()->GetSize().second / 2.0f)
					Face.m_Position.y = ((float)(int)Tigris::Application::Get().GetWindow()->GetSize().second - Face.m_Height) / 2.0f;
				else if (Face.m_Position.y + Face.m_Height / 2.0f - 30.0f < (float)(int)Tigris::Application::Get().GetWindow()->GetSize().second / -2.0f)
					Face.m_Position.y = -(Face.m_Height / 2.0f) + 30.0f + Tigris::Application::Get().GetWindow()->GetSize().second / -2.0f;
			}

			Tigris::Renderer2D::DrawQuad({ -xPos, 0.0f }, { narrow,wide }, 0x1122EEFF + c1);
			Tigris::Renderer2D::DrawQuad({ xPos, 0.0f }, { narrow,wide }, 0x1122EEFF + c2);

			Tigris::Renderer2D::DrawQuad({ 0.0f,  yPos }, { wide,narrow }, 0x1122EEFF + c3);
			Tigris::Renderer2D::DrawQuad({ 0.0f, -yPos }, { wide,narrow }, 0x1122EEFF + c4);

			Tigris::Renderer2D::DrawQuad({ 0.0f,  0.0f }, { wide,wide }, 0x1122EEFF + c5);
		}
	}



	void OnUpdate(Tigris::TimeInterval dt) override
	{
		if (moved>0)moved++;
		if (moved > 10)moved = 0;
		
		MouseX1 = (Tigris::Input::GetMousePosition().x - Tigris::Application::Get().GetWindow()->GetSize().first / 2.0f);
		MouseY1 = -(Tigris::Input::GetMousePosition().y - Tigris::Application::Get().GetWindow()->GetSize().second / 2.0f);
	//	printf("%f/n", m_CamController.GetCamera().GetViewProjection()[0][0]* Tigris::Application::Get().GetWindow()->GetSize().first);
		Tigris::RenderCommand::SetClearColor({ 80.0f / 255.0f,183.5f / 255.0f,226.0f / 255.0f,1.0f });
		Tigris::RenderCommand::Clear();
		


		if (Size < 0.0f)Size = 0.0f;
	
		Body1.m_Force.y += -0.01f;
	
		UpdateBody(Body1);

	
		if (Body1.bottom()  <= -(WIDTH/2.0f)) {
			Body1.m_Velocity.y = 0.96f * abs(Body1.m_Velocity.y);
			Body1.m_Position.y = Body1.m_Size.y / 2.0f - 720.0f / 2.0f;
		}


		if (Body1.right() >= 1280.0f / 2.0f)
		{
			Body1.m_Position.x = -Body1.m_Size.x / 2.0f +1280.0f / 2.0f;
			Body1.m_Velocity.x = -abs(Body1.m_Velocity.x);
		}
		else if (Body1.left()  <= -1280.0f / 2.0f)
		{
			Body1.m_Position.x = Body1.m_Size.x / 2.0f - 1280.0f / 2.0f;
			Body1.m_Velocity.x = abs(Body1.m_Velocity.x);
		}





		

		//if (it.joinable())it.join();
		static float angle = 0.0f;
		//Tigris::Renderer2D::DrawRotated({ 0.0f,0.0f }, { 500.0f,500.0f }, Forest, angle);
		angle += 0.0001f;
		//Tigris::Renderer2D::DrawQuad({ f,  0.0f }, {70.0f,70.0f }, Circle, UINT_MAX- 0x1122EE00 );
		Face.Begin();
		DrawBody(Body1,Circle);
		Face.End();

		Tigris::Renderer2D::BeginBatch(m_CamController.GetCamera());

		Docking();
		Tigris::Renderer2D::EndBatch();

		
	}
	




float vol = 0.0f;

	void OnImguiRender(Tigris::TimeInterval dt) override
	{
		 
		ImGui::DragFloat("Volume", &vol,0.1f);
		if (vol < 0)vol = 0;
		else if (vol > 100)vol = 100;

		volume = (uint16_t)(uint32_t)(655.350f * vol);
		
	
	}

private:
	GraphicalInterface Face;
	Tigris::CameraController m_CamController;

};

class Editor : public Tigris::Application
{
public:
	Editor()
	{
		//PushLayer(new MenuLayer());	
		PushLayer(new BeginLayer());
	}
private:


};


Tigris::Application* CreateApplication()
{
	return new Editor();
}