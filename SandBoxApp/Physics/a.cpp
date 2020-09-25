#include "a.h"

void DrawBody(Body2D& b, const Tigris::Ref<Tigris::Texture>& tex)
{
	Tigris::Renderer2D::DrawQuad(b.m_Position, b.m_Size, tex, 0x123412ff);
}

void UpdateBody(Body2D& b)
{
	b.m_Velocity += b.m_Force / b.m_Mass;
	b.m_Force = math::vec2(0.0f);
	b.m_Position += b.m_Velocity;

}

void ApplyForce(Body2D& b, math::vec2 force)
{
	b.m_Force += force;
}

bool IsColliding(Body2D& a, Body2D& b)
{
	if (a.m_Position.x + a.m_Size.x / 2.0f < b.m_Position.x - b.m_Size.x / 2.0f || a.m_Position.x + a.m_Size.x / 2.0f > b.m_Position.x + b.m_Size.x / 2.0f)return false;
	if (a.m_Position.y + a.m_Size.y / 2.0f < b.m_Position.y - b.m_Size.y / 2.0f || a.m_Position.y + a.m_Size.y / 2.0f > b.m_Position.y + b.m_Size.y / 2.0f)return false;
	return true;
}

bool IsCircleColliding(Body2D& a, Body2D& b)
{
	return ((a.m_Size.x+b.m_Size.x)/2.0f>(glm::length(a.m_Position-b.m_Position)));
}

