#pragma once
#include "Vector2.h"
#include <math.h>
#include "dllmain.h"
#include "typeDef.h"


/*
* class Matrix2
*
* This is a matrix2, which stores a 2d array of 2 lots of vector2's together and is able to 
* store values of type "real" within itself. Within this matrix2, it stores functions
* which grants the ablity to be able to change values within the matrix2 itself.
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class DLL Matrix2
{
	
public:
	/* Matrix2();
	* This is the default constructor, it will create a default 2d array of type "real" with the idetity matrix of Matrix2. 
	* This is created when a matrix2 is created with no parameters.
	*/
	Matrix2();

	/* Matrix2(real x1, real x2, real y1, real y2);
	* This is a different Matrix2 constructor, it will create a default 2d array of type "real" with the parameters taken in.
	* This is created when a matrix2 is created with 4 parameters of type real.

	@parameter 1 x1 - a value of 'real' defined in typeDef.h
	@parameter 2 x2 - a value of 'real' defined in typeDef.h
	@parameter 3 y1 - a value of 'real' defined in typeDef.h
	@parameter 4 y2 - a value of 'real' defined in typeDef.h
	*/
	Matrix2(real x1, real x2, real y1, real y2);
	
	/* Matrix2();
	* This is the default destructor, it will destroy a Matrix2.
	* This is called when a the main program has reached the end of its scope.
	*/
	~Matrix2();
	
	Vector2 v[2];
	
	operator real*();
	
	/* Matrix2 operator*(Matrix2 &mat1);
	* This function allows for the ablity to be able to multiply 2 Matrix2's together 
	* in order to return a single Matrix2.
	*
	* @parameter 1 &mat1 - a Matrix2.
	* 
	* @returns tempMatrix - a Matrix2 which is two Matrix2's multipled together. 
	*/
	Matrix2 operator*(Matrix2 &mat1);

	/* Vector2 Matrix2::operator*(Vector2 &vec);
	* This function allows for the ablity to be able to multiply a Matrix2 by a Vector2 
	* in order to return a single Vector2.
	*
	* @parameter 1 &vec - a Vector2.
	*
	* @returns tempVec - a Vector2 which is of a Vector2 and a Matrix2 multipled together.
	*/
	Vector2 Matrix2::operator*(Vector2 &vec);

	/* void Matrix2::setRotate(real rad);
	*
	* This function sets the rotation matrix of a Matrix2 if required based on the parameter taken in (which is a radiant).
	*
	* @parameter 1 - rad is of type real, which is defined in typeDef.h
	*
	* @returns void
	*/
	void Matrix2::setRotate(real rad);
	
	/* void Matrix2::identity();
	*
	* This function returns the identity matrix of a Matrix2.
	*
	* @returns void
	*/
	void Matrix2::identity();
	
	/* real Matrix2::determinant(real x1, real y1, real x2, real y2);
	* This is a function that will find the determinat of a matrix2 and return it as type 'real' as defined in typeDef.h.
	*
	@parameter 1 x1 - a value of 'real' defined in typeDef.h
	@parameter 2 x2 - a value of 'real' defined in typeDef.h
	@parameter 3 y1 - a value of 'real' defined in typeDef.h
	@parameter 4 y2 - a value of 'real' defined in typeDef.h
	
	@ returns determinat - a value of type 'real'.
	*/
	real Matrix2::determinant(real x1, real y1, real x2, real y2);
	
	/* void Matrix2::inverse();
	*
	* This function returns the inverse of a Matrix2.
	*
	* @returns void
	*/
	void Matrix2::inverse();



	Vector2 & Matrix2::operator[](int n)
	{
		return v[n];
	}

};