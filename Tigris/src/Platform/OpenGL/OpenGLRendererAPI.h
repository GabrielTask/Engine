#pragma once
#include "Graphics/RendererAPI.h"

namespace Tigris
{

	class OpenGLRendererAPI : public RendererAPI
	{

	public:
		OpenGLRendererAPI() = default;
		void Init() override;


		void SetViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;


		void SetClearColor(const math::vec4& color) override;


		void Clear() override;


		void DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t count = 0) override;

	};

}