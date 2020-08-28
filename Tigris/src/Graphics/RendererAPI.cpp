#include "TGpch.h"
#include "RendererAPI.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"
namespace Tigris
{


	API RendererAPI::s_API = API::OpenGL;

	Tigris::Scope<Tigris::RendererAPI> RendererAPI::Create()
	{
		switch (RendererAPI::s_API)
		{
		case API::OpenGL: return CreateScope<OpenGLRendererAPI>();
		default:
			return nullptr;
			break;
		}
	}

}