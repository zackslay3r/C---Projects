#include "Matrix2.h"

/*
This is the default constructor for a Matrix2. 
this should return a blank Matrix2 with the identity matrix.
*/
Matrix2::Matrix2()
{
	v[0][0] = 1;
	v[0][1] = 0;
	v[1][0] = 0;
	v[1][1] = 1;

}
/*
This is a different Matrix2 constructor, it will create a default 2d array of type "real" with the parameters taken in.
*/
Matrix2::Matrix2(real x1, real x2, real y1, real y2)
{
	v[0][0] = x1;
	v[0][1] = x2;
	v[1][0] = y1;
	v[1][1] = y2;
}

//This is the Matrix2 destructor.
Matrix2::~Matrix2()
{

}

Matrix2::operator real*()
{
	return &v[0][0];
}
// This is a Matrix2 multiplied by a Matrix2 
Matrix2 Matrix2::operator*(Matrix2 &matrix1)
{
	Matrix2 tempMatrix;

	// loop though the matrix's and times each of the values together.
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			tempMatrix.v[i][j] = {
				v[0][j] * matrix1.v[i][0] +
				v[1][j] * matrix1.v[i][1]
			};
		}
	}
	// return the multipled Matrix2.
	return tempMatrix;
}
// This is a Matrix2 multiplied by a Vector2 and returning the Vector2 
Vector2 Matrix2::operator*(Vector2 &vec)
{
	// this is the tempVec which will be set in the loop
	Vector2 tempVec;
	// this loop sets tempVec[i] equal to itself plus the original vector[j] * Matrix2[j][i]
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			tempVec[i] += vec[j] * v[j][i];
		}
	}

	// return the Vector2.
	return tempVec;
}

// This sets the rotation Matrix based on the radiant parameter.
void Matrix2::setRotate(real rad)
{
	v[0].x = cos(rad);
	v[0].y = sin(rad);
	v[1].x = -sin(rad);
	v[1].y = cos(rad);
}
// This returns the identity Matrix.
void Matrix2::identity()
{
	v[0][0] = 1;
	v[0][1] = 0;
	v[1][0] = 0;
	v[1][1] = 1;
}
// This is the determinat function.
real Matrix2::determinant(real x1, real x2, real y1, real y2)
{
	// create new temp variables.
	real determinat;
	Matrix2 tempMatrix;
	// set the temporary Matrix2 equal to the values of the original Matrix2.
	tempMatrix.v[0][0] = x1;
	tempMatrix.v[0][1] = x2;
	tempMatrix.v[1][0] = y1;
	tempMatrix.v[1][1] = y2;
	// multiply diagonals.
	determinat = x1 * y2 - x2 * y1;
	//return the determinat.
	return determinat;
}

// this is the inverse function for Matrix2's.
void Matrix2::inverse()
{
	// Make the matrix2 of cofactors.
	v[0][1] *= -1;
	v[1][0] *= -1;

	//swaps the diagonals.
	real pos1 = v[0][0];
	real pos2 = v[1][1];
	
	v[1][1] = pos1;
	v[0][0] = pos2;


	//find the determinat and divide each position by it.
	real deter = Matrix2::determinant(v[0][0], v[1][1], v[1][0], v[0][1]);

	v[0][0] *= 1 / deter;
	v[0][1] *= 1 / deter;
	v[1][0] *= 1 / deter;
	v[1][1] *= 1 / deter;
}

