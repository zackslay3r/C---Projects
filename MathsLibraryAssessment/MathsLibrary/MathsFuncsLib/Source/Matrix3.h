
#pragma once
#include "Vector3.h"
#include "Vector2.h"
#include <math.h>
#include "typeDef.h"

/*
* class Matrix3
*
* This is a matrix3, which stores a 2d array of 3 lots of vector3's together and is able to
* store values of type "real" within itself. Within this matrix3, it stores functions
* which grants the ablity to be able to change values within the matrix3 itself.
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class DLL Matrix3
{

public:
	/* Matrix3();
	* This is the default constructor, it will create a default 2d array of type "real" with the idetity matrix of Matrix3.
	* This is created when a matrix3 is created with no parameters.
	*/
	Matrix3();

	/* Matrix3(real x1, real x2, real x3, real y1, real y2, real y3, real z1, real z2, real z3);
	* This is a different Matrix3 constructor, it will create a default 3d array of type "real" with the parameters taken in.
	* This is created when a matrix2 is created with 9 parameters of type real.

	@parameter 1 x1 - a value of 'real' defined in typeDef.h
	@parameter 2 x2 - a value of 'real' defined in typeDef.h
	@parameter 3 x3 - a value of 'real' defined in typeDef.h
	@parameter 4 y1 - a value of 'real' defined in typeDef.h
	@parameter 5 y2 - a value of 'real' defined in typeDef.h
	@parameter 6 y3 - a value of 'real' defined in typeDef.h
	@parameter 7 z1 - a value of 'real' defined in typeDef.h
	@parameter 8 z2 - a value of 'real' defined in typeDef.h
	@parameter 9 z9 - a value of 'real' defined in typeDef.h
	
	*/
	Matrix3(real x1, real x2, real x3,
		real y1, real y2, real y3,
		real z1, real z2, real z3);
	
	/* Matrix3();
	* This is the default destructor, it will destroy a Matrix3.
	* This is called when a the main program has reached the end of its scope.
	*/
	~Matrix3();
	Vector3 v[3];
	operator real*();

	/* real Matrix3::determinant();
	* This is a function that will find the determinat of a matrix3 and return it as type 'real' as defined in typeDef.h.
	*
	@ returns determinat - a value of type 'real'.
	*/
	real Matrix3::determinant();
	
	/* void Matrix3::inverse();
	*
	* This function returns the inverse of a Matrix3.
	*
	* @returns void
	*/
	void Matrix3::inverse();
	
	/* Matrix3 operator*(Matrix3 &mat1);
	* This function allows for the ablity to be able to multiply 2 Matrix3's together
	* in order to return a single Matrix3.
	*
	* @parameter 1 &mat1 - a Matrix3.
	*
	* @returns tempMatrix - a Matrix3 which is two Matrix3's multipled together.
	*/
	Matrix3 operator*(Matrix3 &mat1);
	/* Vector3 Matrix3::operator*(Vector3 &vec);
	* This function allows for the ablity to be able to multiply a Matrix3 by a Vector3
	* in order to return a single Vector3.
	*
	* @parameter 1 &vec - a Vector3.
	*
	* @returns tempVec - a Vector3 which is of a Vector2 and a Matrix2 multipled together.
	*/
	Vector3 Matrix3::operator*(Vector3 &vec);
	
	/* Vector2 Matrix3::operator*(Vector2 &vec);
	* This function allows for the ablity to be able to multiply a Matrix3 by a Vector2
	* in order to return a single Vector2.
	*
	* @parameter 1 &vec2 - a Vector2.
	*
	* @returns tempVec - a Vector2 which is of a Vector2 and a Matrix2 multipled together.
	*/
	Vector2 Matrix3::operator*(Vector2 &vec2);
	
	/* void Matrix3::setRotateX(real x);
	*
	* This function sets the rotation matrix of a Matrix3 if required based on the parameter taken in (which is a radiant) and affects the x axis.
	*
	* @parameter 1 - x is of type real, which is defined in typeDef.h
	*
	* @returns void
	*/
	void Matrix3::setRotateX(real x);
	
	/* void Matrix3::setRotateY(real y);
	*
	* This function sets the rotation matrix of a Matrix3 if required based on the parameter taken in (which is a radiant) and affects the y axis.
	*
	* @parameter 1 - y is of type real, which is defined in typeDef.h
	*
	* @returns void
	*/
	void Matrix3::setRotateY(real y);
	
	/* void Matrix3::setRotateZ(real z);
	*
	* This function sets the rotation matrix of a Matrix3 if required based on the parameter taken in (which is a radiant) and affects the z axis.
	*
	* @parameter 1 - z is of type real, which is defined in typeDef.h
	*
	* @returns void
	*/
	void Matrix3::setRotateZ(real z);
	
	/* void Matrix3::identity();
	*
	* This function returns the identity matrix of a Matrix3.
	*
	* @returns void
	*/
	void Matrix3::identity();

	Vector3 & Matrix3::operator[](int n)
	{
		return v[n];
	}

};