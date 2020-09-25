#pragma once
#include "TGpch.h"
#include "Renderer.h"
#include  <utility>
#include <array>


#include "Shader.h"
#include "Buffer.h"
#include "Platform/OpenGL/OpenGLShader.h"
#include <glad/glad.h>

namespace Tigris
{

	struct Vertex {
		math::vec2 Position;
		uint32_t Color;
		float TextureIndex;
		math::vec2 TextureCoords;


	};

	template<typename T>
	constexpr T ntohl(const T& input)
	{
		T result;
		uint8_t* data = (uint8_t*)&result;
		size_t size = sizeof(T) / sizeof(uint8_t);
		for (uint8_t i = 0; i < size; i++)
		{
			data[i] = input >> (size - i - 1) * 8;
		}
		return result;
	}

	namespace SquareVertices
	{
		struct {
			const math::vec2 c1 = { +0.5f, +0.5f };
			const math::vec2 c2 = { -0.5f, +0.5f };
			const math::vec2 c3 = { -0.5f, -0.5f };
			const math::vec2 c4 = { +0.5f, -0.5f };
		}str;
		constexpr const math::vec2& get(int index) { return *(&str.c1+index); }
	};

	struct RenderData
	{
		static const int MaxQuads = 1000;
		static const int MaxTextureNumber = 32;

		Vertex* r_Vertices = nullptr;
		Vertex* r_Target = nullptr;

		uint32_t r_TextureIndex = 1;
		uint32_t r_Index = 0;
		std::array<Texture*, MaxTextureNumber> r_Textures;


		Ref<VertexArray> r_VertaxArray;
		Ref<VertexBuffer> r_VertexBuffer;
		Ref<IndexBuffer> r_IndexBuffer;
	
		Ref<Shader> r_Shader;

		~RenderData()
		{
			for (auto texture : r_Textures)
			{
			//	delete[] texture;
			}
		}
		Ref<Texture2D> WhiteTexture;

	};
	RenderData Renderer2Ddata;


	struct RenderData2
	{
		Vertex* r_Vertices = nullptr;
		Vertex* r_Target = nullptr;
		Ref<VertexArray> r_VertaxArray;
		Ref<VertexBuffer> r_VertexBuffer;
	};
	RenderData2 Renderer2Ddata2;


	std::initializer_list<Element> layout = {
	{ElementType::Float2,0},
	{ElementType::Uchar4,1},
	{ElementType::Float1,0 },
	{ElementType::Float2,0 }
	};


	bool Renderer2D::Init()
	{
		RenderCommand::Init();
		memset(&Renderer2Ddata.r_Textures, 0, Renderer2Ddata.r_Textures.size());

		Renderer2Ddata.r_VertaxArray = VertexArray::Create();
		Renderer2Ddata.r_VertexBuffer = VertexBuffer::Create(4 * sizeof(Vertex) * Renderer2Ddata.MaxQuads);
		Renderer2Ddata.r_IndexBuffer = IndexBuffer::Create(6 * sizeof(uint32_t) * Renderer2Ddata.MaxQuads);

								Renderer2Ddata2.r_VertaxArray = VertexArray::Create();
								Renderer2Ddata2.r_VertexBuffer = VertexBuffer::Create(4 * sizeof(Vertex) * Renderer2Ddata.MaxQuads);

		Renderer2Ddata.r_Shader = Shader::Create("C:/users/GABRIEL/Desktop/Engine/Tigris/src/Base/Shader.glsl");
		Renderer2Ddata.r_Shader->Bind();

		Renderer2Ddata.r_Vertices = new Vertex[4 * Renderer2Ddata.MaxQuads];

								Renderer2Ddata2.r_Vertices = new Vertex[4 * Renderer2Ddata.MaxQuads];

		Renderer2Ddata.r_Target = Renderer2Ddata.r_Vertices;

								Renderer2Ddata2.r_Target = Renderer2Ddata2.r_Vertices;

		uint32_t* indices = new uint32_t[6 * Renderer2Ddata.MaxQuads];

		for (uint32_t offset = 0; offset < Renderer2Ddata.MaxQuads; offset++)
		{
			indices[6 * offset + 0] = 0 + 4 * offset;
			indices[6 * offset + 1] = 1 + 4 * offset;
			indices[6 * offset + 2] = 2 + 4 * offset;
			indices[6 * offset + 3] = 2 + 4 * offset;
			indices[6 * offset + 4] = 3 + 4 * offset;
			indices[6 * offset + 5] = 0 + 4 * offset;
		}

		Renderer2Ddata.r_VertaxArray->Bind();
		Renderer2Ddata.r_VertaxArray->AddVertexBuffer(Renderer2Ddata.r_VertexBuffer);
		Renderer2Ddata.r_VertexBuffer->AddLayout(layout);

		Renderer2Ddata.r_VertexBuffer->Bind();
		Renderer2Ddata.r_VertexBuffer->AddIndexBuffer(Renderer2Ddata.r_IndexBuffer);

		Renderer2Ddata.r_IndexBuffer->Bind();
		Renderer2Ddata.r_IndexBuffer->SetData(6 * Renderer2Ddata.MaxQuads * sizeof(uint32_t), indices);

		delete[] indices;
		 
		//--------------------------------------White Default Texture------------------------------------------------//
		Renderer2Ddata.WhiteTexture = Texture2D::Create(1,1);
		uint32_t white = 0xffffffff;
		Renderer2Ddata.WhiteTexture->SetData(&white, sizeof(uint32_t));
		Renderer2Ddata.r_Textures[0] = Renderer2Ddata.WhiteTexture.get();

		//-----------------------------------------------------------------------------------------------------------//

		int TexuresIndices[Renderer2Ddata.MaxTextureNumber + 1]; 
		for (int i = 0; i <= Renderer2Ddata.MaxTextureNumber ; i++)
		{
			TexuresIndices[i] = i;
		}

		((OpenGLShader*)Renderer2Ddata.r_Shader.get())->SetUniformIntArray("uTextures", TexuresIndices, Renderer2Ddata.MaxTextureNumber + 1);
		return true;
	}

