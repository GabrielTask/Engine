#pragma once
#include "Graphics/Texture.h"

namespace Tigris
{
	class OpenGLTexture2D : public Texture2D
	{

	public:
		OpenGLTexture2D(uint32_t width, uint32_t height);
		OpenGLTexture2D(const std::string& path);
		~OpenGLTexture2D();
		virtual uint32_t GetWidth() const override;


		virtual uint32_t GetHeight() const override;


		virtual uint32_t GetRendererID() const override;


		virtual void SetData(void* data, uint32_t size) override;


		virtual void Bind(uint32_t slot = 0) const override;


		virtual bool operator ==(const Texture& other) const override
		{
			return (GetRendererID() == other.GetRendererID());
		}
	private:
		uint32_t m_Width, m_Height;
		uint32_t m_RendererID;
		uint32_t m_InternalFormat;
		uint32_t m_DataFormat;

	};
}