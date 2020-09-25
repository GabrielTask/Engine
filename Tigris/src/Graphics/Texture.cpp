#include "TGpch.h"
#include "Texture.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Tigris
{

	Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
	{
		return CreateRef<OpenGLTexture2D>(width, height);
	}

	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		return CreateRef<OpenGLTexture2D>(path);
	}

	Tigris::Ref<Tigris::Texture2D> Texture2D::Create(uint32_t width, uint32_t height, uint32_t ID)
	{
		return CreateRef<OpenGLTexture2D>(width, height, ID);
	}







}