	void Renderer2D::BeginBatch(Camera& camera)
	{
		((OpenGLShader*)Renderer2Ddata.r_Shader.get())->SetUniformMat4("u_ViewMatrix", &camera.GetViewProjection()[0][0]);
	}

	void Renderer2D::EndBatch()
	{
		flush();
	}

	


	uint32_t Renderer2D::CheckTexture(Ref<Texture> texture)
	{
		for (uint32_t i = 1; i < Renderer2Ddata.r_TextureIndex; i++)
			if (*Renderer2Ddata.r_Textures[i] == *texture)
				return i;
		
		if (Renderer2Ddata.r_TextureIndex == Renderer2Ddata.MaxTextureNumber)
			flush();

		Renderer2Ddata.r_Textures[Renderer2Ddata.r_TextureIndex] = texture.get();
		return Renderer2Ddata.r_TextureIndex++;
	}

	void Renderer2D::flush()
	{
		uint32_t NumberOfVertices = Renderer2Ddata.r_Index / 6 * 4;
		Renderer2Ddata.r_VertexBuffer->Bind();
		Renderer2Ddata.r_VertexBuffer->SetData(sizeof(Vertex) * NumberOfVertices, Renderer2Ddata.r_Vertices);

		for (uint32_t i = 0; i < Renderer2Ddata.r_TextureIndex; ++i)
		{
			Renderer2Ddata.r_Textures[i]->Bind(i);
		}
		RenderCommand::DrawIndexed(Renderer2Ddata.r_VertaxArray, Renderer2Ddata.r_Index);
		Renderer2Ddata.r_Target = Renderer2Ddata.r_Vertices;
		Renderer2Ddata.r_TextureIndex = 1;
		Renderer2Ddata.r_Index = 0;


		
		
								
	}


	void Renderer2D::DrawQuad(const math::vec2& position, const math::vec2& scale, uint32_t tintColor)
	{
		if (Renderer2Ddata.r_Index / 6 >= Renderer2Ddata.MaxQuads)
			flush();
		uint32_t Color = ntohl(tintColor);

		constexpr std::array<float, 8> textureCoords =
		{
			1.0f,1.0f,
			0.0f,1.0f,
			0.0f,0.0f,
			1.0f,0.0f
		};

		for (uint32_t i = 0; i < 4; i++)
		{
			Renderer2Ddata.r_Target->Position = math::vec2(SquareVertices::get(i).x * scale.x, SquareVertices::get(i).y * scale.y) + position;
			Renderer2Ddata.r_Target->Color = Color;
			Renderer2Ddata.r_Target->TextureIndex = 0.0f;
			Renderer2Ddata.r_Target->TextureCoords = { textureCoords[2 * i], textureCoords[2 * i + 1] };
			Renderer2Ddata.r_Target++;
		}
		Renderer2Ddata.r_Index += 6;
	}

