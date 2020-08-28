#include "NBpch.h"
/*//TODO this should be in a differente project
//end TODO;

#include "Matrix.h"
#include "Vector.h"
namespace math
{
	Matrix<float, 4, 4> ortho(float left, float right, float bottom, float top, float zNear, float zFar)
	{
		Matrix<float, 4, 4> Result;
		Result[0][0] = 2.0f / (right - left);
		Result[1][1] = 2.0f / (top - bottom);
		Result[2][2] = 1.0f / (zFar - zNear);
		Result[3][0] = -(right + left) / (right - left);
		Result[3][1] = -(top + bottom) / (top - bottom);
		Result[3][2] = -zNear / (zFar - zNear);
		return Result;
	}
	Matrix<float, 4, 4> translate(const Matrix<float, 4, 4>& mat, const vec3& vec)
	{
		Matrix<float, 4, 4> matr = mat;
		*(matr.Get() + 12) +=vec.x;
		*(matr.Get() + 13) +=vec.y;
		*(matr.Get() + 14) +=vec.z;

		return matr;
	}

	Matrix<float, 4, 4> scale(const Matrix<float, 4, 4>& mat, const vec3& vec)
	{
		Matrix<float, 4, 4> matr;
		for (int i=0; i<mat.getColumns();i++)
			for(int j = 0; j<mat.getLines()-1;j++)
				{
				int index = mat.getColumns() * i + j;
				*(matr.Get() + index) = *(mat.get() + index)*vec.data[j];
				}
		
		return matr;
	}

	Matrix<float, 4, 4> rotate(const Matrix<float, 4, 4>& mat, const vec3& vec)
	{
		Matrix<float, 4, 4> matr;
		for (int i = 0; i < 16; i++)*(matr.Get() + i) = *(mat.get() + i);
	

		*(matr.Get()) *=  cos(vec.z);

		if (* (matr.Get()+1))
		*(matr.Get() +1) *=  sin(vec.z);
		else *(matr.Get() + 1) = sin(vec.z);
	
		*(matr.Get()+4) *= -sin( vec.z); 
		if (*(matr.Get() + 4 + 1))
		*(matr.Get() + 4 + 1) *= cos(vec.z);
		else *(matr.Get() + 4 + 1) = cos(vec.z);


		//*(matr.Get()+8) *= cos(1.5708f + vec.y);
		//*(matr.Get() + 2+8) *= sin(1.5708f + vec.y);
		//
		//*(matr.Get()  ) *= cos(vec.y);
		//*(matr.Get() + 2) *= sin(vec.y);
		//
		//*(matr.Get() + 8) *= cos(1.5708f + vec.y);
		//*(matr.Get() + 2 + 8) *= sin(1.5708f + vec.y);
		//
		//*(matr.Get()+3) *= cos(vec.x);
		//*(matr.Get() + 2+4) *= sin(vec.x);
		//
		//*(matr.Get() + 8) *= cos(1.5708f + vec.x);
		//*(matr.Get() + 2 + 8) *= sin(1.5708f + vec.x);

		return matr;
	}

}
*/
