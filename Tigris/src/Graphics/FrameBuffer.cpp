#include "TGpch.h"
#include "FrameBuffer.h"

#include "Graphics/RenderCommand.h"
#include "Platform/OpenGL/OpenGLFrameBuffer.h"

namespace Tigris
{
	

	Tigris::Ref<Tigris::FrameBuffer> FrameBuffer::Create(const FrameBufferSpecification& spec)
	{
		switch (RenderCommand::GetAPI())
		{
		case API::OpenGL: return CreateRef<OpenGLFrameBuffer>(spec); 
		}
		return nullptr;
	}

}