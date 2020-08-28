#include "TGpch.h"
#include "OpenGLBuffer.h"
#include "glad/glad.h"

namespace Tigris
{

	



	

	//&Renderer2Ddata.r_Vertices
	


	


	
//-------------------------------------------------------------------------------------------------------------------------------------------//
	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t size, void* data /*= nullptr*/)
	{
		glGenBuffers(1, &m_RendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void OpenGLIndexBuffer::SetData(uint32_t size, const void* data)
	{
		
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, size, data);
	}

	void OpenGLIndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	}


//-------------------------------------------------------------------------------------------------------------------------------------------//
	OpenGLVertexBuffer::OpenGLVertexBuffer(uint32_t size, void* data /*= nullptr*/)
	{
		glGenBuffers(1, &m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

	}

	void OpenGLVertexBuffer::SetData(uint32_t size, const void* data)
	{
		
		glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
	}

	void OpenGLVertexBuffer::AddIndexBuffer(Ref<IndexBuffer> buffer)
	{
		
		buffer->Bind();
	}

	void OpenGLVertexBuffer::AddLayout(std::initializer_list<Element> type)
	{
		uint32_t count = 0;
		uint32_t stride = 0, offset = 0;
		for (auto& element : type)
		{
			stride += GetSize(element.type);
		}

		for (auto& element : type)
		{

			glVertexAttribPointer(count, GetElementCount(element.type), GetOpenGLType(element.type), element.normalized, stride, (const void*)offset);
			glEnableVertexAttribArray(count++);
			offset += GetSize(element.type);
		}

	
	}

	void OpenGLVertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}


//-------------------------------------------------------------------------------------------------------------------------------------------//
	OpenGLVertexArray::OpenGLVertexArray(uint32_t size, void* data /*= nullptr*/)
	{
		glCreateVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::AddVertexBuffer(Ref<VertexBuffer> buffer)
	{

		buffer->Bind();
	}

	void OpenGLVertexArray::Bind()
	{
		glBindVertexArray(m_RendererID);
	}

}