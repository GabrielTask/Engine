#pragma once
#include "TGpch.h"
#include "RenderCommand.h"
#include "RendererAPI.h"

namespace Tigris
{
	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

	void RenderCommand::Init()
	{
		s_RendererAPI->Init();
	}

	void RenderCommand::SetViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
		s_RendererAPI->SetViewPort(x,y,width,height);
	}

	void RenderCommand::SetClearColor(const math::vec4& color)
	{
		s_RendererAPI->SetClearColor(color);
	}

	void RenderCommand::Clear()
	{
		s_RendererAPI->Clear();
	}

	void RenderCommand::DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t count /*= 0*/)
	{
		s_RendererAPI->DrawIndexed(vertexArray,count);
	}


}