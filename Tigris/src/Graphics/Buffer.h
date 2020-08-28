#pragma once
#include "Base/Base.h"

namespace Tigris
{

	enum class ElementType
	{
		Float1,
		Float2,
		Float3,
		Float4,

		Int1,
		Int2,
		Int3,
		Int4,

		Uint1,
		Uint2,
		Uint3,
		Uint4,


		Shrt1,
		Shrt2,
		Shrt3,
		Shrt4,

		Ushrt1,
		Ushrt2,
		Ushrt3,
		Ushrt4,

		Char1,
		Char2,
		Char3,
		Char4,

		Uchar1,
		Uchar2,
		Uchar3,
		Uchar4,


	
	};




	struct Element
	{
		ElementType type;
		bool normalized;
	};

	uint32_t GetElementCount(ElementType type);

	uint32_t GetSize(ElementType type);

	uint32_t GetOpenGLType(ElementType type);

	class IndexBuffer
	{
	public:
		static Ref<IndexBuffer> Create(uint32_t size, void* data = nullptr);
		virtual void SetData(uint32_t size, const void* data) = 0;
		virtual void Bind() = 0;
	};

	class VertexBuffer
	{
	public:
		static Ref<VertexBuffer> Create(uint32_t size, void* data = nullptr);
		virtual void SetData(uint32_t size, const void* data) = 0;
		virtual void AddIndexBuffer(Ref<IndexBuffer> buffer) = 0;
		virtual void AddLayout(std::initializer_list<Element> type) = 0;
		virtual void Bind() = 0;
	};

	class VertexArray
	{
	public:
		static Ref<VertexArray> Create();
		virtual void AddVertexBuffer(Ref<VertexBuffer> buffer) = 0;
		virtual void Bind() = 0;
	};
}