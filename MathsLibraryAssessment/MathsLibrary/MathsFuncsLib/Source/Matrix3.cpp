#include "Matrix3.h"
#include "Matrix2.h"

// This is the default constructor for a blank matrix3.
// This ensures that a matrix3 always has default values.
Matrix3::Matrix3()
{
	v[0][0] = 1;
	v[0][1] = 0;
	v[0][2] = 0;
	v[1][0] = 0;
	v[1][1] = 1;
	v[1][2] = 0;
	v[2][0] = 0;
	v[2][1] = 0;
	v[2][2] = 1;

}



/*
This is a different Matrix3 constructor, it will create a default 2d array of type "real" with the parameters taken in.
*/
Matrix3::Matrix3(real x1, real x2, real x3, real y1, real y2, real y3, real z1, real z2, real z3)
{
	v[0][0] = x1;
	v[0][1] = x2;
	v[0][2] = x3;
	v[1][0] = y1;
	v[1][1] = y2;
	v[1][2] = y3;
	v[2][0] = z1;
	v[2][1] = z2;
	v[2][2] = z3;
}

//This is the Matrix3 destructor.
Matrix3::~Matrix3()
{

}

Matrix3::operator real*()
{
	return &v[0][0];
}


// This is the determinat function.
real Matrix3::determinant()
{
	real determinant;
	
	real a = v[0][0];
	real b = v[0][1];
	real c = v[0][2];

	real d = v[1][0];
	real e = v[1][1];
	real f = v[1][2];

	real g = v[2][0];
	real h = v[2][1];
	real i = v[2][2];

	//combining the variables
	real aei = a * i * e;
	real bfg = b * f * g;
	real cdh = c * d * h;
	real ceg = c * e * g;
	real bdi = b * d * i;
	real afh = a * f * h;

	determinant = aei + bfg + cdh - ceg - bdi - afh;
	//determinant = e * i - f * h - d * i - f * g + d * h - e * g ;

	return determinant;
}


// this is the inverse function for Matrix3's.
void Matrix3::inverse()
{
	Matrix3 tempMatrix;
	real tempFloat1;
	

	// Matrix of minors.
	real a = v[0][0];
	real b = v[0][1];
	real c = v[0][2];

	real d = v[1][0];
	real e = v[1][1];
	real f = v[1][2];

	real g = v[2][0];
	real h = v[2][1];
	real i = v[2][2];

		// Finding the determinant
	float theDeterminant;
	theDeterminant = determinant();
	
	
	v[0][0] = Matrix2{ e, f, h, i }.determinant(e, f, h, i);
	v[0][1] = Matrix2{ d,f,g,i }.determinant(d, f, g, i);
	v[0][2] = Matrix2{ d,g,e,h }.determinant(d, g, e, h);
	v[1][0] = Matrix2{ b,c,h,i }.determinant(b, c, h, i);
	v[1][1] = Matrix2{ a,c,g,i }.determinant(a, c, g, i);
	v[1][2] = Matrix2{ a,b,g,h }.determinant(a, b, g, h);
	v[2][0] = Matrix2{ b,c,e,f }.determinant(b, c, e, f);
	v[2][1] = Matrix2{ a,c,d,f }.determinant(a, c, d, f);
	v[2][2] = Matrix2{ a,b,d,e }.determinant(a, b, d, e);

	//determinant(v[0][0], v[0][1], v[0][2], v[1][0], v[1][1], v[1][2], v[2][0], v[2][1], v[2][2]);
	// turns the matrix of minors into a Matrix of cofactors.
	
	/*
	tempMatrix.v[0][1] *= -1;
	tempMatrix.v[1][0] *= -1;
	tempMatrix.v[1][2] *= -1;
	tempMatrix.v[2][1] *= -1;
	*/
	v[0][1] *= -1;
	v[1][0] *= -1;
	v[1][2] *= -1;
	v[2][1] *= -1;
	// time to adjugate (swap the diagonal elements.)

	
	tempFloat1 = v[1][0];
	v[1][0] = v[0][1];
	v[0][1] = tempFloat1;
	
	tempFloat1 = v[0][2];
	v[0][2] = v[2][0];
	v[2][0] = tempFloat1;

	tempFloat1 = v[1][2];
	v[1][2] = v[2][1];
	v[2][1] = tempFloat1;
	

	
	v[0][0] *= 1 / theDeterminant;
	v[0][1] *= 1 / theDeterminant;
	v[0][2] *= 1 / theDeterminant;
	v[1][0] *= 1 / theDeterminant;
	v[1][1] *= 1 / theDeterminant;
	v[1][2] *= 1 / theDeterminant;
	v[2][0] *= 1 / theDeterminant;
	v[2][1] *= 1 / theDeterminant;
	v[2][2] *= 1 / theDeterminant;

	/*
	tempMatrixtempFloat1 = tempMatrix[1][2];
	tempMatrix[1][2] = tempMatrix[2][1];
	tempMatrix[2][1] = tempFloat1;
	tempMatrix[0][1] *= 1 / theDeterminant;
	tempMatrix[0][2] *= 1 / theDeterminant;
	tempMatrix[1][0] *= 1 / theDeterminant;
	tempMatrix[1][1] *= 1 / theDeterminant;
	tempMatrix[1][2] *= 1 / theDeterminant;
	tempMatrix[2][0] *= 1 / theDeterminant;
	tempMatrix[2][1] *= 1 / theDeterminant;
	tempMatrix[2][2] *= 1 / theDeterminant;
	*/

	// setting the values to the current Matrix3
	/*
	v[0][0] = tempMatrix.v[0][0];
	v[0][1] = tempMatrix.v[0][1];
	v[0][2] = tempMatrix.v[0][2];
	v[1][0] = tempMatrix.v[1][0];
	v[1][1] = tempMatrix.v[1][1];
	v[1][2] = tempMatrix.v[1][2];
	v[2][0] = tempMatrix.v[2][0];
	v[2][1] = tempMatrix.v[2][1];
	v[2][2] = tempMatrix.v[2][2];
	/*
	Matrix3 tempMatrix;
	tempMatrix.v[0][0] = v[2][2];
	tempMatrix.v[2][2] = v[0][0];
	tempMatrix.v[0][1] = v[2][1];
	tempMatrix.v[1][0] = v[1][2];
	tempMatrix.v[1][1] = v[1][1];
	tempMatrix.v[1][2] = v[1][0];
	tempMatrix.v[2][1] = v[0][1];
	tempMatrix.v[0][2] = v[2][0];
	tempMatrix.v[2][0] = v[0][2];
	
	return tempMatrix;
	*/


	}

