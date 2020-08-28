#include "TGpch.h"
#include "Buffer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"
#include "RenderCommand.h"
namespace Tigris
{


	Ref<IndexBuffer> IndexBuffer::Create(uint32_t size, void* data /*= nullptr*/)
	{
		switch (RenderCommand::GetAPI())
		{
		case API::OpenGL:
			return CreateRef<OpenGLIndexBuffer>(size, data);
		default:
			break;
		}
	}

	Ref<VertexBuffer> VertexBuffer::Create(uint32_t size, void* data /*= nullptr*/)
	{
		switch (RenderCommand::GetAPI())
		{
		case API::OpenGL:
		return CreateRef<OpenGLVertexBuffer>(size, data);
		default:
			break;
		}
	}

	Ref<VertexArray> VertexArray::Create()
	{
		switch (RenderCommand::GetAPI())
		{
		case API::OpenGL:
		return CreateRef<OpenGLVertexArray>();
		default:
			break;
		}
	}

	uint32_t GetElementCount(ElementType type)
	{
		switch (RenderCommand::GetAPI())
		{
		case API::OpenGL:
		return (uint32_t)type % 4 + 1;
		default:
			break;
		}
	}





	uint32_t GetSize(ElementType type)
	{
		uint32_t result = GetElementCount(type);
		if ((uint32_t)type < 12)
			return result * 4;
		if ((uint32_t)type < 20)
			return result * 2;
		if ((uint32_t)type < 28)
			return result * 1;
		return -1;
	}

	uint32_t GetOpenGLType(ElementType type)
	{
#define GL_BYTE                           0x1400
#define GL_UNSIGNED_BYTE                  0x1401
#define GL_SHORT                          0x1402
#define GL_UNSIGNED_SHORT                 0x1403
#define GL_INT                            0x1404
#define GL_UNSIGNED_INT                   0x1405
#define GL_FLOAT                          0x1406
#define GL_2_BYTES                        0x1407
#define GL_3_BYTES                        0x1408
#define GL_4_BYTES                        0x1409
#define GL_DOUBLE                         0x140A


		uint32_t result = GetElementCount(type);
		if ((uint32_t)type < 4)
			return GL_FLOAT;
		if ((uint32_t)type < 8)
			return GL_INT;
		if ((uint32_t)type < 12)
			return GL_UNSIGNED_INT;
		if ((uint32_t)type < 16)
			return GL_SHORT;
		if ((uint32_t)type < 20)
			return GL_UNSIGNED_SHORT;
		if ((uint32_t)type < 24)
			return GL_BYTE;
		if ((uint32_t)type < 28)
			return GL_UNSIGNED_BYTE;
	}

}