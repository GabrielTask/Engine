#pragma once
#include "../Math/maths.h"
#include "Tigris.h"


struct Body2D
{
	Body2D() = default;
	Body2D(math::vec2 position, math::vec2 size, float mass):
		m_Position(position), m_Size(size), m_Mass(mass)
	{
		m_Rotation = 0.0f;
		m_Force = { 0.0f,0.0f };
		m_Velocity = { 0.0f,0.0f };
	}

	math::vec2 m_Position;
	math::vec2 m_Size;
	math::vec2 m_Force;
	math::vec2 m_Velocity;
	float m_Rotation;
	float m_Mass;



	inline float left()const { return m_Position.x - m_Size.x / 2.0f; };
	inline float right()const { return m_Position.x + m_Size.x / 2.0f; };
	inline float bottom()const { return m_Position.y - m_Size.y/2.0f; };
	inline float top()const { return m_Position.y + m_Size.y / 2.0f; };
};



void DrawBody(Body2D& b, const Tigris::Ref<Tigris::Texture>& tex);

void UpdateBody(Body2D& b);
void ApplyForce(Body2D& b, math::vec2 force);
bool IsColliding(Body2D& a, Body2D& b);
bool IsCircleColliding(Body2D& a, Body2D& b);


