#pragma once
#include "MathCore.h"

namespace math
{
	template<int Q, typename T>
	struct vec;


	template<typename T>
	struct vec<3,T>
	{
		//Data
		union {
			T data[3];
			struct { T x; T y; T z; };
			struct { T r; T g; T b; };
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
			this->z = static_cast<T>(scalar);
		}

		///Convertion
		template<typename U>
		vec(const vec<1, U>& v)
		{
			this->x = static_cast<T>(v.x);
			this->y = static_cast<T>(0);
			this->z = static_cast<T>(0);
		}
		template<typename U>
		vec(const vec<2, U>& v)
		{
			this->x = static_cast<T>(v.x);
			this->y = static_cast<T>(v.y);
		}

		template<typename X, typename Y, typename Z>
		vec(X x, Y y, Z z)
		{
			this->x = static_cast<T>(x);
			this->y = static_cast<T>(y);
			this->z = static_cast<T>(z);
		}

		//Return compoents
		T& operator[](uint32_t i) { return data[i]; }
		const T&  operator[](uint32_t i)const { return data[i]; }

		//Other Vectors' function
		float length()const
		{
			return 	sqrt(
				static_cast<float>(this->x)* static_cast<float>(this->x) +
				static_cast<float>(this->y)* static_cast<float>(this->y) +
				static_cast<float>(this->z)* static_cast<float>(this->z)
			);

		}

		void normalize()
		{
			auto span = length();
			if (!span)return;
			this->x /= span;
			this->y /= span;
			this->z /= span;
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
		vec<3,T>& operator=(const vec<2,U>& v)
		{
			this->x = static_cast<T>(v.x);
			this->y = static_cast<T>(v.y);
			this->z = static_cast<T>(0);
			return *this;
		}
		template<typename U>
		vec<3,T>& operator+=(const vec<2, U>& v)
		{
			this->x += static_cast<T>(v.x);
			this->y += static_cast<T>(v.y);
			return *this;
		}
		template<typename U>
		vec<3,T>& operator-=(const vec<2, U>& v)
		{
			this->x -= static_cast<T>(v.x);
			this->y -= static_cast<T>(v.y);
			return *this;
		}

		template<typename U>
		vec<3,T>& operator=(const vec<3, U>& v)
		{
			this->x = static_cast<T>(v.x);
			this->y = static_cast<T>(v.y);
			this->z = static_cast<T>(v.z);
			return *this;
		}
		template<typename U>
		vec<3,T>& operator+=(const vec<3, U>& v)
		{
			this->x += static_cast<T>(v.x);
			this->y += static_cast<T>(v.y);
			this->z += static_cast<T>(v.z);

			return *this;
		}
		template<typename U>
		vec<3,T>& operator-=(const vec<3, U>& v)
		{
			this->x -= static_cast<T>(v.x);
			this->y -= static_cast<T>(v.y);
			this->z -= static_cast<T>(v.z);

			return *this;
		}


		template<typename U>
		vec<3, T>& operator -= (U scalar)
		{
			this->x -= static_cast<T>(scalar);
			this->y -= static_cast<T>(scalar);
			this->z -= static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec<3,T>& operator*=(U scalar)
		{
			this->x *= static_cast<T>(scalar);
			this->y *= static_cast<T>(scalar);
			this->z *= static_cast<T>(scalar);
			return *this;
		}

		template<typename U>
		vec<3,T>& operator/=(U scalar)
		{
			this->x /= static_cast<T>(scalar);
			this->y /= static_cast<T>(scalar);
			this->z /= static_cast<T>(scalar);
			return *this;
		}

		//Dot Product (member method)
		template<typename U>
		vec<3, T>& operator*=(vec<3, U>& other)
		{
			this->x *= static_cast<T>(other.x);
			this->y *= static_cast<T>(other.y);
			this->z *= static_cast<T>(other.y);
			return *this;
		}



		// -- Increment and decrement operators --
		// -- Unary bit operators --


	};
		// Unary operators

	template<typename T, typename U>
	vec<3, T> operator + (const vec<3, T>& one, U scalar)
	{
		vec<3, T> Result = one;
		Result += scalar;
		return Result;
	}

	template<typename T, typename U>
	vec<3, T> operator - (const vec<3, T>& one, U scalar)
	{
		vec<3, T> Result = one;
		Result -= scalar;
		return Result;
	}

	template<typename T, typename U>
	vec<3, T> operator * (const vec<3, T>& one, U scalar)
	{
		vec<3, T> Result = one;
		Result *= scalar;
		return Result;
	}

	template<typename T, typename U> 
	vec<3, T> operator / (const vec<3, T>& one, U scalar)
	{
		vec<3, T> Result = one;
		Result /= scalar;
		return Result;
	}




	template <typename T, typename U>
	vec<3, T> operator*(vec<3, U>& one, vec<3, U>& other)
	{
		vec<3, T> result = one;
		result *= other;

		return result;
	}
}