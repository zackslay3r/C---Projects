#pragma once
#include "dllmain.h"
#include "Vector4.h"
#include "typeDef.h"


class Vector4;
class Vector3;


/*
* class Vector2
* This is a Vector2, which stores a 1d array of 2 values of type 'real' (defined in typeDef.h) within itself. 
* Within this Vector2, it stores functions which grants the ablity to be able to change values within the Vector2 itself.
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/

class DLL Vector2
{
public:
	/* Vector2();
	* This is the default constructor, it will create a default 1d array with 2 values of type 'real'.
	* This is created when a Vector2 is created with no parameters.
	*/
	Vector2();
	
	/* Vector2(real newx, real newy);
	* This is a different Vector2 constructor, it will create a default 1d array with 2 values of type "real" with the parameters taken in.
	* This is created when a Vector2 is created with 2 parameters of type real.

	@parameter 1 newx - a value of 'real' defined in typeDef.h
	@parameter 2 newy - a value of 'real' defined in typeDef.h
	
	*/
	Vector2(real newx, real newy);
	
	/* Vector2();
	* This is the default destructor, it will destroy a Vector2.
	* This is called when a the main program has reached the end of its scope.
	*/
	~Vector2();
	
	union
	{
		struct { real x, y; };
		real e[2];
	};
	
