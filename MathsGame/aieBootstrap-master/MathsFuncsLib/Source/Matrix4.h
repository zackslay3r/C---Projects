#pragma once
#pragma once
#include "Vector4.h"
#include <math.h>
#include "dllmain.h"
#include "typeDef.h"


/*
* class Matrix4
*
* This is a matrix4, which stores a 2d array of 4 vector4's together and is able to
* store values of type "real" within itself. Within this matrix4, it stores functions
* which grants the ablity to be able to change values within the matrix4 itself.
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class DLL Matrix4
{
	
public:
	/* Matrix4();
	* This is the default constructor, it will create a default 2d array of type "real" with the idetity matrix of Matrix4.
	* This is created when a matrix3 is created with no parameters.
	*/
	Matrix4();

	/* Matrix4(real x1, real x2, real x3, real x4, real y1, real y2, real y3, real y4, real z1. real z2, real z3, real z4, real w1, real w2, real w3, real w4);
	* This is a different Matrix3 constructor, it will create a default 3d array of type "real" with the parameters taken in.
	* This is created when a matrix2 is created with 9 parameters of type real.

	@parameter 1 x1 - a value of 'real' defined in typeDef.h
	@parameter 2 x2 - a value of 'real' defined in typeDef.h
	@parameter 3 x3 - a value of 'real' defined in typeDef.h
	@parameter 4 x4 - a value of 'real' defined in typeDef.h
	@parameter 5 y1 - a value of 'real' defined in typeDef.h
	@parameter 6 y2 - a value of 'real' defined in typeDef.h
	@parameter 7 y3 - a value of 'real' defined in typeDef.h
	@parameter 8 y4 - a value of 'real' defined in typeDef.h
	@parameter 9 z1 - a value of 'real' defined in typeDef.h
	@parameter 10 z2 - a value of 'real' defined in typeDef.h
	@parameter 11 z3 - a value of 'real' defined in typeDef.h
	@parameter 12 z4 - a value of 'real' defined in typeDef.h
	@parameter 13 w1 - a value of 'real' defined in typeDef.h
	@parameter 14 w2 - a value of 'real' defined in typeDef.h
	@parameter 15 w3 - a value of 'real' defined in typeDef.h
	@parameter 16 w4 - a value of 'real' defined in typeDef.h

	*/
	Matrix4(
		real x1, real x2, real x3, real x4,
		real y1, real y2, real y3, real y4,
		real z1, real z2, real z3, real z4,
		real w1, real w2, real w3, real w4);
	/* Matrix4();
	* This is the default destructor, it will destroy a Matrix4.
	* This is called when a the main program has reached the end of its scope.
	*/
	~Matrix4();
	Vector4 v[4];
	operator real*();
	/* real Matrix4::determinant();
	* This is a function that will find the determinat of a matrix4 and return it as type 'real' as defined in typeDef.h.
	*
	@ returns determinat - a value of type 'real'.
	*/
	real Matrix4::determinant();
	/* void Matrix4::inverse();
	*
	* This function returns the inverse of a Matrix4.
	*
	* @returns void
	*/
	void Matrix4::inverse();
	/* Matrix4 operator*(Matrix4 &mat1);
	* This function allows for the ablity to be able to multiply 2 Matrix4's together
	* in order to return a single Matrix4.
	*
	* @parameter 1 &mat1 - a Matrix4.
	*
	* @returns tempMatrix - a Matrix4 which is two Matrix4's multipled together.
	*/
	Matrix4 operator*(Matrix4 &mat1);
	
	/* Vector4 Matrix4::operator*(Vector4 &vec);
	* This function allows for the ablity to be able to multiply a Matrix4 by a Vector4
	* in order to return a single Vector4.
	*
	* @parameter 1 &vec - a Vector4.
	*
	* @returns tempVec - a Vector4 which is of a Vector4 and a Matrix4 multipled together.
	*/
	Vector4 Matrix4::operator*(Vector4 &matrx);
	
	/* void Matrix4::setRotateX(real x);
	*
	* This function sets the rotation matrix of a Matrix4 if required based on the parameter taken in (which is a radiant) and affects the x axis.
	*
	* @parameter 1 - x is of type real, which is defined in typeDef.h
	*
	* @returns void
	*/
	void Matrix4::setRotateX(real x);

	/* void Matrix4::setRotateY(real y);
	*
	* This function sets the rotation matrix of a Matrix4 if required based on the parameter taken in (which is a radiant) and affects the y axis.
	*
	* @parameter 1 - y is of type real, which is defined in typeDef.h
	*
	* @returns void
	*/
	void Matrix4::setRotateY(real y);
	
	/* void Matrix4::setRotateZ(real z);
	*
	* This function sets the rotation matrix of a Matrix4 if required based on the parameter taken in (which is a radiant) and affects the z axis.
	*
	* @parameter 1 - z is of type real, which is defined in typeDef.h
	*
	* @returns void
	*/
	void Matrix4::setRotateZ(real z);
	
	/* void Matrix4::identity();
	*
	* This function returns the identity matrix of a Matrix4.
	*
	* @returns void
	*/
	void Matrix4::identity();

	Vector4 & Matrix4::operator[](int n)
	{
		return v[n];
	}

};