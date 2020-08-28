#pragma once
#include "MathCore.h"
#include "Vector.h"

namespace math
{


	template<typename T, int columns, int lines>
	class Matrix;
 

	template<typename T>
	class Matrix<T, 4, 4>
	{
	private:
		vec<4, T> m_Data[4];

	public:

		//Constructors

		Matrix()
		{
			m_Data[0][0] = static_cast<T>(0);
			m_Data[0][1] = static_cast<T>(0);
			m_Data[0][2] = static_cast<T>(0);
			m_Data[0][3] = static_cast<T>(0);
			m_Data[0][4] = static_cast<T>(0);
			m_Data[0][5] = static_cast<T>(0);
			m_Data[0][6] = static_cast<T>(0);
			m_Data[0][7] = static_cast<T>(0);
			m_Data[0][8] = static_cast<T>(0);
			m_Data[0][9] = static_cast<T>(0);
			m_Data[0][10] = static_cast<T>(0);
			m_Data[0][11] = static_cast<T>(0);
			m_Data[0][12] = static_cast<T>(0);
			m_Data[0][13] = static_cast<T>(0);
			m_Data[0][14] = static_cast<T>(0);
			m_Data[0][15] = static_cast<T>(0);
		}

		vec<4, T>& operator[](uint32_t index) { return m_Data[index]; }
		const vec<4, T>& operator[](uint32_t index)const { return m_Data[index]; }

		template <typename U>
		Matrix(U scalar) :Matrix()
		{
			m_Data[0][0] = static_cast<T>(scalar);
			m_Data[1][1] = static_cast<T>(scalar);
			m_Data[2][2] = static_cast<T>(scalar);
			m_Data[3][3] = static_cast<T>(scalar);
		}

		//void translate

		const vec<4, T>& getX()const { return m_Data[0]; }
		const vec<4, T>& getY()const { return m_Data[1]; }
		const vec<4, T>& getZ()const { return m_Data[2]; }
		const vec<4, T>& getW()const { return m_Data[3]; }

		vec<4, T>& getX() { return m_Data[0]; }
		vec<4, T>& getY() { return m_Data[1]; }
		vec<4, T>& getZ() { return m_Data[2]; }
		vec<4, T>& getW() { return m_Data[3]; }

		operator T* () { return &m_Data[0][0]; }

		bool operator==(Matrix<T,4,4>& other)
		{
			for (int i = 0; i < 16; i++)
				if (getX()[i] != other.getX()[i])return false;
			return true;
		}
	};

	template<typename T>
	Matrix<T, 4, 4> ortho(T left, T right, T bottom, T top, T zNear, T zFar)
	{
		Matrix<T, 4, 4> Result(static_cast<T>(1));
		Result[0][0] = static_cast<T>(2) / (right - left);
		Result[1][1] = static_cast<T>(2) / (top - bottom);
		Result[2][2] = static_cast<T>(1) / (zFar - zNear);
		Result[3][0] = -(right + left) / (right - left);
		Result[3][1] = -(top + bottom) / (top - bottom);
		Result[3][2] = -zFar  / (zFar - zNear);
		return Result;

	}

	//Update Ortho Matrix
	template<typename T>
	void ortho(Matrix<T, 4, 4>& mat, T left, T right, T bottom, T top)
	{
		mat[0][0] = static_cast<T>(4) / (right - left);
		mat[1][1] = static_cast<T>(4) / (top - bottom);
		mat[3][0] = -(right + left) / (right - left);
		mat[3][1] = -(top + bottom) / (top - bottom);
	}

	template<typename T>
	Matrix<T,4, 4> rotate(Matrix<T, 4, 4> & m, T angle, vec<3, T> const& v)
	{
		T const a = angle;
		T const c = cos(a);
		T const s = sin(a);
	
		vec<3, T> axis(v);
		axis.normalize();
		vec<3, T> temp( axis* (T(1) - c));

		Matrix<T, 4, 4> Rotate;
		Rotate[0][0] = c + temp[0] * axis[0];
		Rotate[0][1] = temp[0] * axis[1] + s * axis[2];
		Rotate[0][2] = temp[0] * axis[2] - s * axis[1];

		Rotate[1][0] = temp[1] * axis[0] - s * axis[2];
		Rotate[1][1] = c + temp[1] * axis[1];
		Rotate[1][2] = temp[1] * axis[2] + s * axis[0];

		Rotate[2][0] = temp[2] * axis[0] + s * axis[1];
		Rotate[2][1] = temp[2] * axis[1] - s * axis[0];
		Rotate[2][2] = c + temp[2] * axis[2];

		Matrix<T, 4, 4> Result;
		Result[0] = m[0] * Rotate[0][0] + m[1] * Rotate[0][1] + m[2] * Rotate[0][2];
		Result[1] = m[0] * Rotate[1][0] + m[1] * Rotate[1][1] + m[2] * Rotate[1][2];
		Result[2] = m[0] * Rotate[2][0] + m[1] * Rotate[2][1] + m[2] * Rotate[2][2];
		Result[3] = m[3];
		return Result;
	}

//template<typename T>
//struct Vector3
//{
//
//	union { T data[3]; struct { T x; T y; T z; }; struct { T r; T g; T b; }; };
//	//void operator = (const Vector3<T>& another) { memcpy(&data[0], &another.data[0], sizeof(data)); }
//	Vector3<T> operator = (Vector3<T>& other, const Vector3<T>& another);
//};


	//vec3 operator + (const vec3& other,const vec3& another)
	//{ 
	//	vec3 result;
	//	for (int i = 0; i < 3; i++)
	//		result.data[i] = other.data[i] + other.data[i];
	//	return result;
	//}
	//
	//vec3 vec3::operator = (vec3& other, const vec3& another)
	//{
	//	other = other + another;
	//	return other;
	//}
	template<typename T>
	Matrix<T, 4, 4> translate(const Matrix<T, 4, 4>& mat, const vec3& vec)
	{
		Matrix<T, 4, 4> matr = mat;
		matr.getW() += mat[0] * vec[0] + mat[1] * vec[1] + mat[2] * vec[2] ;
		return matr;
	}
	//Matrix<float, 4, 4> NB_API scale(const Matrix<float, 4, 4>& mat, const vec3& vec);
	//Matrix<float, 4, 4> NB_API rotate(const Matrix<float, 4, 4>& mat, const vec3& vec);


}

