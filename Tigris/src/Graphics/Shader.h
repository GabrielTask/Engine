#pragma once
#include "Base/Base.h"

namespace Tigris
{
	class Shader
	{
	public:

		virtual void Bind() = 0;

	public:
		static Ref<Shader> Create(const char* vsSrc, const char* fsSrc);
		Ref<Shader> Shader::Create(const char* Vpath, const char* Fpath, const char* path);
		static Ref<Shader> Create(const char* path);
	};
}
