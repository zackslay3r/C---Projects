#pragma once
#include "dllmain.h"
#include "typeDef.h"

class Vector2;
class Vector4;

/*
* class Vector3
* This is a Vector3, which stores a 1d array of 3 values of type 'real' (defined in typeDef.h) within itself.
* Within this Vector3, it stores functions which grants the ablity to be able to change values within the Vector3 itself.
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class DLL Vector3
{
public:
	/* Vector3();
	* This is the default constructor, it will create a default 1d array with 3 values of tpye 'real'.
	* This is created when a Vector3 is created with no parameters.
	*/
	Vector3();
	
	/* Vector3(real newx, real newy, real newz);
	* This is a different Vector3 constructor, it will create a default 1d array with 3 values of type "real" with the parameters taken in.
	* This is created when a Vector3 is created with 3 parameters of type real.

	@parameter 1 newx - a value of 'real' defined in typeDef.h
	@parameter 2 newy - a value of 'real' defined in typeDef.h
	@parameter 3 newz - a value of 'real' defined in typeDef.h

	*/
	Vector3(real newx, real newy, real newz);
	
	/* Vector3();
	* This is the default destructor, it will destroy a Vector3.
	* This is called when a the main program has reached the end of its scope.
	*/
	~Vector3();
	union
	{
		struct { real x, y, z; };
		real e[3];
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
	* GetXY
	*
	* swizzles vector to (x,y)
	*
	* @returns Vector2 - the swizzled vector
	*/
	 Vector2 GetXY();

	/*
	* GetXZ
	*
	* swizzles vector to (x,z)
	*
	* @returns Vector2 - the swizzled vector
	*/
	 Vector2 GetXZ();

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
	* GetYZ
	*
	* swizzles vector to (y,z)
	*
	* @returns Vector2 - the swizzled vector
	*/
	 Vector2 GetYZ();

	/*
	* GetZX
	*
	* swizzles vector to (z,x)
	*
	* @returns Vector2 - the swizzled vector
	*/
	 Vector2 GetZX();

	/*
	* GetZY
	*
	* swizzles vector to (z,y)
	*
	* @returns Vector2 - the swizzled vector
	*/
	 Vector2 GetZY();

	/*
	* GetZZ
	*
	* swizzles vector to (z,z)
	*
	* @returns Vector2 - the swizzled vector
	*/
	 Vector2 GetZZ();

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
	* GetXXZ
	*
	* swizzles vector to (x,x,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetXXZ();

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
	* GetXZX
	*
	* swizzles vector to (x,z,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetXZX();

	/*
	* GetXZY
	*
	* swizzles vector to (x,z,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetXZY();

	/*
	* GetXZZ
	*
	* swizzles vector to (x,z,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetXZZ();

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
	* GetYXZ
	*
	* swizzles vector to (y,x,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetYXZ();

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
	* GetYYZ
	*
	* swizzles vector to (y,y,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetYYZ();

	/*
	* GetYZX
	*
	* swizzles vector to (y,z,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetYZX();

	/*
	* GetYZY
	*
	* swizzles vector to (y,z,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetYZY();

	/*
	* GetYZZ
	*
	* swizzles vector to (y,z,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetYZZ();

	/*
	* GetZXX
	*
	* swizzles vector to (z,x,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetZXX();

	/*
	* GetZXY
	*
	* swizzles vector to (z,x,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetZXY();

	/*
	* GetZXZ
	*
	* swizzles vector to (z,x,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetZXZ();

	/*
	* GetZYX
	*
	* swizzles vector to (z,y,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetZYX();

	/*
	* GetZYY
	*
	* swizzles vector to (z,y,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetZYY();

	/*
	* GetZYZ
	*
	* swizzles vector to (z,y,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetZYZ();

	/*
	* GetZZX
	*
	* swizzles vector to (z,z,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetZZX();

	/*
	* GetZZY
	*
	* swizzles vector to (z,z,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetZZY();

	/*
	* GetZZZ
	*
	* swizzles vector to (z,z,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetZZZ();

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
	* GetXXXZ
	*
	* swizzles vector to (x,x,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXXXZ();

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
	* GetXXYZ
	*
	* swizzles vector to (x,x,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXXYZ();

	/*
	* GetXXZX
	*
	* swizzles vector to (x,x,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXXZX();

	/*
	* GetXXZY
	*
	* swizzles vector to (x,x,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXXZY();

	/*
	* GetXXZZ
	*
	* swizzles vector to (x,x,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXXZZ();

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
	* GetXYXZ
	*
	* swizzles vector to (x,y,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXYXZ();

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
	* GetXYYZ
	*
	* swizzles vector to (x,y,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXYYZ();

	/*
	* GetXYZX
	*
	* swizzles vector to (x,y,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXYZX();

	/*
	* GetXYZY
	*
	* swizzles vector to (x,y,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXYZY();

	/*
	* GetXYZZ
	*
	* swizzles vector to (x,y,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXYZZ();

	/*
	* GetXZXX
	*
	* swizzles vector to (x,z,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXZXX();

	/*
	* GetXZXY
	*
	* swizzles vector to (x,z,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXZXY();

	/*
	* GetXZXZ
	*
	* swizzles vector to (x,z,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXZXZ();

	/*
	* GetXZYX
	*
	* swizzles vector to (x,z,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXZYX();

	/*
	* GetXZYY
	*
	* swizzles vector to (x,z,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXZYY();

	/*
	* GetXZYZ
	*
	* swizzles vector to (x,z,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXZYZ();

	/*
	* GetXZZX
	*
	* swizzles vector to (x,z,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXZZX();

	/*
	* GetXZZY
	*
	* swizzles vector to (x,z,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXZZY();

	/*
	* GetXZZZ
	*
	* swizzles vector to (x,z,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXZZZ();

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
	* GetYXXZ
	*
	* swizzles vector to (y,x,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYXXZ();

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
	* GetYXYZ
	*
	* swizzles vector to (y,x,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYXYZ();

	/*
	* GetYXZX
	*
	* swizzles vector to (y,x,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYXZX();

	/*
	* GetYXZY
	*
	* swizzles vector to (y,x,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYXZY();

	/*
	* GetYXZZ
	*
	* swizzles vector to (y,x,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYXZZ();

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
	* GetYYXZ
	*
	* swizzles vector to (y,y,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYYXZ();

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

	/*
	* GetYYYZ
	*
	* swizzles vector to (y,y,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYYYZ();

	/*
	* GetYYZX
	*
	* swizzles vector to (y,y,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYYZX();

	/*
	* GetYYZY
	*
	* swizzles vector to (y,y,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYYZY();

	/*
	* GetYYZZ
	*
	* swizzles vector to (y,y,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYYZZ();

	/*
	* GetYZXX
	*
	* swizzles vector to (y,z,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYZXX();

	/*
	* GetYZXY
	*
	* swizzles vector to (y,z,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYZXY();

	/*
	* GetYZXZ
	*
	* swizzles vector to (y,z,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYZXZ();

	/*
	* GetYZYX
	*
	* swizzles vector to (y,z,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYZYX();

	/*
	* GetYZYY
	*
	* swizzles vector to (y,z,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYZYY();

	/*
	* GetYZYZ
	*
	* swizzles vector to (y,z,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYZYZ();

	/*
	* GetYZZX
	*
	* swizzles vector to (y,z,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYZZX();

	/*
	* GetYZZY
	*
	* swizzles vector to (y,z,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYZZY();

	/*
	* GetYZZZ
	*
	* swizzles vector to (y,z,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYZZZ();

	/*
	* GetZXXX
	*
	* swizzles vector to (z,x,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZXXX();

	/*
	* GetZXXY
	*
	* swizzles vector to (z,x,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZXXY();

	/*
	* GetZXXZ
	*
	* swizzles vector to (z,x,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZXXZ();

	/*
	* GetZXYX
	*
	* swizzles vector to (z,x,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZXYX();

	/*
	* GetZXYY
	*
	* swizzles vector to (z,x,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZXYY();

	/*
	* GetZXYZ
	*
	* swizzles vector to (z,x,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZXYZ();

	/*
	* GetZXZX
	*
	* swizzles vector to (z,x,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZXZX();

	/*
	* GetZXZY
	*
	* swizzles vector to (z,x,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZXZY();

	/*
	* GetZXZZ
	*
	* swizzles vector to (z,x,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZXZZ();

	/*
	* GetZYXX
	*
	* swizzles vector to (z,y,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZYXX();

	/*
	* GetZYXY
	*
	* swizzles vector to (z,y,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZYXY();

	/*
	* GetZYXZ
	*
	* swizzles vector to (z,y,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZYXZ();

	/*
	* GetZYYX
	*
	* swizzles vector to (z,y,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZYYX();

	/*
	* GetZYYY
	*
	* swizzles vector to (z,y,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZYYY();

	/*
	* GetZYYZ
	*
	* swizzles vector to (z,y,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZYYZ();

	/*
	* GetZYZX
	*
	* swizzles vector to (z,y,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZYZX();

	/*
	* GetZYZY
	*
	* swizzles vector to (z,y,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZYZY();

	/*
	* GetZYZZ
	*
	* swizzles vector to (z,y,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZYZZ();

	/*
	* GetZZXX
	*
	* swizzles vector to (z,z,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZZXX();

	/*
	* GetZZXY
	*
	* swizzles vector to (z,z,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZZXY();

	/*
	* GetZZXZ
	*
	* swizzles vector to (z,z,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZZXZ();

	/*
	* GetZZYX
	*
	* swizzles vector to (z,z,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZZYX();

	/*
	* GetZZYY
	*
	* swizzles vector to (z,z,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZZYY();

	/*
	* GetZZYZ
	*
	* swizzles vector to (z,z,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZZYZ();

	/*
	* GetZZZX
	*
	* swizzles vector to (z,z,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZZZX();

	/*
	* GetZZZY
	*
	* swizzles vector to (z,z,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZZZY();

	/*
	* GetZZZZ
	*
	* swizzles vector to (z,z,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZZZZ();
#pragma endregion swizzling


	
	/*	Vector3 operator+(Vector3 &other);
	*	This function overloads the + operator so that 2 Vector3's can be added together.
	*
	*	parameter 1 &other - a Vector3.
	*	@returns Vector3
	*/
	Vector3 operator+(Vector3 &other);
	
	
	/*	void Vector3::operator=(Vector2 &other);
	*	This function overloads the = operator so that a Vector3 equal's a vector2.
	*
	*	parameter 1 &other - a Vector2.
	*	@returns void
	*/
	void Vector3::operator=(Vector2 &other);

	/*	void Vector3::operator=(Vector4 &other);
	*	This function overloads the = operator so that a Vector3 equal's a vector4.
	*
	*	parameter 1 &other - a Vector4.
	*	@returns void
	*/
	void Vector3::operator=(Vector4 &other);
	
	
	/*	void Vector3::operator+=(const Vector3 &other);
	*	This function overloads the += operator so that a Vector3's can add by itself followed by another Vector3.
	*
	*	parameter 1 &other - a Vector3.
	*	@returns Vector3
	*/
	void Vector3::operator+=(const Vector3 &other);
	
	// V = V - V (point translated by a vector)
	//
	/*	Vector3 operator-(Vector3 &other);
	*	This function overloads the - operator so that 2 Vector3's can be subtracted from each other.
	*
	*	parameter 1 &other - a Vector3.
	*	@returns Vector3
	*/
	Vector3 operator-(Vector3 &other);

	/*	void Vector3::operator-=(const Vector3 &other);
	*	This function overloads the -= operator so that a Vector3's can subtract by itself followed by another Vector3.
	*
	*	parameter 1 &other - a Vector3.
	*	@returns Vector3
	*/
	void Vector3::operator-=(const Vector3 &other);
	
	/*	void Vector3::operator*=(const Vector3 &other);
	*	This function overloads the *= operator so that a Vector3's can multiply by itself followed by another Vector3.
	*
	*	parameter 1 &other - a Vector3.
	*	@returns Vector3
	*/
	void Vector3::operator*=(const Vector3 &other);

	//V = V x f (vector scale)
	
	/*	Vector3 operator*(real scalar);
	*	This function overloads the * operator so that a Vector3 can be multiplied by a real value.
	*
	*	parameter 1 scalar - a 'real' value.
	*	@returns Vector3
	*/
	Vector3 operator*(real scalar);
	
	//V = f x V (vector scale)

	/*	friend Vector3 operator*(real scalar, Vector3 &other);
	*	This function overloads the * operator so that a Vector3 can be equal to a 'real' value multiplied by a Vector3.
	*
	*	parameter 1 scalar - a 'real' value.
	*	parameter 2 &other - a Vector3.
	*	@returns Vector3
	*/
	friend DLL Vector3 operator*(real scalar, Vector3 &other);
	
	//f = V.dot(V)
	/*	real dot(Vector3 &other);
	*	This function returns a 'real' value that is based on the dot product of a inputted Vector3.
	*
	*	parameter 1 &other - a Vector3.
	*	@returns 'real'
	*/
	real dot(Vector3 &other);

	//V = V.cross(V)
	/*	Vector3 cross(Vector3 &other);
	*	This function returns a Vector3 that is based on the cross product of a Vector3.
	*
	*	parameter 1 &other - a Vector3.
	*	@returns Vector3
	*/
	Vector3 cross(Vector3 &other);

	//f = V.magnitude()
	/*	real magnitude();
	*	This function returns a 'real' value that is the magnitude of a Vector3.
	*
	*	@returns 'real' (defined in typeDef.h)
	*/
	real magnitude();

	//V.normalised
	/*	Vector3 normalised();
	*	This function returns a Vector3 that has been normalised.
	*
	*
	*	@returns Vector3
	*/
	Vector3 normalised();
	
	//V.normalise()
	/*	void normalise();
	*	This function normalises a Vector3.
	*
	*
	*	@returns void
	*/
	void normalise();
	
	real operator[](int n)const;

	real &operator[](int n);

	operator real*() { return &e[0]; };

	/* operator Vector2();
	*
	* This function allows a Vector3 to be used as a Vector2.
	*
	* @returns Vector4(x,y)
	*/
	operator Vector2();
	
	/* operator Vector4();
	*
	* This function allows a Vector3 to be used as a Vector4.
	*
	* @returns Vector4(x,y,z,0)
	*/
	operator Vector4();

	#pragma region swizzling

	#pragma endregion

};