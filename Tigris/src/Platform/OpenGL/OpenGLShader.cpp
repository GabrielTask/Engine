#include "TGpch.h"
#include "OpenGLShader.h"
#include "glad/glad.h"
#include <sstream>
#include <fstream>

namespace Tigris
{

	OpenGLShader::OpenGLShader(const char* vsSrc, const char* fsSrc)
	{
		Compile(vsSrc, fsSrc);
	}

	OpenGLShader::OpenGLShader(const char* path)
	{
		enum class ShaderType
		{
			NONE = -1, VERTEXSHADER, FRAGMENTSHADER
		};

		std::ifstream file(path);
		std::string line;
		std::stringstream ss[2];
		ShaderType type = ShaderType::NONE;
		while (getline(file, line))
		{
			if (line.find("#Vertex") != std::string::npos)
				type = ShaderType::VERTEXSHADER;
			else if (line.find("#Fragment") != std::string::npos)
				type = ShaderType::FRAGMENTSHADER;
			else
				ss[(int)type] << line << "\n";


		}

		m_RendererID = glCreateProgram();
		std::string vertexShader = ss[0].str();
		std::string pixelShader = ss[1].str();
		Compile(vertexShader.c_str(), pixelShader.c_str());
	}

	OpenGLShader::OpenGLShader(const char* Vpath, const char* Fpath, const char* path):m_RendererID(-1)
	{

	}

	void OpenGLShader::Bind()
	{
		glUseProgram(m_RendererID);
	}

	void OpenGLShader::SetUniformMat4(std::string name, const float* data)
	{
		glUniformMatrix4fv(GetUniformLocation(name), 1, 0, data);
	}

	void OpenGLShader::SetUniformInt(std::string name, uint32_t value)
	{
		glUniform1i(GetUniformLocation(name), value);
	}

	void OpenGLShader::SetUniformIntArray(std::string name, int* value, uint32_t count)
	{
		glUniform1iv(GetUniformLocation(name), count, value);
	}

	void OpenGLShader::Compile(const char* vsSrc, const char* fsSrc)
	{

		std::cout << vsSrc << fsSrc << "\n";
		uint32_t vs, fs;
		m_RendererID = glCreateProgram();
		vs = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vs, 1, &vsSrc, NULL);
		glCompileShader(vs);

		fs = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fs, 1, &fsSrc, NULL);
		glCompileShader(fs);

		glAttachShader(m_RendererID, vs);
		glAttachShader(m_RendererID, fs);
		glLinkProgram(m_RendererID);
		glUseProgram(m_RendererID);

		{
			int  success;
			char infoLog[512];
			glGetShaderiv(vs, GL_COMPILE_STATUS, &success);

			if (!success)
			{
				glGetShaderInfoLog(vs, 512, NULL, infoLog);
				std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
			}

		}

		{
			int  success;
			char infoLog[512];
			glGetShaderiv(fs, GL_COMPILE_STATUS, &success);

			if (!success)
			{
				glGetShaderInfoLog(fs, 512, NULL, infoLog);
				std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
			}
		}
		glUseProgram(0);
	}

	int32_t OpenGLShader::GetUniformLocation(const std::string& name)
	{
		if (m_Uniforms.find(name) != m_Uniforms.end())
			return m_Uniforms[name];
		m_Uniforms[name] = glGetUniformLocation(m_RendererID, name.c_str());
		return m_Uniforms[name];
	}

}

