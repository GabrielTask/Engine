#pragma once
#include "Base/Base.h"
#include "maths.h"

namespace Tigris
{
	class Texture
	{
	public:
		virtual ~Texture() = default;
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual uint32_t GetRendererID() const = 0;
		virtual void Resize(uint32_t width, uint32_t height)const = 0;;
		virtual void SetData(void* data, uint32_t size) = 0;
		virtual void Bind(uint32_t slot = 0) const = 0;
		virtual bool operator==(const Texture& other) const = 0;
		

	};

	class Texture2D : public Texture
	{
	public:
		static Ref<Texture2D> Create(uint32_t width, uint32_t height);
		static Ref<Texture2D> Create(const std::string& path);
		static Ref<Texture2D> Create(uint32_t width, uint32_t height,uint32_t ID);


	};


	class SubTexture2D
	{
	public:
		Ref<Texture2D> GetTexture()const { return m_Texture; }
		math::vec2* GetTextureCoords() { return m_TextureCoords; }
		SubTexture2D(Ref<Texture2D> texture,const math::vec2& min, const math::vec2 max):m_Texture(texture)
		{
			m_TextureCoords[0] = { max.x,max.y };
			m_TextureCoords[1] = { min.x,max.y };
			m_TextureCoords[2] = { min.x,min.y };
			m_TextureCoords[3] = { max.x,min.y };

		}
		static Ref<SubTexture2D> Create(Ref<Texture2D> texture, math::vec2& coords, const math::vec2& cellSize, const math::vec2& spriteSize = { 1.0f,1.0f })
		{
			return CreateRef<SubTexture2D>(texture,
				math::vec2(coords.x * cellSize.x / texture->GetWidth(), coords.y * cellSize.y / texture->GetHeight()),
				math::vec2((coords.x + spriteSize.x) * cellSize.x / texture->GetWidth(), (coords.y + spriteSize.y) * cellSize.y / texture->GetHeight()));
			//return CreateRef<SubTexure2D>(texture, { coords.x * cellSize.x, coords.y * cellSize.y }, {0.0f,0.0f});
		}
	private:
		Ref<Texture2D> m_Texture;
		math::vec2 m_TextureCoords[4];
	};

}