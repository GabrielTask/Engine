#pragma once
#include "MathCore.h"

namespace math
{
	template<int Q, typename T>
	struct vec;


	template<typename T>
	struct vec<1, T>
	{
		//Data
		union {
			T data[1];
			struct { T x; };
			struct { T r; };
		};

		//Constructors


		///Default
		vec() = default;
		vec(const vec& v) = default;

		///Scalar
		template<typename U>
		vec(U scalar)
		{
			this->x = static_cast<T>(scalar);
		}

		///Convertion
		template<typename U>
		vec(const vec<1, U>& v)
		{
			this->x = static_cast<T>(v.x);
		}

	

		//Return compoents
		T& operator[](uint32_t i) { return data[i]; }
		const T& operator[](uint32_t i)const { return data[i]; }

		//Other Vectors' function
		float length()const{this->x}

		void normalize()
		{
			this->x = static_cast<T>(1);
		}

		// -- Unary arithmetic operators --
		template<typename U>
		vec<1, T>& operator=(const vec<1, U>& v)
		{
			this->x = static_cast<T>(v.x);
			return *this;
		}
		template<typename U>
		vec<1, T>& operator+=(const vec<1, U>& v)
		{
			this->x += static_cast<T>(v.x);
			return *this;
		}
		template<typename U>
		vec<1, T>& operator-=(const vec<1, U>& v)
		{
			this->x -= static_cast<T>(v.x);
			return *this;
		}

		template<typename U>
		vec<1, T>& operator*=(U scalar)
		{
			this->x *= static_cast<T>(scalar);
			return *this;
		}
		template<typename U>
		vec<1, T>& operator/=(U scalar)
		{
			this->x /= static_cast<T>(scalar);
			return *this;
		}
		template<typename U>
		vec<1, T> operator*=(const vec<1, U>& other)
		{

			this->x *= other.x;
			return *this;
		}


		// -- Increment and decrement operators --
		
		vec<1, T>& operator++()
		{
			this->x++;
			return *this;
		}
		vec<1, T>& operator--()
		{
			this->x--;
			return *this;
		}
		// -- Unary bit operators --


	};
	// Unary operators
	template <typename T,typename U>
	vec<1, T> operator+(const vec<1, T>& one, U value)
	{
		vec<1, T> result =one;
		result +=value;
		return result;
	}

	template <typename T, typename U>
	vec<1, T> operator-(const vec<1, T>& one, U value)
	{
		vec<1, T> result = one;
		result -= value;
		return result;
	}

	template <typename T, typename U>
	vec<1, T> operator*(const vec<1, T>& one,U value)
	{
		vec<1, T> result = one;
		result *= value;
		return result;
	}

	template <typename T, typename U>
	vec<1, T> operator*(const vec<1, T>& one, const vec<1, U>& other)
	{
		vec<1, T> result = one;
		result.x *= other.x;
		return result;
	}


	template <typename T, typename U>
	vec<1, T> operator/ (const vec<1, T>& one,U value)
	{
		vec<1, T> result = one;
		result /= value;
		return result;
	}

}