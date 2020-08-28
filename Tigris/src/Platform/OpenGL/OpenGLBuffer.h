#pragma once
#include "Graphics/Buffer.h"

namespace Tigris
{
	class OpenGLIndexBuffer: public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t size, void* data = nullptr);
		void SetData(uint32_t size, const void* data) override;

		void Bind() override;

	private:
		uint32_t m_RendererID;
	};

	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(uint32_t size, void* data = nullptr);
		void SetData(uint32_t size, const void* data) override;


		void AddIndexBuffer(Ref<IndexBuffer> buffer) override;


		void AddLayout(std::initializer_list<Element> type) override;


		void Bind() override;

	private:
		uint32_t m_RendererID;

	};

	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray() = default;
		OpenGLVertexArray(uint32_t size, void* data = nullptr);
		virtual void AddVertexBuffer(Ref<VertexBuffer> buffer) override;
		virtual void Bind();

	private:
		uint32_t m_RendererID = -1;
	};
}