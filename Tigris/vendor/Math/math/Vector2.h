#pragma once
#include "MathCore.h"

namespace math
{
	template<int Q, typename T>
	struct vec;


	template<typename T>
	struct vec<2, T>
	{
		//Data
		union {
			T data[2];
			struct { T x; T y;};
			struct { T r; T g;};
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
			this->y = static_cast<T>(scalar);

		}

		///Convertion
		template<typename U>
		vec(const vec<1, U>& v)
		{
			this->x = static_cast<T>(v.x);
			this->y = static_cast<T>(0);
		}
		template<typename U>
		vec(const vec<2, U>& v)
		{
			this->x = static_cast<T>(v.x);
			this->y = static_cast<T>(v.y);

		}

		template<typename X, typename Y>
		vec(X x, Y y) 
		{
			this->x = static_cast<T>(x);
			this->y = static_cast<T>(y);
		}

		//Return compoents
		T& operator[](uint32_t i) { return data[i]; }
		const T& operator[](uint32_t i)const { return data[i]; }

		//Other Vectors' function
		float length()const
		{
			return 	sqrt(
				static_cast<float>(this->x)* static_cast<float>(this->x) +
				static_cast<float>(this->y)* static_cast<float>(this->y) 
			);

		}

		void normalize()
		{
			auto span = length();
			if (span > 0)
			{
				this->x /= span;
				this->y /= span;
			}
		}

		// -- Unary arithmetic operators --
		template<typename U>
		vec<3, T>& operator=(const vec<1, U>& v)
		{
			this->x = static_cast<T>(v.x);
			this->y = static_cast<T>(0);
			this->z = static_cast<T>(0);
			return *this;
		}
		template<typename U>
		vec<3, T>& operator+=(const vec<1, U>& v)
		{
			this->x += static_cast<T>(v.x);
			return *this;
		}
		template<typename U>
		vec<3, T>& operator-=(const vec<1, U>& v)
		{
			this->x -= static_cast<T>(v.x);
			return *this;
		}



		template<typename U>
		vec<2, T>& operator=(const vec<2, U>& v)
		{
			this->x = static_cast<T>(v.x);
			this->y = static_cast<T>(v.y);
			return *this;
		}
		template<typename U>
		vec<2, T>& operator+=(const vec<2, U>& v)
		{
			this->x += static_cast<T>(v.x);
			this->y += static_cast<T>(v.y);
			return *this;
		}
		template<typename U>
		vec<2, T>& operator-=(const vec<2, U>& v)
		{
			this->x -= static_cast<T>(v.x);
			this->y -= static_cast<T>(v.y);
			return *this;
		}

		template<typename U>
		vec<2, T>& operator*=(U scalar)
		{
			this->x *= static_cast<T>(scalar);
			this->y *= static_cast<T>(scalar);
			return *this;
		}
		template<typename U>
		vec<2, T>& operator/=(U scalar)
		{
			this->x /= static_cast<T>(scalar);
			this->y /= static_cast<T>(scalar);
				return *this;
		}

		//Dot Product (member method)
		template<typename U>
		vec<2, T>& operator*=(vec<2, U>& other)
		{
			this->x *= static_cast<T>(other.x);
			this->y *= static_cast<T>(other.y);
			return *this;
		}

		// -- Increment and decrement operators --
		// -- Unary bit operators --


	};
	// Unary operators

		template<typename T, typename U>
		vec<2, T> operator + (const vec<2, T>& one, const vec<2, U>& other)
		{
			vec<2, T> Result = one;
			Result += other;
			return Result;
		}

		template<typename T, typename U>
		vec<2, T> operator - (const vec<2, T>& one, const vec<2, U>& other)
		{
			vec<2, T> Result = one;
			Result -= other;
			return Result;
		}


		template<typename T, typename U>
		vec<2, T> operator / (const vec<2, T>& one, U scalar)
		{
			vec<2, T> Result = one;
			Result /= scalar;
			return Result;
		}

		template<typename T, typename U>
		vec<2, T> operator * (const vec<2, T>& one, U scalar)
		{
			vec<2, T> Result = one;
			Result *= scalar;
			return Result;
		}

		template<typename T, typename U>
		vec<2, T> operator * (const vec<2, T>& one, const vec<2, U>& other)
		{
			vec<2, T> Result = one;
			Result *= other;
			return Result;
		}
	

}