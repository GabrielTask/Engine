#pragma once
#include "Graphics/RendererAPI.h"
#include "maths.h"


namespace Tigris
{
	class RenderCommand
	{
	public:
		static void Init();
		static void SetViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
		static void SetClearColor(const math::vec4& color);
		static void Clear();
		static void DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t count = 0);
		static API GetAPI() { return s_RendererAPI->GetAPI(); }
	private:
		static Scope<RendererAPI> s_RendererAPI;
	};
}