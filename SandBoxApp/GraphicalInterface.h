#pragma once
#include <stdint.h>
#include <Tigris.h>


class GraphicalInterface
{
public:

	GraphicalInterface() = default;
	GraphicalInterface(const Tigris::Ref<Tigris::Window>& window, uint32_t width = 50, uint32_t height = 50);

	void Begin();

	void End();

	void Resize(uint32_t width, uint32_t height);

	void OnEvent(Tigris::Event& e);

	static GraphicalInterface* s_Instance;
	static GraphicalInterface& Get();

	math::vec2 m_Position;
	bool IsSelected;
	bool IsFocused;
	uint32_t m_Width, m_Height;
private:
	Tigris::Ref<Tigris::Window> m_Window;
	//Tigris::Ref<Tigris::FrameBuffer> m_FrameBuffer;
	Tigris::Camera m_Camera;
	Tigris::CameraController m_Controller;
	//Tigris::Ref<Tigris::Texture2D> m_Texture;
};


bool Button(const math::vec2& pos, const math::vec2& size, uint32_t color, const math::vec2& posR = { 0.0f, 0.0f });
bool IsWithin(float xP, float yP, float _x, float _y, float _sx, float _sy);




