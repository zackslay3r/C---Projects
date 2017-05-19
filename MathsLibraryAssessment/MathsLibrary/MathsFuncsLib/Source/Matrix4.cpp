#include "Matrix4.h"
#include "Matrix3.h"
// This is the default constructor for a blank matrix4.
// This ensures that a matrix4 always has default values.
Matrix4::Matrix4()
{
	
	/*
	for (int i = 0; i < 4; i++)
	{
	}
	*/
	
	v[0][0] = 1;
	v[0][1] = 0;
	v[0][2] = 0;
	v[0][3] = 0;
	v[1][0] = 0;
	v[1][1] = 1;
	v[1][2] = 0;
	v[1][3] = 0;
	v[2][0] = 0;
	v[2][1] = 0;
	v[2][2] = 1;
	v[2][3] = 0;
	v[3][0] = 0;
	v[3][1] = 0;
	v[3][2] = 0;
	v[3][3] = 1;
	

}

/*
This is a different Matrix4 constructor, it will create a default 2d array of type "real" with the parameters taken in.
*/

Matrix4::Matrix4(real x1, real x2, real x3, real x4, real y1, real y2, real y3, real y4, real z1, real z2, real z3, real z4, real w1, real w2, real w3, real w4)
{
	v[0][0] = x1;
	v[0][1] = x2;
	v[0][2] = x3;
	v[0][3] = x4;
	v[1][0] = y1;
	v[1][1] = y2;
	v[1][2] = y3;
	v[1][3] = y4;
	v[2][0] = z1;
	v[2][1] = z2;
	v[2][2] = z3;
	v[2][3] = z4;
	v[3][0] = w1;
	v[3][1] = w2;
	v[3][2] = w3;
	v[3][3] = w4;
}

//This is the Matrix4 destructor.
Matrix4::~Matrix4()
{

}
Matrix4::operator real*()
{
	return &v[0][0];
}
// This is the determinat function.
real Matrix4::determinant()
{
	real determinant;

	real a = v[0][0];
	real b = v[0][1];
	real c = v[0][2];
	real d = v[0][3];

	real e = v[1][0];
	real f = v[1][1];
	real g = v[1][2];
	real h = v[1][3];

	real i = v[2][0];
	real j = v[2][1];
	real k = v[2][2];
	real l = v[2][3];

	real m = v[3][0];
	real n = v[3][1];
	real o = v[3][2];
	real p = v[3][3];

	//combining the variables
	real dgjm = d * g * j * m;
	real chjm = c * h * j * m;
	real dfkm = d * f * k * m;
	real bhkm = b * h * k * m;
	real cflm = c * f * l * m;
	real bglm = b * g * l * m;
	real dgin = d * g * i * n;
	real chin = c * h * i * n;
	real dekn = d * e * k * n;
	real ahkn = a * h * k * n;
	real celn = c * e * l * n;
	real agln = a * g * l * n;
	real dfio = d * f * i * o;
	real bhio = b * h * i * o;
	real dejo = d * e * j * o;
	real ahjo = a * h * j * o;
	real belo = b * e * l * o;
	real aflo = a * f * l * o;
	real cfip = c * f * i * p;
	real bgip = b * g * i * p;
	real cejp = c * e * j * p;
	real agjp = a * g * j * p;
	real bekp = b * e * k * p;
	real afkp =	a * f * k * p;


	determinant = dgjm - chjm - dfkm + bhkm +
					cflm - bglm - dgin + chin + 
					dekn - ahkn - celn + agln + 
					dfio - bhio - dejo + ahjo + 
					belo - aflo - cfip + bgip + 
					cejp - agjp - bekp + afkp;
	//determinant = e * i - f * h - d * i - f * g + d * h - e * g ;

	return determinant;
}

