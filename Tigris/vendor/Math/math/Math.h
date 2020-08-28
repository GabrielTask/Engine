#pragma once

#include <stdint.h>
#include "Utils.h"
#include "Vector.h"
#include "Matrix.h"
#include "Complex.h"

namespace math
{
#define PI 3.1415f
#define TAU 2*PI;


	template<typename T, int Q>
	vec<Q, T> constrain(const vec<Q, T>& one,float min, float max)
	{
		vec<Q, T> result = one;
		float length = one.length();
		if (length<=max && length>=min)
			return result;

		result.normalize();
		std::cout << result.length();
		if (length < min)
			result *= min;
		else result *= max;

		
		return result;
	}

	template<typename T>
	T constrain(T one, T min, T max)
	{

		if (one <= max && one >= min)
			return one;
		if (one < min)
			return min;
		return max;
	}


	template<typename T>
	T limit(T c, T min, T max)
	{
		if (c <= min)return min;
		if (c >= max)return max;
	}

	template<typename T >
	T lerp(T origin, T destination, float rate)
	{
		return (destination - origin) * rate;
	}

	template<typename T,typename U, int Q>
	float dist(const vec<Q, T>& one, const vec<Q, U>& other)
	{
		float result = 0.0f;
		for (int i = 0; i < Q; i++)
		{
			result += pow(other[i] - one[i], 2);
		}
		return sqrt(result);
	}

	template<typename T, typename U, int Q>
	float distS(const vec<Q, T>& one, const vec<Q, U>& other)
	{
		float result = 0.0f;
		for (int i = 0; i < Q; i++)
		{
			result += pow(other[i] - one[i], 2);
		}
		return result;
	}
}

