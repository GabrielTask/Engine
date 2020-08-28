#pragma once
#include "MathCore.h"

namespace math
{
	template<int Q, typename T>
	struct vec;


	template<typename T>
	struct vec<4, T>
	{
		//Data
		union {
			T data[4];
			struct { T x; T y; T z; T w; };
			struct { T r; T g; T b; T a; };
		};

		//Constructors

		///Default
		vec() = default;
		vec(const vec& v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			this->w = v.w;
		}

		///Scalar
		template<typename U>
		vec(U scalar)
		{
			this->x = static_cast<T>(scalar);
			this->y = static_cast<T>(scalar);
			this->z = static_cast<T>(scalar);
			this->w = static_cast<T>(scalar);
		}

		///Convertion
		template<typename U>
		vec(const vec<1, U>& v)
		{
			this->x = static_cast<T>(v.x);
			this->y = static_cast<T>(0);
			this->z = static_cast<T>(0);
			this->w = static_cast<T>(0);
		}
		template<typename U>
		vec(const vec<2, U>& v)
		{
			this->x = static_cast<T>(v.x);
			this->y = static_cast<T>(v.y);
			this->z = static_cast<T>(0);
			this->w = static_cast<T>(0);
		}

		template<typename X, typename Y, typename Z, typename W>
		vec(X x, Y y, Z z, W w)
		{
			this->x = static_cast<T>(x);
			this->y = static_cast<T>(y);
			this->z = static_cast<T>(z);
			this->w = static_cast<T>(w);
		}

		//Return compoents
		T& operator[](uint32_t i) { return data[i]; }
		const T& operator[](uint32_t i)const { return data[i]; }

		//Other Vectors' function
		float length()const
		{
			return 	sqrt(
				static_cast<float>(this->x)* static_cast<float>(this->x) +
				static_cast<float>(this->y)* static_cast<float>(this->y) +
				static_cast<float>(this->z)* static_cast<float>(this->z) +
				static_cast<float>(this->w)* static_cast<float>(this->w) +
			);

		}

		void normalize()
		{
			auto span = length();
			this->x /= span;
			this->y /= span;
			this->z /= span;
			this->w /= span;
		}

		// -- Unary arithmetic operators --
		template<typename U>
		vec<4, T>& operator=(const vec<1, U>& v)
		{
			this->x = static_cast<T>(v.x);
			this->y = static_cast<T>(0);
			this->z = static_cast<T>(0);
			return *this;
		}
		template<typename U>
		vec<4, T>& operator+=(const vec<1, U>& v)
		{
			this->x += static_cast<T>(v.x);
			return *this;
		}
		template<typename U>
		vec<4, T>& operator-=(const vec<1, U>& v)
		{
			this->x -= static_cast<T>(v.x);
			return *this;
		}



		template<typename U>
		vec<4, T>& operator=(const vec<2, U>& v)
		{
			this->x = static_cast<T>(v.x);
			this->y = static_cast<T>(v.y);
			return *this;
		}
		template<typename U>
		vec<4, T>& operator+=(const vec<2, U>& v)
		{
			this->x += static_cast<T>(v.x);
			this->y += static_cast<T>(v.y);
			return *this;
		}
		template<typename U>
		vec<4, T>& operator-=(const vec<2, U>& v)
		{
			this->x -= static_cast<T>(v.x);
			this->y -= static_cast<T>(v.y);
			return *this;
		}

		template<typename U>
		vec<4, T>& operator=(const vec<3, U>& v)
		{
			this->x = static_cast<T>(v.x);
			this->y = static_cast<T>(v.y);
			this->z = static_cast<T>(v.z);
			this->w = static_cast<T>(0);
			return *this;
		}
		template<typename U>
		vec<4, T>& operator+=(const vec<3, U>& v)
		{
			this->x += static_cast<T>(v.x);
			this->y += static_cast<T>(v.y);
			this->z += static_cast<T>(v.z);
			return *this;
		}
		template<typename U>
		vec<4, T>& operator-=(const vec<3, U>& v)
		{
			this->x -= static_cast<T>(v.x);
			this->y -= static_cast<T>(v.y);
			this->z -= static_cast<T>(v.z);
			return *this;
		}

		template<typename U>
		vec<4, T>& operator=(const vec<4, U>& v)
		{
			this->x = static_cast<T>(v.x);
			this->y = static_cast<T>(v.y);
			this->z = static_cast<T>(v.z);
			this->w = static_cast<T>(v.w);
			return *this;
		}
		template<typename U>
		vec<4, T>& operator+=(const vec<4, U>& v)
		{
			this->x += static_cast<T>(v.x);
			this->y += static_cast<T>(v.y);
			this->z += static_cast<T>(v.z);
			this->w += static_cast<T>(v.w);

			return *this;
		}
		template<typename U>
		vec<4, T>& operator-=(const vec<4, U>& v)
		{
			this->x -= static_cast<T>(v.x);
			this->y -= static_cast<T>(v.y);
			this->z -= static_cast<T>(v.z);
			this->w -= static_cast<T>(v.w);

			return *this;
		}

		template<typename U>
		vec<4, T>& operator*=(U scalar)
		{
			this->x *= static_cast<T>(scalar);
			this->y *= static_cast<T>(scalar);
			this->z *= static_cast<T>(scalar);
			this->w *= static_cast<T>(scalar);
			return *this;
		}
		template<typename U>
		vec<4, T>& operator/=(U scalar)
		{
			this->x /= static_cast<T>(scalar);
			this->y /= static_cast<T>(scalar);
			this->z /= static_cast<T>(scalar);
			this->w /= static_cast<T>(scalar);
			return *this;
		}

		template <typename U>
		vec<4, T>& operator*=(const vec<4, U>& other)
		{
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
			this->w *= other.w;

			return *this;
		}
	

		// -- Increment and decrement operators --
		// -- Unary bit operators --


	};
	// Unary operators
	template<typename T, typename U>
	vec<4, T> operator + (const vec<4, T>& one, U scalar)
	{
		vec<4, T> Result = one;
		Result += scalar;
		return Result;
	}

	template<typename T, typename U>
	vec<4, T> operator - (const vec<4, T>& one, U scalar)
	{
		vec<4, T> Result = one;
		Result -= scalar;
		return Result;
	}

	template<typename T, typename U>
	vec<4, T> operator * (const vec<4, T>& one, U scalar)
	{
		vec<4, T> Result = one;
		Result *= scalar;
		return Result;
	}

	template<typename T, typename U>
	vec<4, T> operator / (const vec<4, T>& one, U scalar)
	{
		vec<4, T> Result = one;
		Result /= scalar;
		return Result;
	}

	template <typename T, typename U>
	vec<4, T> operator*(vec<4, U>& one, vec<4, U>& other)
	{
		vec<4, T> result = one;
		result *= other;

		return result;
	}


}