// this is the inverse function for Matrix4's.
void Matrix4::inverse()
{
	Matrix4 tempMatrix;
	float tempFloat1;


	// Matrix of minors.
	real a = v[0][0];
	real b = v[0][1];
	real c = v[0][2];
	real d = v[0][3];
	
	real e = v[1][0];
	real f = v[1][1];
	real g = v[1][2];
	real h = v[1][3];
	
	real i = v[2][0];
	real j = v[2][1];
	real k = v[2][2];
	real l = v[2][3];

	real m = v[3][0];
	real n = v[3][1];
	real o = v[3][2];
	real p = v[3][3];
	
	// Finding the determinant
	float theDeterminant;
	theDeterminant = determinant();


	// Matrix of minors.
	v[0][0] = Matrix3{ f,g,h,j,k,l,n,o,p }.determinant();
	v[0][1] = Matrix3{ e,g,h,i,k,l,m,o,p }.determinant();
	v[0][2] = Matrix3{ e,f,h,i,j,l,m,n,p }.determinant();
	v[0][3] = Matrix3{ e,f,g,i,j,k,m,n,o }.determinant();
	v[1][0] = Matrix3{ b,c,d,j,k,l,n,o,p }.determinant();
	v[1][1] = Matrix3{ a,c,d,i,k,l,m,o,p }.determinant();
	v[1][2] = Matrix3{a,b,d,i,j,l,m,n,p}.determinant();
	v[1][3] = Matrix3{ a,b,d,i,j,l,m,n,p }.determinant();
	v[2][0] = Matrix3{ b,c,d,f,g,h,n,o,p }.determinant();
	v[2][1] = Matrix3{ a,c,d,e,g,h,m,o,p }.determinant();
	v[2][2] = Matrix3{ a,b,d,e,f,h,m,n,p }.determinant();
	v[2][3] = Matrix3{ a,b,c,e,f,g,m,n,o }.determinant();
	v[3][0] = Matrix3{ b,c,d,f,g,h,j,k,l }.determinant();
	v[3][1] = Matrix3{ a,c,d,e,g,h,i,k,l }.determinant();
	v[3][2] = Matrix3{ a,b,d,e,f,h,i,j,l }.determinant();
	v[3][3] = Matrix3{ a,b,c,e,f,g,i,j,k }.determinant();

	// turning the matrix of minors into Cofactors
	v[0][1] *= -1;
	v[0][3] *= -1;
	v[1][0] *= -1;
	v[1][2] *= -1;
	v[2][1] *= -1;
	v[2][3] *= -1;
	v[3][0] *= -1;
	v[3][2] *= -1;


	//adjulate the matrix (swapping values around)
	tempFloat1 = v[1][0];
	v[1][0] = v[0][1];
	v[0][1] = tempFloat1;

	tempFloat1 = v[0][2];
	v[0][2] = v[2][0];
	v[2][0] = tempFloat1;

	tempFloat1 = v[3][0];
	v[3][0] = v[0][3];
	v[0][3] = tempFloat1;

	tempFloat1 = v[1][3];
	v[1][3] = v[3][1];
	v[3][1] = tempFloat1;

	tempFloat1 = v[2][3];
	v[2][3] = v[3][2];
	v[3][2] = tempFloat1;


	
	
	//multiply by 1/determinant

	v[0][0] *= 1 / theDeterminant;
	v[0][1] *= 1 / theDeterminant;
	v[0][2] *= 1 / theDeterminant;
	v[0][3] *= 1 / theDeterminant;

	v[1][0] *= 1 / theDeterminant;
	v[1][1] *= 1 / theDeterminant;
	v[1][2] *= 1 / theDeterminant;
	v[1][3] *= 1 / theDeterminant;


	v[2][0] *= 1 / theDeterminant;
	v[2][1] *= 1 / theDeterminant;
	v[2][2] *= 1 / theDeterminant;
	v[2][3] *= 1 / theDeterminant;

	v[3][0] *= 1 / theDeterminant;
	v[3][1] *= 1 / theDeterminant;
	v[3][2] *= 1 / theDeterminant;
	v[3][3] *= 1 / theDeterminant;

}


// This is a Matrix4 multiplied by a Matrix4 
Matrix4 Matrix4::operator*(Matrix4 &matrix1)
{
	Matrix4 tempMatrix;

	/*// rows
	for (int i = 0; i < 4; i++)
	{
		//coloums
		for (int j = 0; j < 4; j++)
		{
			// adding together
			for (int k = 0; k < 4; k++)
			{
				tempMatrix.v[i][j] += (v[k][j] * matrix1.v[i][k]);
			}


		}

	}
	*/

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tempMatrix.v[i][j] = { v[0][j] * matrix1.v[i][0] +
			v[1][j] * matrix1.v[i][1] +
			v[2][j] * matrix1.v[i][2] +
			v[3][j] * matrix1.v[i][3] };
		}
	}

	return tempMatrix;
	

	
}

// This is a Matrix4 multiplied by a Vector4 and returning the Vector4 
Vector4 Matrix4::operator*(Vector4 &vec)
{
	Vector4 tempVec;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tempVec[i] += vec[j] * v[j][i];
		}
	}


	return tempVec;
}


// This sets the rotation Matrix based on the radiant parameter on the x axis.
void Matrix4::setRotateX(real rad)
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
void Matrix4::setRotateY(real rad)
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
void Matrix4::setRotateZ(real rad)
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
void Matrix4::identity()
{
	v[0][0] = 1;
	v[0][1] = 0;
	v[0][2] = 0;
	v[0][3] = 0;
	v[1][0] = 0;
	v[1][1] = 1;
	v[1][2] = 0;
	v[1][3] = 0;
	v[2][0] = 0;
	v[2][1] = 0;
	v[2][2] = 1;
	v[2][3] = 0;
	v[3][0] = 0;
	v[3][1] = 0;
	v[3][2] = 0;
	v[3][3] = 1;
}