// This is a Matrix3 multiplied by a Matrix3 
Matrix3 Matrix3::operator*(Matrix3 &matrix1)
{
	Matrix3 tempMatrix;
	
	// loop though the matrix's and times each of the values together.
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tempMatrix.v[i][j] = { 
				v[0][j] * matrix1.v[i][0] +
				v[1][j] * matrix1.v[i][1] +
				v[2][j] * matrix1.v[i][2]
			};
		}
	}
	
	// return the multipled Matrix3.
	return tempMatrix;
}
// This is a Matrix3 multiplied by a Vector3 and returning the Vector3 
Vector3 Matrix3::operator*(Vector3 &vec)
{
	Vector3 tempVec;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tempVec[i] += vec[j] * v[j][i];
		}
	}


	return tempVec;
}
// This is a Matrix3 multiplied by a Vector2 and returning the Vector2 
Vector2 Matrix3::operator*(Vector2 & vec2)
{
	Vector3 tempVec;
	tempVec.x = vec2.x;
	tempVec.y = vec2.y;
	tempVec.z = 1;

	tempVec = *this * tempVec;

	return (Vector2) tempVec;
}

// This sets the rotation Matrix based on the radiant parameter on the x axis.
void Matrix3::setRotateX(real rad)
{
	v[0].x = 1;
	v[0].y = 0;
	v[0].z = 0;
	v[1].x = 0;
	v[1].y = cos(rad);
	v[1].z = sin(rad);
	v[2].x = 0;
	v[2].y = -sin(rad);
	v[2].z = cos(rad);
}

// This sets the rotation Matrix based on the radiant parameter on the y axis.
void Matrix3::setRotateY(real rad)
{
	v[0].x = cos(rad);
	v[0].y = 0;
	v[0].z = -sin(rad);
	v[1].x = 0;
	v[1].y = 1;
	v[1].z = 0;
	v[2].x = sin(rad);
	v[2].y = 0;
	v[2].z = cos(rad);
}

// This sets the rotation Matrix based on the radiant parameter on the z axis.
void Matrix3::setRotateZ(real rad)
{
	v[0].x = cos(rad);
	v[0].y = sin(rad);
	v[0].z = 0;
	v[1].x = -sin(rad);
	v[1].y = cos(rad);
	v[1].z = 0;
	v[2].x = 0;
	v[2].y = 0;
	v[2].z = 1;
}

// This returns the identity Matrix.
void Matrix3::identity()
{
	v[0][0] = 1;
	v[0][1] = 0;
	v[0][2] = 0;
	v[1][0] = 0;
	v[1][1] = 1;
	v[1][2] = 0;
	v[2][0] = 0;
	v[2][1] = 0;
	v[2][2] = 1;
}
