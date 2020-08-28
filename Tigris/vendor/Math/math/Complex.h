#pragma once

#include <ostream>

namespace math
{

	class Complex
	{
	public:
		Complex() = default;
		Complex(float _x, float _y);
		float x;
		float y;
	};



	Complex operator+(const Complex& one, const Complex& other);

	Complex operator-(const Complex& one, const Complex& other);

	Complex operator*(const Complex& one, const Complex& other);

	Complex operator/(const Complex& one, const Complex& other);

}
	std::ostream& operator<<(std::ostream& os, const math::Complex& number);

