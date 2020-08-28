#pragma once
#include "Graphics/Shader.h"
#include <unordered_map>
#include <string.h>

namespace Tigris
{

	class OpenGLShader :public Shader
	{
	public:
		OpenGLShader(const char* vsSrc, const char* fsSrc);
		OpenGLShader(const char* path);
		OpenGLShader(const char* Vpath, const char* Fpath, const char* path);
		
		void Bind() override;

		void SetUniformMat4(std::string name, const float* data);
		void SetUniformInt(std::string name, uint32_t value);
		void SetUniformIntArray(std::string name, int* value, uint32_t count);
		
	private:
		void Compile(const char* vsSrc, const char* fsSrc);
		int32_t GetUniformLocation(const std::string& name);
	private:
		uint32_t m_RendererID;
		std::unordered_map<std::string, int32_t> m_Uniforms;

	};
}