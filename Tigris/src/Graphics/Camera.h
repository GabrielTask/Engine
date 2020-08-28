#pragma once
#include "maths.h"
#include "Base/Time.h"

namespace Tigris
{
	class Camera
	{
	public:
		Camera();
		void SetOrthoProjection(float left, float right, float bottom, float top, float ZNear, float zFar);

		math::mat4& GetViewProjection();
		const math::mat4& GetViewProjection()const;
		const math::mat4& GetProjection();
	private:
		math::mat4 m_Projection;
		math::mat4 m_ViewProjection;

	};


	class CameraController
	{
	public:
		CameraController(float rotation = 0.0f, const math::vec3& position = math::vec3(0.0f), const math::vec3& zoom = math::vec3(1.0f), const math::vec3& velocity = math::vec3(0.0f));
		Camera& GetCamera() { return m_Camera; }
		void SetOrthoProjection(float left, float right, float bottom, float top, float ZNear, float zFar);
		void SetVelocity(const math::vec3& velocity);
		void Displace(const math::vec3& displacement);
		void Displace(float x = 0.0f, float y = 0.0f, float z = 0.0f);
		void Rotate(float angle);
		void Zoom(const math::vec3& mag);
		void OnUpdate(Tigris::TimeInterval dt);
	private:
		float m_Rotation;
		Camera m_Camera;
		math::vec3 m_Position;
		math::vec3 m_Zoom;
		math::vec3 m_Velocity;
	};


	
	
}