	void Renderer2D::DrawQuad(const math::vec2& position, const math::vec2& scale, Ref<Texture> texture, uint32_t tintColor /*= 0xffffffff*/)
	{
		if (Renderer2Ddata.r_Index / 6 >= Renderer2Ddata.MaxQuads)
			flush();
		uint32_t Color = ntohl(tintColor);

		constexpr std::array<float, 8> textureCoords =
		{
			1.0f,1.0f,
			0.0f,1.0f,
			0.0f,0.0f,
			1.0f,0.0f
		};

		uint32_t texureIndex = CheckTexture(texture);



		for (uint32_t i = 0; i < 4; i++)
		{
			Renderer2Ddata.r_Target->Position = math::vec2(SquareVertices::get(i).x * scale.x, SquareVertices::get(i).y * scale.y) + position;
			Renderer2Ddata.r_Target->Color = Color;
			Renderer2Ddata.r_Target->TextureIndex = (float)texureIndex;
			Renderer2Ddata.r_Target->TextureCoords = { textureCoords[2 * i], textureCoords[2 * i + 1] };
			Renderer2Ddata.r_Target++;
		}
		Renderer2Ddata.r_Index += 6;
	}
	void Renderer2D::DrawQuad(const math::vec2& position, const math::vec2& scale, Ref<SubTexture2D> texture, uint32_t tintColor /*= 0xffffffff*/)
	{

		if (Renderer2Ddata.r_Index / 6 >= Renderer2Ddata.MaxQuads)
			flush();


		uint32_t Color = ntohl(tintColor);

		constexpr std::array<float, 8> textureCoords =
		{
			1.0f,1.0f,
			0.0f,1.0f,
			0.0f,0.0f,
			1.0f,0.0f
		};

		uint32_t texureIndex = CheckTexture(texture->GetTexture());


		for (uint32_t i = 0; i < 4; i++)
		{
			Renderer2Ddata.r_Target->Position = math::vec2(SquareVertices::get(i).x * scale.x, SquareVertices::get(i).y * scale.y) + position;
			Renderer2Ddata.r_Target->Color = Color;
			Renderer2Ddata.r_Target->TextureIndex = (float)texureIndex;
			Renderer2Ddata.r_Target->TextureCoords = texture->GetTextureCoords()[i];
			Renderer2Ddata.r_Target++;
		}
		Renderer2Ddata.r_Index += 6;
	}


	void Renderer2D::DrawRotated(const math::vec2& position, const math::vec2& scale, uint32_t tintColor, float angle)
	{
		if (Renderer2Ddata.r_Index / 6 >= Renderer2Ddata.MaxQuads)
			flush();

		uint32_t Color = ntohl(tintColor);
		math::Complex rotation(cos(angle), sin(angle));

		constexpr std::array<float, 8> textureCoords =
		{
			1.0f,1.0f,
			0.0f,1.0f,
			0.0f,0.0f,
			1.0f,0.0f
		};


		for (uint32_t i = 0; i < 4; i++)
		{
			
			math::Complex result = *((math::Complex*)&SquareVertices::get(i)) * rotation;
			Renderer2Ddata.r_Target->Position = math::vec2(result.R() * scale.x, result.I() * scale.y) + position;
			Renderer2Ddata.r_Target->Color = Color;
			Renderer2Ddata.r_Target->TextureIndex = 0.0f;
			Renderer2Ddata.r_Target->TextureCoords = { textureCoords[2 * i], textureCoords[2 * i + 1] };
			Renderer2Ddata.r_Target++;
		}
		Renderer2Ddata.r_Index += 6;
	}

	void Renderer2D::DrawRotated(const math::vec2& position, const math::vec2& scale, Ref<Texture> texture, float angle, uint32_t tintColor /*= 0xffffffff*/)
	{
		if (Renderer2Ddata.r_Index / 6 >= Renderer2Ddata.MaxQuads)
			flush();
		uint32_t Color = ntohl(tintColor);
		math::Complex rotation(cos(angle), sin(angle));
		constexpr std::array<float, 8> textureCoords =
		{
			1.0f,1.0f,
			0.0f,1.0f,
			0.0f,0.0f,
			1.0f,0.0f
		};

		uint32_t texureIndex = CheckTexture(texture);


		for (uint32_t i = 0; i < 4; i++)
		{
			math::Complex OriginalPosition(SquareVertices::get(i).x, SquareVertices::get(i).y);
			math::Complex result = OriginalPosition * rotation;
			Renderer2Ddata.r_Target->Position = math::vec2(result.R() * scale.x, result.I() * scale.y) + position;
			Renderer2Ddata.r_Target->Color = Color;
			Renderer2Ddata.r_Target->TextureIndex = (float)texureIndex;
			Renderer2Ddata.r_Target->TextureCoords = { textureCoords[2 * i], textureCoords[2 * i + 1] };
			Renderer2Ddata.r_Target++;
		}
		Renderer2Ddata.r_Index += 6;
	}

	void Renderer2D::DrawRotated(const math::vec2& position, const math::vec2& scale, Ref<SubTexture2D> texture, float angle, uint32_t tintColor /*= 0xffffffff*/)
	{
		if (Renderer2Ddata.r_Index / 6 >= Renderer2Ddata.MaxQuads)
			flush();
		uint32_t Color = ntohl(tintColor);
		math::Complex rotation(cos(angle), sin(angle));
		
	
		uint32_t texureIndex = CheckTexture(texture->GetTexture());



		for (uint32_t i = 0; i < 4; i++)
		{
			math::Complex result = *((math::Complex*) &SquareVertices::get(i)) * rotation;
			Renderer2Ddata.r_Target->Position = math::vec2(result.R() * scale.x, result.I() * scale.y) + position;
			Renderer2Ddata.r_Target->Color = Color;
			Renderer2Ddata.r_Target->TextureIndex = (float)texureIndex;
			Renderer2Ddata.r_Target->TextureCoords = texture->GetTextureCoords()[i];
			Renderer2Ddata.r_Target++;
		}
		Renderer2Ddata.r_Index += 6;
	}



}