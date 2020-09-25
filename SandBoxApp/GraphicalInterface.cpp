#include "GraphicalInterface.h"

extern math::vec2 RedPos;
uint32_t Coloring = 0xff0000ff;
uint32_t cor = Coloring;
GraphicalInterface* GraphicalInterface::s_Instance = nullptr;
float MouseX;
float MouseY;
float d = 0.0f;
float e = 0.0f;
float f = 0.0f;
float g = 0.0f;
uint32_t timePressed = 0;

extern float MouseX1;
extern float MouseY1;

bool IsWithin(float xP, float yP, float _x, float _y, float _sx, float _sy)
{

	return 	((xP <= _x + _sx && xP >= _x) && (yP <= _y + _sy && yP >= _y));
}

bool Button(const math::vec2& pos, const math::vec2& size, uint32_t color, const math::vec2& posR)
{
	math::vec2 Pos = pos + posR;
	//printf("Mouse: (%.f - %.f) (%.f - %.f)\n", MouseX1, MouseY1, Pos.x, Pos.y);
	uint32_t Color = color;
	math::vec2 Size = size;
	bool result = false;
	if(IsWithin(MouseX1, MouseY1, Pos.x-size.x/2.0f, Pos.y - size.y / 2.0f, size.x, size.y))
	{
		*(((uint8_t*)&Color) + 0) += 0x15;
		*(((uint8_t*)&Color) + 1) += 0x15;
		*(((uint8_t*)&Color) + 2) += 0x15;
	
		if (Tigris::Input::IsMousePressed(0))
		{
			*(((uint8_t*)&Color) + 0) += 0x25;
			*(((uint8_t*)&Color) + 1) += 0x25;
			*(((uint8_t*)&Color) + 2) += 0x25;
			Size*=0.9f;
			result = (timePressed == 1);
		}
	}
	if (result)timePressed++;
	Tigris::Renderer2D::DrawQuad(pos, Size, Color);
	return result;
	
}

int lw, lh;
GraphicalInterface::GraphicalInterface(const Tigris::Ref<Tigris::Window>& window, uint32_t width /*= 50*/, uint32_t height /*= 50*/) :m_Window(window), m_Width(width), m_Height(height),m_Position(0.0f)
{
	s_Instance = this;
	//m_FrameBuffer = Tigris::FrameBuffer::Create({ width,height });
	Resize(width, height);

	auto [w, h] = Tigris::Application::Get().GetWindow()->GetSize();
	m_Camera.SetOrthoProjection(-(w / 2.0f), (w / 2.0f), -(h / 2.0f), (h / 2.0f), -100.0f, 100.0f);
	//m_Texture = Tigris::Texture2D::Create(width, height, m_FrameBuffer->GetColorAttachmentRendererID());
	lw = w;
	lh = h;
	IsFocused = false;
	IsSelected = false;

	m_Controller = Tigris::CameraController();
	m_Controller.SetVelocity(math::vec3(0.1f));



}

void GraphicalInterface::Begin()
{
	timePressed += Tigris::Input::IsMousePressed(0);

	Tigris::RenderCommand::Clear();

	//Tigris::Renderer2D::BeginBatch(m_Controller.GetCamera());

	MouseX = Tigris::Input::GetMousePosition().x - m_Position.x - (Tigris::Application::Get().GetWindow()->GetSize().first - m_Width) / 2.0f;
	MouseY = Tigris::Input::GetMousePosition().y + m_Position.y - (Tigris::Application::Get().GetWindow()->GetSize().second - m_Height) / 2.0f;
	

	Tigris::Renderer2D::BeginBatch(m_Camera);
	Tigris::Renderer2D::DrawQuad(m_Position, { m_Width,m_Height }, IsFocused ? 0xffee99FF : 0xCC8833FF);
	Tigris::Renderer2D::DrawQuad(m_Position + math::vec2(0.0f, m_Height / 2.0f - 15.0f), { m_Width,30.0f }, 0xDDDDDDFF);
	Tigris::Renderer2D::EndBatch();

	//Tigris::RenderCommand::SetViewPort((Tigris::Application::Get().GetWindow()->GetSize().first - m_Width) / 2.0f + m_Position.x, m_Position.y, m_Width, m_Height);
	Tigris::RenderCommand::SetViewPort((Tigris::Application::Get().GetWindow()->GetSize().first - m_Width) / 2.0f + m_Position.x, (Tigris::Application::Get().GetWindow()->GetSize().second - m_Height) / 2.0f + m_Position.y, m_Width, m_Height);
	Tigris::Renderer2D::BeginBatch(m_Controller.GetCamera());
	Button({ 0.0f,0.0f }, { 50.0f,50.0f }, 0x887733FF, m_Position);

}

void GraphicalInterface::End()
{
	Tigris::Renderer2D::EndBatch();

	Tigris::RenderCommand::SetViewPort(0, 0, Tigris::Application::Get().GetWindow()->GetSize().first, Tigris::Application::Get().GetWindow()->GetSize().second);


	                                 
	if (timePressed == 1 && IsFocused && IsWithin(MouseX1, MouseY1, m_Position.x - (m_Width / 2.0f), m_Position.y+m_Height/2.0f-30.0f , m_Width, 30.0f)) IsSelected = true;
	IsSelected = (timePressed > 0 && IsSelected);
}

void GraphicalInterface::Resize(uint32_t width, uint32_t height)
{	
	if (m_Width == width && m_Height == height)return;

	//m_FrameBuffer->Resize(width, height);
	m_Controller.SetOrthoProjection(-(width / 2.0f), width / 2.0f, -(height / 2.0f), height / 2.0f, -100.0f, 100.0f);
	m_Height = height;
	m_Width = width;

}


void GraphicalInterface::OnEvent(Tigris::Event& e)
{
	Tigris::Trigger trigger(e);
	trigger.Trig<Tigris::WindowResizedEvent>([&](Tigris::WindowResizedEvent& e)
		{
			uint32_t w = e.GetWidth() > 0.0f ? e.GetWidth() : 1;
			uint32_t h = e.GetHeight() > 0.0f ? e.GetHeight() : 1;
			//m_Camera.SetOrthoProjection(-(w / 2.0f), (w / 2.0f), -(h / 2.0f), (h / 2.0f), -100.0f, 100.0f);
		//	Resize(m_Width * w / lw, m_Height * h / lh);
			//lw = w;
		//lh = h;
			//Resize(1280.0f/200 * w, 200 * 720 / h);
		});

	trigger.Trig<Tigris::MouseButtonReleasedEvent>([&](Tigris::MouseButtonReleasedEvent& e)
		{if (e.GetButton() == 0)timePressed=0;});



}

GraphicalInterface& GraphicalInterface::Get()
{
	return *s_Instance;
}



