#include <Tigris.h>
#include <Base/EntryPoint.h>
#include "../imgui/imgui.h"
#include <array>
#include <thread>
#include "Menu.h"
#include "../src/Platform/OpenGL/OpenGLTexture.h"


using namespace std::chrono_literals;
int n = 0;
math::vec2 Position;
float tt = 0.0f;
Tigris::Camera other;
//constexpr type operator"" name(unsigned long long _Val) noexcept{return 2 * _Val;}

class ExempleLayer : public Tigris::Layer 
{

public:
	void OnAtach() override
	{
		as = Tigris::Texture2D::Create(1,1);
		 uint32_t whiteColor = UINT_MAX;
		as->SetData(&whiteColor, sizeof(uint32_t));

		float aspc = Tigris::Application::Get().GetWindow()->GetAspectRatio();
		m_Camera.SetOrthoProjection(-aspc, aspc, -1.0f, 1.0f, 0.0f, 1.0f);

		m_Camera.SetVelocity({ 0.01f,0.01f,0.0f });
		textureMap = Tigris::Texture2D::Create("D:/users/GABRIEL/Programming/c++/Engine/EngineEditor/src/assets/target_top.png");
		for (uint32_t j = 0; j < textureMap->GetWidth() / 64; j++)
			for (uint32_t i = 0; i < textureMap->GetHeight() / 64; i++)
			{
				textures[textureMap->GetHeight() / 64 * j + i] = Tigris::SubTexture2D::Create(textureMap, math::vec2(j, i), math::vec2(64.0f));
			}
		Tigris::FrameBufferSpecification fspec;
		memcpy(&fspec.Width, &Tigris::Application::Get().GetWindow()->GetSize(), 8);

		m_FrameBuffer = Tigris::FrameBuffer::Create(fspec);
		testing = Tigris::Texture2D::Create(fspec.Width, fspec.Height, m_FrameBuffer->GetColorAttachmentRendererID());
		//testing->GetRendererID() = m_FrameBuffer->GetColorAttachmentRendererID();
		other.GetViewProjection() = math::mat4(1.0f);
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
				float aspc = Tigris::Application::Get().GetWindow()->GetAspectRatio();
				m_Camera;
				
				//m_Camera.SetOrthoProjection(-aspc, aspc, -1.0f, 1.0f, -1.0f, 1.0f);
			
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
		m_FrameBuffer->Bind();
		Tigris::RenderCommand::SetClearColor({ 80.0f / 255.0f,183.5f / 255.0f,226.0f / 255.0f,1.0f });
		Tigris::RenderCommand::Clear();
		if (Tigris::Input::IsKeyPressed('L'))m_Camera.Rotate(0.1f);
		else if (Tigris::Input::IsKeyPressed('K'))m_Camera.Rotate(-0.1f);

		m_Camera.OnUpdate(dt);
		Tigris::Renderer2D::BeginBatch(m_Camera.GetCamera());

		for (int32_t j = 0; j < textureMap->GetWidth() / 64; j++)
			for (int32_t i = 0; i < textureMap->GetHeight() / 64; i++)
			{
				Tigris::Renderer2D::DrawQuad({ -j,i}, {1.0f,1.0f},0xBB3378FF);
				Tigris::Renderer2D::DrawRotated(Position+math::vec2( j,i), {1.0f,1.0f},textures[textureMap->GetHeight() / 64 * j + i],3.1415936757/4.0f);
			}

		Tigris::Renderer2D::EndBatch();

		m_FrameBuffer->UnBind();

	  Tigris::RenderCommand::SetClearColor({0.8f,0.4f,0.6f,1.0f});
		Tigris::RenderCommand::Clear();
		Tigris::Renderer2D::BeginBatch(m_Camera.GetCamera());
		Tigris::Renderer2D::DrawQuad({ -0.5f,0.0f }, { 1.0f,1.0f }, testing);

		Tigris::Renderer2D::EndBatch();
	}




	bool p_open = 0;
	void OnImguiRender(Tigris::TimeInterval dt) override
	{	
		if (p_open) {

			static bool opt_fullscreen_persistant = true;
			static ImGuiDockNodeFlags opt_flags = ImGuiDockNodeFlags_None;
			bool opt_fullscreen = opt_fullscreen_persistant;

			// We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
			// because it would be confusing to have two docking targets within each others.
			ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
			if (opt_fullscreen)
			{
				ImGuiViewport* viewport = ImGui::GetMainViewport();
				ImGui::SetNextWindowPos(viewport->Pos);
				ImGui::SetNextWindowSize(viewport->Size);
				ImGui::SetNextWindowViewport(viewport->ID);
				ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
				ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
				window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
				window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
			}

			// When using ImGuiDockNodeFlags_PassthruDockspace, DockSpace() will render our background and handle the pass-thru hole, so we ask Begin() to not render a background.
			if (opt_flags & ImGuiDockNodeFlags_PassthruDockspace)
				window_flags |= ImGuiWindowFlags_NoBackground;

			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
			ImGui::Begin("DockSpace Demo", &p_open, window_flags);
			ImGui::PopStyleVar();

			if (opt_fullscreen)
				ImGui::PopStyleVar(2);

			// Dockspace
			ImGuiIO& io = ImGui::GetIO();
			if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
			{
				ImGuiID dockspace_id = ImGui::GetID("MyDockspace");
				ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), opt_flags);
			}

			if (ImGui::BeginMenuBar())
			{
				if (ImGui::BeginMenu("File"))
				{
					if (ImGui::MenuItem("Exit"))
					{
						Tigris::Application::Get().OnEvent(Tigris::WindowClosedEvent());
					}
					ImGui::EndMenu();
				}

				ImGui::EndMenuBar();
			}

			ImGui::Begin("Testing");
			
			float aspc = ImGui::GetWindowSize().x/ ImGui::GetWindowSize().y;

			m_Camera.SetOrthoProjection(-aspc, aspc, -1.0f, 1.0f, -1.0f, 1.0f);
			ImGui::Image((void*)m_FrameBuffer->GetColorAttachmentRendererID(), ImGui::GetWindowSize());
	
			
			ImGui::End();
			ImGui::End();
		}



	}

private:
	Tigris::CameraController m_Camera;
	Tigris::Ref<Tigris::Texture2D> textureMap;
	Tigris::Ref<Tigris::Texture2D> as;
	Tigris::Ref<Tigris::Texture2D> testing;
	Tigris::Ref<Tigris::Texture2D> testing2;
	std::array<Tigris::Ref<Tigris::SubTexture2D>, 8*8> textures;
	Tigris::Ref<Tigris::FrameBuffer> m_FrameBuffer;



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

Tigris::Application* CreateApplication()
{
	return new Editor();
 }