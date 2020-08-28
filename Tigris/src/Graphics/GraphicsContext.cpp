#include "TGpch.h"

#include "GraphicsContext.h"
#include "Platform/OpenGL/OpenGLContext.h"
#include "RenderCommand.h"
namespace Tigris
{


	Scope<GraphicsContext> GraphicsContext::Create(void * Window)
	{
		switch (RenderCommand::GetAPI())
		{
		case API::OpenGL:
			return CreateScope<OpenGLContext>(Window);
		default:
			break;
		}
	}

}