#pragma region swizzling
	/*
	* GetXX
	*
	* swizzles vector to (x,x)
	*
	* @returns Vector2 - the swizzled vector
	*/
	 Vector2 GetXX();

	/*
	* GetYX
	*
	* swizzles vector to (y,x)
	*
	* @returns Vector2 - the swizzled vector
	*/
	 Vector2 GetYX();

	/*
	* GetYY
	*
	* swizzles vector to (y,y)
	*
	* @returns Vector2 - the swizzled vector
	*/
	 Vector2 GetYY();

	/*
	* GetXXX
	*
	* swizzles vector to (x,x,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetXXX();

	/*
	* GetXXY
	*
	* swizzles vector to (x,x,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetXXY();

	/*
	* GetXYX
	*
	* swizzles vector to (x,y,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetXYX();

	/*
	* GetXYY
	*
	* swizzles vector to (x,y,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetXYY();

	/*
	* GetYXX
	*
	* swizzles vector to (y,x,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetYXX();

	/*
	* GetYXY
	*
	* swizzles vector to (y,x,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetYXY();

	/*
	* GetYYX
	*
	* swizzles vector to (y,y,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetYYX();

	/*
	* GetYYY
	*
	* swizzles vector to (y,y,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetYYY();

	/*
	* GetXXXX
	*
	* swizzles vector to (x,x,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXXXX();

	/*
	* GetXXXY
	*
	* swizzles vector to (x,x,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXXXY();

	/*
	* GetXXYX
	*
	* swizzles vector to (x,x,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXXYX();

	/*
	* GetXXYY
	*
	* swizzles vector to (x,x,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXXYY();

	/*
	* GetXYXX
	*
	* swizzles vector to (x,y,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXYXX();

	/*
	* GetXYXY
	*
	* swizzles vector to (x,y,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXYXY();

	/*
	* GetXYYX
	*
	* swizzles vector to (x,y,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXYYX();

	/*
	* GetXYYY
	*
	* swizzles vector to (x,y,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXYYY();

	/*
	* GetYXXX
	*
	* swizzles vector to (y,x,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYXXX();

	/*
	* GetYXXY
	*
	* swizzles vector to (y,x,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYXXY();

	/*
	* GetYXYX
	*
	* swizzles vector to (y,x,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYXYX();

	/*
	* GetYXYY
	*
	* swizzles vector to (y,x,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYXYY();

	/*
	* GetYYXX
	*
	* swizzles vector to (y,y,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYYXX();

	/*
	* GetYYXY
	*
	* swizzles vector to (y,y,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYYXY();

	/*
	* GetYYYX
	*
	* swizzles vector to (y,y,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYYYX();

	/*
	* GetYYYY
	*
	* swizzles vector to (y,y,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYYYY();



#pragma endregion swizzling
	
	
	
	/*	void Vector2::operator=(Vector4 &other);
	*	This function overloads the = operator so that a Vector2 equal's a vector4.
	*
	*	parameter 1 &other - a Vector4.	
	*	@returns void
	*/
	void Vector2::operator=(Vector4 &other);

	/*	void Vector2::operator=(Vector3 &other);
	*	This function overloads the = operator so that a Vector2 equal's a vector3.
	*	
	*	parameter 1 &other - a Vector3.
	*	@returns void
	*/
	void Vector2::operator=(Vector3 &other);
	
	/*	 Vector2 operator+(Vector2 &other);
	*	This function overloads the + operator so that 2 Vector2's can be added together. 
	*
	*	parameter 1 &other - a Vector2.
	*	@returns Vector2
	*/
	 Vector2 operator+(Vector2 &other);

	 /*	void Vector2::operator+=(const Vector2 &other);
	 *	This function overloads the += operator so that a Vector2's can add by itself followed by another Vector2.
	 *
	 *	parameter 1 &other - a Vector2.
	 *	@returns Vector2
	 */
	 void Vector2::operator+=(const Vector2 &other);
	
	 /*	Vector2 operator-(Vector2 &other);
	 *	This function overloads the - operator so that 2 Vector2's can be subtracted from each other.
	 *
	 *	parameter 1 &other - a Vector2.
	 *	@returns Vector2
	 */
	Vector2 operator-(Vector2 &other);
	
	/*	void Vector2::operator-=(const Vector2 &other);
	*	This function overloads the -= operator so that a Vector2's can subtract by itself followed by another Vector2.
	*
	*	parameter 1 &other - a Vector2.
	*	@returns Vector2
	*/
	void Vector2::operator-=(const Vector2 &other);
	
	/*	void Vector2::operator*=(const Vector2 &other);
	*	This function overloads the *= operator so that a Vector2's can multiply by itself followed by another Vector2.
	*
	*	parameter 1 &other - a Vector2.
	*	@returns Vector2
	*/
	void Vector2::operator*=(const Vector2 &other);
	
	
	/*	Vector2 operator*(real scalar);
	*	This function overloads the * operator so that a Vector2 can be multiplied by a real value.
	*
	*	parameter 1 scalar - a 'real' value.
	*	@returns Vector2
	*/
	Vector2 operator*(real scalar);


	//V = f x V (vector scale)

	/* friend Vector2 operator*(real scalar, Vector2 &other);
	*	This function overloads the * operator so that a Vector2 can be equal to a 'real' value multiplied by a Vector2.
	*
	*	parameter 1 scalar - a 'real' value.
	*	parameter 2 &other - a Vector2.
	*	@returns Vector2
	*/
	friend DLL Vector2 operator*(real scalar, Vector2 &other);

	//f = V.dot(V)

	/*	real dot(Vector2 &other);
	*	This function returns a 'real' value that is based on the dot product of a inputted Vector2.
	*
	*	parameter 1 &other - a Vector2.
	*	@returns 'real' 
	*/
	real dot(Vector2 &other);


	
	/*	real magnitude();
	*	This function returns a 'real' value that is the magnitude of a Vector2.
	*
	*	@returns 'real' (defined in typeDef.h)
	*/
	real magnitude();

	/*	Vector2 normalised();
	*	This function returns a Vector2 that has been normalised.
	*
	*	
	*	@returns Vector2
	*/
	Vector2 normalised();

	/*	void normalise();
	*	This function normalises a Vector2.
	*
	*
	*	@returns void
	*/
	void normalise();

	real operator[](int n)const;

	real &operator[](int n);

	/* operator Vector3();
	*
	* This function allows a Vector2 to be used as a Vector3.
	*
	* @returns Vector3(x,y,0)
	*/
	operator Vector3();

	/* operator Vector3();
	*
	* This function allows a Vector2 to be used as a Vector4.
	*
	* @returns Vector4(x,y,0,0)
	*/
	operator Vector4();

	operator real*() { return &e[0]; };
};