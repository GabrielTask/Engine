#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_access.hpp>

namespace math
{
	typedef glm::vec2 vec2;
	typedef glm::vec3 vec3;
	typedef glm::vec4 vec4;
	typedef glm::mat4 mat4;

	class Complex
	{
	public:
		Complex(float a, float b) :m_A(a), m_B(b)
		{
		}

		float R()const { return m_A; }
		float I()const { return m_B; }

		Complex operator*(const Complex& other)const
		{
			return Complex(this->R() * other.R() - this->I() * other.I(), this->I() * other.R() + this->R() * other.I());
		}

		Complex& operator*=(const Complex& other)
		{
			*this = Complex(this->R() * other.R() - this->I() * other.I(), this->I() * other.R() + this->R() * other.I());
			return *this;
		}

		Complex operator/(const Complex& other)const
		{
			Complex(this->R() * other.R() + this->I() * other.I(), this->I() * other.R() - this->R() * other.I());
		}

	private:
		float m_A, m_B;
	};
}
	
//	typedef glm::mat4 mat4;

