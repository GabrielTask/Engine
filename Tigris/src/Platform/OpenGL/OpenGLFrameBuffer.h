#pragma once
#include "Graphics/FrameBuffer.h"

namespace Tigris
{
	class OpenGLFrameBuffer: public FrameBuffer
	{
	public:
		OpenGLFrameBuffer(const FrameBufferSpecification& spec);
		virtual ~OpenGLFrameBuffer();

		void Resize();

		virtual void Bind() override;

		virtual void UnBind() override;

		virtual uint32_t GetColorAttachmentRendererID()const { return m_ColorAttachment; }

		const FrameBufferSpecification& GetSpecification() const override;


		void Resize(uint32_t width, uint32_t height) override;

	private:
		uint32_t m_RendererID;
		uint32_t m_ColorAttachment, m_DepthAttachment;
		FrameBufferSpecification m_Specification;
	};

}