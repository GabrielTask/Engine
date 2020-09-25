#pragma once
#include "maths.h"
#include "Camera.h"
#include "RenderCommand.h"
#include "Texture.h"



namespace Tigris
{




	class Renderer2D
	{
	public:
		Renderer2D() = delete;
		static bool Init();
		static void BeginBatch(Camera& camera);
		static void EndBatch();

		static void DrawQuad(const math::vec2& position, const math::vec2& scale, uint32_t tintColor);
		static void DrawQuad(const math::vec2& position, const math::vec2& scale, Ref<Texture> texture, uint32_t tintColor = 0xffffffff);
		static void DrawQuad(const math::vec2& position, const math::vec2& scale, Ref<SubTexture2D> texture, uint32_t tintColor = 0xffffffff);

		static void DrawRotated(const math::vec2& position, const math::vec2& scale, uint32_t tintColor, float angle);
		static void DrawRotated(const math::vec2& position, const math::vec2& scale, Ref<Texture> texture, float angle, uint32_t tintColor = 0xffffffff);
		static void DrawRotated(const math::vec2& position, const math::vec2& scale, Ref<SubTexture2D> texture, float angle, uint32_t tintColor = 0xffffffff);
	private:


		static uint32_t CheckTexture(Ref<Texture> texture);
		static void flush();

	};

}