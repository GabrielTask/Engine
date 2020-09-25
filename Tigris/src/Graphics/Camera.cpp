#include "TGpch.h"
#include "Camera.h"
#include "Base/Input.h"
#include "maths.h"

namespace Tigris
{


	Camera::Camera() : m_Projection(1.0f), m_ViewProjection(0)
	{

	}

	void Camera::SetOrthoProjection(float left, float right, float bottom, float top, float ZNear, float zFar)
	{
		m_Projection = glm::ortho(left, right, bottom, top);
		m_ViewProjection = m_Projection;
	}
	const math::mat4& Camera::GetViewProjection()const
	{
		return m_ViewProjection;
	}

	math::mat4& Camera::GetViewProjection()
	{
		return m_ViewProjection;
	}

	const math::mat4& Camera::GetProjection()
	{
		return m_Projection;
	}



	CameraController::CameraController(float rotation /*= 0.0f*/, const math::vec3& position /*= math::vec3(0.0f)*/, const math::vec3& zoom /*= math::vec3(1.0f)*/, const math::vec3& velocity /*= math::vec3(0.0f)*/) :m_Rotation(rotation), m_Position(position), m_Zoom(zoom), m_Velocity(velocity)
	{

	}

	void CameraController::SetOrthoProjection(float left, float right, float bottom, float top, float ZNear, float zFar)
	{
		m_Camera.SetOrthoProjection(left, right, bottom, top, ZNear, zFar);
	}

	void CameraController::SetVelocity(const math::vec3& velocity) 
	{
		m_Velocity = velocity;
	}

	void CameraController::Displace(const math::vec3& displacement)
	{
		math::Complex d = math::Complex(cos(m_Rotation), sin(m_Rotation))* math::Complex(displacement.x, displacement.y);

		m_Position.x-=d.R()/m_Zoom.x;
		m_Position.y-=d.I() / m_Zoom.y;
		m_Position.z-=displacement.z;
	}

	void CameraController::Displace(float x /*= 0.0f*/, float y /*= 0.0f*/, float z /*= 0.0f*/)
	{
		m_Position.x -= x;
		m_Position.y -= y;
		m_Position.z -= z;
	}

	void CameraController::Rotate(float angle)
	{
		m_Rotation -= angle;
	}


	void CameraController::Zoom(const math::vec3& mag)
	{
		m_Zoom += mag * m_Zoom.x;
	}

	void CameraController::OnUpdate(Tigris::TimeInterval dt)
	{
		Displace({ Input::IsKeyPressed('D') * m_Velocity.x * dt,Input::IsKeyPressed('W') * m_Velocity.y * dt,0.0f });
		Displace({ -Input::IsKeyPressed('A') * m_Velocity.x * dt,-Input::IsKeyPressed('S') * m_Velocity.y * dt,0.0f });

		if (m_Rotation > 6.283185f)
			m_Rotation -= 6.283185f;
		if (m_Rotation < 0.0f)
			m_Rotation += 6.283185f;

		m_Camera.GetViewProjection() = glm::translate(glm::rotate(glm::scale(m_Camera.GetProjection(),m_Zoom), m_Rotation, { 0.0f,0.0f,1.0f }), m_Position);
	}

}