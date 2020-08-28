#include "NBpch.h"
#include "Complex.h"

math::Complex::Complex(float _x, float _y) :x(_x), y(_y)
{

}

math::Complex math::operator+(const Complex& one, const Complex& other)
{
	return Complex(one.x + other.x, one.y + other.y);
}

math::Complex math::operator-(const Complex& one, const Complex& other)
{
	return Complex(one.x - other.x, one.y - other.y);
}

math::Complex math::operator*(const Complex& one, const Complex& other)
{
	return Complex(one.x * other.x - one.y * other.y, one.y * other.x + one.x * other.y);
}

math::Complex math::operator/(const Complex& one, const Complex& other)
{
	return Complex(one.x * other.x + one.y * other.y, one.y * other.x - one.x * other.y);
}

std::ostream& operator<<(std::ostream& os, const math::Complex& number)
{
	return os << "(" << number.x << " + " << number.y << "i)";
}
