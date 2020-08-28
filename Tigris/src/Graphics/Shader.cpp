#include "TGpch.h"
#include "Shader.h"
#include "Platform/OpenGL/OpenGLShader.h"
#include "RenderCommand.h"

namespace Tigris
{


	Ref<Shader> Shader::Create(const char* VsSrc, const char* fsSrc)
	{
		switch (RenderCommand::GetAPI())
		{
		case API::OpenGL:
		return CreateRef<OpenGLShader>(VsSrc, fsSrc);
		default:
			break;
		}
	}

	Ref<Shader> Shader::Create(const char* Vpath, const char* Fpath, const char* path)
	{
		switch (RenderCommand::GetAPI())
		{
		case API::OpenGL:
		return CreateRef<OpenGLShader>(Vpath, Fpath, path);
		default:
			break;
		}
	}

	Ref<Shader> Shader::Create(const char* path)
	{
		switch (RenderCommand::GetAPI())
		{
		case API::OpenGL:
		return CreateRef<OpenGLShader>(path);
		default:
			break;
		}
	}
}