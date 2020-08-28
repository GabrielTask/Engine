#pragma once

#include "Graphics/Buffer.h"
#include "maths.h"

namespace Tigris
{
	enum class API
	{
		none=-1,OpenGL
	};

	class RendererAPI
	{
	public:
		virtual void Init() = 0;
		virtual void SetViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
		virtual void SetClearColor(const math::vec4& color) = 0;
		virtual void Clear() = 0;
		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t count = 0) = 0;
		static Scope<RendererAPI> Create();
		static API GetAPI() { return s_API; }
	private:
		static API s_API;
	};

}