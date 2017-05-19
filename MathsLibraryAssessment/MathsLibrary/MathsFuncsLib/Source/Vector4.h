#pragma once
#include "dllmain.h"
#include "typeDef.h"


// These classes are forward declared within the Vector4.
// This is to ensure that a Vector4 knows what a Vector3 
// and a Vector2 is so that thse can be used for casting.
class Vector2;
class Vector3;

/*
* class Vector4
* This is a Vector4, which stores a 1d array of 4 values of type 'real' (defined in typeDef.h) within itself.
* Within this Vector4, it stores functions which grants the ablity to be able to change values within the Vector4 itself.
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class DLL Vector4
{
public:
	/* Vector4();
	* This is the default constructor, it will create a default 1d array with 4 values of tpye 'real'.
	* This is created when a Vector4 is created with no parameters.
	*/
	Vector4();

	/* Vector4(real newx, real newy, real newz, real neww);
	* This is a different Vector4 constructor, it will create a default 1d array with 4 values of type "real" with the parameters taken in.
	* This is created when a Vector4 is created with 4 parameters of type real.

	@parameter 1 newx - a value of 'real' defined in typeDef.h
	@parameter 2 newy - a value of 'real' defined in typeDef.h
	@parameter 3 newz - a value of 'real' defined in typeDef.h
	@parameter 4 neww - a value of 'real' defined in typeDef.h

	*/
	Vector4(real newx, real newy, real newz, real neww);
	
	/* Vector4();
	* This is the default destructor, it will destroy a Vector4.
	* This is called when a the main program has reached the end of its scope.
	*/
	~Vector4();
	
	union
	{
		struct { real  x, y, z, w; };
		real e[4];
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
	* GetXW
	*
	* swizzles vector to (x,w)
	*
	* @returns Vector2 - the swizzled vector
	*/
	 Vector2 GetXW();

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
	* GetYW
	*
	* swizzles vector to (y,w)
	*
	* @returns Vector2 - the swizzled vector
	*/
	 Vector2 GetYW();

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
	* GetZW
	*
	* swizzles vector to (z,w)
	*
	* @returns Vector2 - the swizzled vector
	*/
	 Vector2 GetZW();

	/*
	* GetWX
	*
	* swizzles vector to (w,x)
	*
	* @returns Vector2 - the swizzled vector
	*/
	 Vector2 GetWX();

	/*
	* GetWY
	*
	* swizzles vector to (w,y)
	*
	* @returns Vector2 - the swizzled vector
	*/
	 Vector2 GetWY();

	/*
	* GetWZ
	*
	* swizzles vector to (w,z)
	*
	* @returns Vector2 - the swizzled vector
	*/
	 Vector2 GetWZ();

	/*
	* GetWW
	*
	* swizzles vector to (w,w)
	*
	* @returns Vector2 - the swizzled vector
	*/
	 Vector2 GetWW();

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
	* GetXXW
	*
	* swizzles vector to (x,x,w)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetXXW();

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
	* GetXYZ
	*
	* swizzles vector to (x,y,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetXYZ();

	/*
	* GetXYW
	*
	* swizzles vector to (x,y,w)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetXYW();

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
	* GetXZW
	*
	* swizzles vector to (x,z,w)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetXZW();

	/*
	* GetXWX
	*
	* swizzles vector to (x,w,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetXWX();

	/*
	* GetXWY
	*
	* swizzles vector to (x,w,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetXWY();

	/*
	* GetXWZ
	*
	* swizzles vector to (x,w,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetXWZ();

	/*
	* GetXWW
	*
	* swizzles vector to (x,w,w)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetXWW();

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
	* GetYXW
	*
	* swizzles vector to (y,x,w)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetYXW();

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
	* GetYYW
	*
	* swizzles vector to (y,y,w)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetYYW();

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
	* GetYZW
	*
	* swizzles vector to (y,z,w)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetYZW();

	/*
	* GetYWX
	*
	* swizzles vector to (y,w,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetYWX();

	/*
	* GetYWY
	*
	* swizzles vector to (y,w,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetYWY();

	/*
	* GetYWZ
	*
	* swizzles vector to (y,w,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetYWZ();

	/*
	* GetYWW
	*
	* swizzles vector to (y,w,w)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetYWW();

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
	* GetZXW
	*
	* swizzles vector to (z,x,w)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetZXW();

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
	* GetZYW
	*
	* swizzles vector to (z,y,w)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetZYW();

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
	* GetZZW
	*
	* swizzles vector to (z,z,w)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetZZW();

	/*
	* GetZWX
	*
	* swizzles vector to (z,w,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetZWX();

	/*
	* GetZWY
	*
	* swizzles vector to (z,w,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetZWY();

	/*
	* GetZWZ
	*
	* swizzles vector to (z,w,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetZWZ();

	/*
	* GetZWW
	*
	* swizzles vector to (z,w,w)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetZWW();

	/*
	* GetWXX
	*
	* swizzles vector to (w,x,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetWXX();

	/*
	* GetWXY
	*
	* swizzles vector to (w,x,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetWXY();

	/*
	* GetWXZ
	*
	* swizzles vector to (w,x,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetWXZ();

	/*
	* GetWXW
	*
	* swizzles vector to (w,x,w)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetWXW();

	/*
	* GetWYX
	*
	* swizzles vector to (w,y,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetWYX();

	/*
	* GetWYY
	*
	* swizzles vector to (w,y,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetWYY();

	/*
	* GetWYZ
	*
	* swizzles vector to (w,y,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetWYZ();

	/*
	* GetWYW
	*
	* swizzles vector to (w,y,w)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetWYW();

	/*
	* GetWZX
	*
	* swizzles vector to (w,z,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetWZX();

	/*
	* GetWZY
	*
	* swizzles vector to (w,z,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetWZY();

	/*
	* GetWZZ
	*
	* swizzles vector to (w,z,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetWZZ();

	/*
	* GetWZW
	*
	* swizzles vector to (w,z,w)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetWZW();

	/*
	* GetWWX
	*
	* swizzles vector to (w,w,x)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetWWX();

	/*
	* GetWWY
	*
	* swizzles vector to (w,w,y)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetWWY();

	/*
	* GetWWZ
	*
	* swizzles vector to (w,w,z)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetWWZ();

	/*
	* GetWWW
	*
	* swizzles vector to (w,w,w)
	*
	* @returns Vector3 - the swizzled vector
	*/
	 Vector3 GetWWW();

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
	* GetXXXW
	*
	* swizzles vector to (x,x,x,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXXXW();

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
	* GetXXYW
	*
	* swizzles vector to (x,x,y,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXXYW();

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
	* GetXXZW
	*
	* swizzles vector to (x,x,z,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXXZW();

	/*
	* GetXXWX
	*
	* swizzles vector to (x,x,w,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXXWX();

	/*
	* GetXXWY
	*
	* swizzles vector to (x,x,w,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXXWY();

	/*
	* GetXXWZ
	*
	* swizzles vector to (x,x,w,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXXWZ();

	/*
	* GetXXWW
	*
	* swizzles vector to (x,x,w,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXXWW();

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
	* GetXYXW
	*
	* swizzles vector to (x,y,x,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXYXW();

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
	* GetXYYW
	*
	* swizzles vector to (x,y,y,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXYYW();

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
	* GetXYWX
	*
	* swizzles vector to (x,y,w,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXYWX();

	/*
	* GetXYWY
	*
	* swizzles vector to (x,y,w,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXYWY();

	/*
	* GetXYWZ
	*
	* swizzles vector to (x,y,w,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXYWZ();

	/*
	* GetXYWW
	*
	* swizzles vector to (x,y,w,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXYWW();

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
	* GetXZXW
	*
	* swizzles vector to (x,z,x,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXZXW();

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
	* GetXZYW
	*
	* swizzles vector to (x,z,y,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXZYW();

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
	* GetXZZW
	*
	* swizzles vector to (x,z,z,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXZZW();

	/*
	* GetXZWX
	*
	* swizzles vector to (x,z,w,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXZWX();

	/*
	* GetXZWY
	*
	* swizzles vector to (x,z,w,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXZWY();

	/*
	* GetXZWZ
	*
	* swizzles vector to (x,z,w,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXZWZ();

	/*
	* GetXZWW
	*
	* swizzles vector to (x,z,w,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXZWW();

	/*
	* GetXWXX
	*
	* swizzles vector to (x,w,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXWXX();

	/*
	* GetXWXY
	*
	* swizzles vector to (x,w,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXWXY();

	/*
	* GetXWXZ
	*
	* swizzles vector to (x,w,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXWXZ();

	/*
	* GetXWXW
	*
	* swizzles vector to (x,w,x,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXWXW();

	/*
	* GetXWYX
	*
	* swizzles vector to (x,w,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXWYX();

	/*
	* GetXWYY
	*
	* swizzles vector to (x,w,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXWYY();

	/*
	* GetXWYZ
	*
	* swizzles vector to (x,w,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXWYZ();

	/*
	* GetXWYW
	*
	* swizzles vector to (x,w,y,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXWYW();

	/*
	* GetXWZX
	*
	* swizzles vector to (x,w,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXWZX();

	/*
	* GetXWZY
	*
	* swizzles vector to (x,w,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXWZY();

	/*
	* GetXWZZ
	*
	* swizzles vector to (x,w,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXWZZ();

	/*
	* GetXWZW
	*
	* swizzles vector to (x,w,z,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXWZW();

	/*
	* GetXWWX
	*
	* swizzles vector to (x,w,w,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXWWX();

	/*
	* GetXWWY
	*
	* swizzles vector to (x,w,w,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXWWY();

	/*
	* GetXWWZ
	*
	* swizzles vector to (x,w,w,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXWWZ();

	/*
	* GetXWWW
	*
	* swizzles vector to (x,w,w,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetXWWW();

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
	* GetYXXW
	*
	* swizzles vector to (y,x,x,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYXXW();

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
	* GetYXYW
	*
	* swizzles vector to (y,x,y,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYXYW();

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
	* GetYXZW
	*
	* swizzles vector to (y,x,z,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYXZW();

	/*
	* GetYXWX
	*
	* swizzles vector to (y,x,w,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYXWX();

	/*
	* GetYXWY
	*
	* swizzles vector to (y,x,w,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYXWY();

	/*
	* GetYXWZ
	*
	* swizzles vector to (y,x,w,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYXWZ();

	/*
	* GetYXWW
	*
	* swizzles vector to (y,x,w,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYXWW();

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
	* GetYYXW
	*
	* swizzles vector to (y,y,x,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYYXW();

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
	* GetYYYW
	*
	* swizzles vector to (y,y,y,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYYYW();

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
	* GetYYZW
	*
	* swizzles vector to (y,y,z,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYYZW();

	/*
	* GetYYWX
	*
	* swizzles vector to (y,y,w,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYYWX();

	/*
	* GetYYWY
	*
	* swizzles vector to (y,y,w,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYYWY();

	/*
	* GetYYWZ
	*
	* swizzles vector to (y,y,w,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYYWZ();

	/*
	* GetYYWW
	*
	* swizzles vector to (y,y,w,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYYWW();

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
	* GetYZXW
	*
	* swizzles vector to (y,z,x,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYZXW();

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
	* GetYZYW
	*
	* swizzles vector to (y,z,y,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYZYW();

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
	* GetYZZW
	*
	* swizzles vector to (y,z,z,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYZZW();

	/*
	* GetYZWX
	*
	* swizzles vector to (y,z,w,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYZWX();

	/*
	* GetYZWY
	*
	* swizzles vector to (y,z,w,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYZWY();

	/*
	* GetYZWZ
	*
	* swizzles vector to (y,z,w,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYZWZ();

	/*
	* GetYZWW
	*
	* swizzles vector to (y,z,w,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYZWW();

	/*
	* GetYWXX
	*
	* swizzles vector to (y,w,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYWXX();

	/*
	* GetYWXY
	*
	* swizzles vector to (y,w,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYWXY();

	/*
	* GetYWXZ
	*
	* swizzles vector to (y,w,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYWXZ();

	/*
	* GetYWXW
	*
	* swizzles vector to (y,w,x,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYWXW();

	/*
	* GetYWYX
	*
	* swizzles vector to (y,w,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYWYX();

	/*
	* GetYWYY
	*
	* swizzles vector to (y,w,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYWYY();

	/*
	* GetYWYZ
	*
	* swizzles vector to (y,w,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYWYZ();

	/*
	* GetYWYW
	*
	* swizzles vector to (y,w,y,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYWYW();

	/*
	* GetYWZX
	*
	* swizzles vector to (y,w,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYWZX();

	/*
	* GetYWZY
	*
	* swizzles vector to (y,w,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYWZY();

	/*
	* GetYWZZ
	*
	* swizzles vector to (y,w,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYWZZ();

	/*
	* GetYWZW
	*
	* swizzles vector to (y,w,z,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYWZW();

	/*
	* GetYWWX
	*
	* swizzles vector to (y,w,w,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYWWX();

	/*
	* GetYWWY
	*
	* swizzles vector to (y,w,w,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYWWY();

	/*
	* GetYWWZ
	*
	* swizzles vector to (y,w,w,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYWWZ();

	/*
	* GetYWWW
	*
	* swizzles vector to (y,w,w,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetYWWW();

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
	* GetZXXW
	*
	* swizzles vector to (z,x,x,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZXXW();

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
	* GetZXYW
	*
	* swizzles vector to (z,x,y,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZXYW();

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
	* GetZXZW
	*
	* swizzles vector to (z,x,z,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZXZW();

	/*
	* GetZXWX
	*
	* swizzles vector to (z,x,w,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZXWX();

	/*
	* GetZXWY
	*
	* swizzles vector to (z,x,w,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZXWY();

	/*
	* GetZXWZ
	*
	* swizzles vector to (z,x,w,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZXWZ();

	/*
	* GetZXWW
	*
	* swizzles vector to (z,x,w,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZXWW();

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
	* GetZYXW
	*
	* swizzles vector to (z,y,x,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZYXW();

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
	* GetZYYW
	*
	* swizzles vector to (z,y,y,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZYYW();

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
	* GetZYZW
	*
	* swizzles vector to (z,y,z,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZYZW();

	/*
	* GetZYWX
	*
	* swizzles vector to (z,y,w,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZYWX();

	/*
	* GetZYWY
	*
	* swizzles vector to (z,y,w,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZYWY();

	/*
	* GetZYWZ
	*
	* swizzles vector to (z,y,w,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZYWZ();

	/*
	* GetZYWW
	*
	* swizzles vector to (z,y,w,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZYWW();

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
	* GetZZXW
	*
	* swizzles vector to (z,z,x,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZZXW();

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
	* GetZZYW
	*
	* swizzles vector to (z,z,y,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZZYW();

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

	/*
	* GetZZZW
	*
	* swizzles vector to (z,z,z,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZZZW();

	/*
	* GetZZWX
	*
	* swizzles vector to (z,z,w,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZZWX();

	/*
	* GetZZWY
	*
	* swizzles vector to (z,z,w,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZZWY();

	/*
	* GetZZWZ
	*
	* swizzles vector to (z,z,w,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZZWZ();

	/*
	* GetZZWW
	*
	* swizzles vector to (z,z,w,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZZWW();

	/*
	* GetZWXX
	*
	* swizzles vector to (z,w,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZWXX();

	/*
	* GetZWXY
	*
	* swizzles vector to (z,w,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZWXY();

	/*
	* GetZWXZ
	*
	* swizzles vector to (z,w,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZWXZ();

	/*
	* GetZWXW
	*
	* swizzles vector to (z,w,x,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZWXW();

	/*
	* GetZWYX
	*
	* swizzles vector to (z,w,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZWYX();

	/*
	* GetZWYY
	*
	* swizzles vector to (z,w,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZWYY();

	/*
	* GetZWYZ
	*
	* swizzles vector to (z,w,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZWYZ();

	/*
	* GetZWYW
	*
	* swizzles vector to (z,w,y,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZWYW();

	/*
	* GetZWZX
	*
	* swizzles vector to (z,w,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZWZX();

	/*
	* GetZWZY
	*
	* swizzles vector to (z,w,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZWZY();

	/*
	* GetZWZZ
	*
	* swizzles vector to (z,w,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZWZZ();

	/*
	* GetZWZW
	*
	* swizzles vector to (z,w,z,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZWZW();

	/*
	* GetZWWX
	*
	* swizzles vector to (z,w,w,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZWWX();

	/*
	* GetZWWY
	*
	* swizzles vector to (z,w,w,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZWWY();

	/*
	* GetZWWZ
	*
	* swizzles vector to (z,w,w,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZWWZ();

	/*
	* GetZWWW
	*
	* swizzles vector to (z,w,w,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetZWWW();

	/*
	* GetWXXX
	*
	* swizzles vector to (w,x,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWXXX();

	/*
	* GetWXXY
	*
	* swizzles vector to (w,x,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWXXY();

	/*
	* GetWXXZ
	*
	* swizzles vector to (w,x,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWXXZ();

	/*
	* GetWXXW
	*
	* swizzles vector to (w,x,x,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWXXW();

	/*
	* GetWXYX
	*
	* swizzles vector to (w,x,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWXYX();

	/*
	* GetWXYY
	*
	* swizzles vector to (w,x,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWXYY();

	/*
	* GetWXYZ
	*
	* swizzles vector to (w,x,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWXYZ();

	/*
	* GetWXYW
	*
	* swizzles vector to (w,x,y,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWXYW();

	/*
	* GetWXZX
	*
	* swizzles vector to (w,x,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWXZX();

	/*
	* GetWXZY
	*
	* swizzles vector to (w,x,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWXZY();

	/*
	* GetWXZZ
	*
	* swizzles vector to (w,x,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWXZZ();

	/*
	* GetWXZW
	*
	* swizzles vector to (w,x,z,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWXZW();

	/*
	* GetWXWX
	*
	* swizzles vector to (w,x,w,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWXWX();

	/*
	* GetWXWY
	*
	* swizzles vector to (w,x,w,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWXWY();

	/*
	* GetWXWZ
	*
	* swizzles vector to (w,x,w,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWXWZ();

	/*
	* GetWXWW
	*
	* swizzles vector to (w,x,w,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWXWW();

	/*
	* GetWYXX
	*
	* swizzles vector to (w,y,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWYXX();

	/*
	* GetWYXY
	*
	* swizzles vector to (w,y,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWYXY();

	/*
	* GetWYXZ
	*
	* swizzles vector to (w,y,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWYXZ();

	/*
	* GetWYXW
	*
	* swizzles vector to (w,y,x,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWYXW();

	/*
	* GetWYYX
	*
	* swizzles vector to (w,y,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWYYX();

	/*
	* GetWYYY
	*
	* swizzles vector to (w,y,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWYYY();

	/*
	* GetWYYZ
	*
	* swizzles vector to (w,y,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWYYZ();

	/*
	* GetWYYW
	*
	* swizzles vector to (w,y,y,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWYYW();

	/*
	* GetWYZX
	*
	* swizzles vector to (w,y,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWYZX();

	/*
	* GetWYZY
	*
	* swizzles vector to (w,y,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWYZY();

	/*
	* GetWYZZ
	*
	* swizzles vector to (w,y,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWYZZ();

	/*
	* GetWYZW
	*
	* swizzles vector to (w,y,z,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWYZW();

	/*
	* GetWYWX
	*
	* swizzles vector to (w,y,w,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWYWX();

	/*
	* GetWYWY
	*
	* swizzles vector to (w,y,w,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWYWY();

	/*
	* GetWYWZ
	*
	* swizzles vector to (w,y,w,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWYWZ();

	/*
	* GetWYWW
	*
	* swizzles vector to (w,y,w,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWYWW();

	/*
	* GetWZXX
	*
	* swizzles vector to (w,z,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWZXX();

	/*
	* GetWZXY
	*
	* swizzles vector to (w,z,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWZXY();

	/*
	* GetWZXZ
	*
	* swizzles vector to (w,z,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWZXZ();

	/*
	* GetWZXW
	*
	* swizzles vector to (w,z,x,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWZXW();

	/*
	* GetWZYX
	*
	* swizzles vector to (w,z,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWZYX();

	/*
	* GetWZYY
	*
	* swizzles vector to (w,z,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWZYY();

	/*
	* GetWZYZ
	*
	* swizzles vector to (w,z,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWZYZ();

	/*
	* GetWZYW
	*
	* swizzles vector to (w,z,y,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWZYW();

	/*
	* GetWZZX
	*
	* swizzles vector to (w,z,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWZZX();

	/*
	* GetWZZY
	*
	* swizzles vector to (w,z,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWZZY();

	/*
	* GetWZZZ
	*
	* swizzles vector to (w,z,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWZZZ();

	/*
	* GetWZZW
	*
	* swizzles vector to (w,z,z,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWZZW();

	/*
	* GetWZWX
	*
	* swizzles vector to (w,z,w,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWZWX();

	/*
	* GetWZWY
	*
	* swizzles vector to (w,z,w,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWZWY();

	/*
	* GetWZWZ
	*
	* swizzles vector to (w,z,w,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWZWZ();

	/*
	* GetWZWW
	*
	* swizzles vector to (w,z,w,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWZWW();

	/*
	* GetWWXX
	*
	* swizzles vector to (w,w,x,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWWXX();

	/*
	* GetWWXY
	*
	* swizzles vector to (w,w,x,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWWXY();

	/*
	* GetWWXZ
	*
	* swizzles vector to (w,w,x,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWWXZ();

	/*
	* GetWWXW
	*
	* swizzles vector to (w,w,x,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWWXW();

	/*
	* GetWWYX
	*
	* swizzles vector to (w,w,y,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWWYX();

	/*
	* GetWWYY
	*
	* swizzles vector to (w,w,y,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWWYY();

	/*
	* GetWWYZ
	*
	* swizzles vector to (w,w,y,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWWYZ();

	/*
	* GetWWYW
	*
	* swizzles vector to (w,w,y,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWWYW();

	/*
	* GetWWZX
	*
	* swizzles vector to (w,w,z,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWWZX();

	/*
	* GetWWZY
	*
	* swizzles vector to (w,w,z,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWWZY();

	/*
	* GetWWZZ
	*
	* swizzles vector to (w,w,z,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWWZZ();

	/*
	* GetWWZW
	*
	* swizzles vector to (w,w,z,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWWZW();

	/*
	* GetWWWX
	*
	* swizzles vector to (w,w,w,x)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWWWX();

	/*
	* GetWWWY
	*
	* swizzles vector to (w,w,w,y)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWWWY();

	/*
	* GetWWWZ
	*
	* swizzles vector to (w,w,w,z)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWWWZ();

	/*
	* GetWWWW
	*
	* swizzles vector to (w,w,w,w)
	*
	* @returns Vector4 - the swizzled vector
	*/
	 Vector4 GetWWWW();


#pragma endregion swizzling

	/*	Vector4 operator+(Vector4 &other);
	*	This function overloads the + operator so that 2 Vector4's can be added together.
	*
	*	parameter 1 &other - a Vector4.
	*	@returns Vector4
	*/
	
	Vector4 operator+(Vector4 &other);

	/*	void Vector4::operator=(Vector2 &other);
	*	This function overloads the = operator so that a Vector4 equal's a vector2.
	*
	*	parameter 1 &other - a Vector2.
	*	@returns void
	*/
	void Vector4::operator=(Vector2 &other);

	/*	void Vector4::operator=(Vector3 &other);
	*	This function overloads the = operator so that a Vector4 equal's a vector3.
	*
	*	parameter 1 &other - a Vector3.
	*	@returns void
	*/
	void Vector4::operator=(Vector3 &other);

	/*	void Vector4::operator+=(const Vector4 &other);
	*	This function overloads the += operator so that a Vector4's can add by itself followed by another Vector4.
	*
	*	parameter 1 &other - a Vector4.
	*	@returns Vector4
	*/
	void Vector4::operator+=(const Vector4 &other);
	// V = V - V (point translated by a vector)
	
	/*	Vector4 operator-(Vector4 &other);
	*	This function overloads the - operator so that 2 Vector4's can be subtracted from each other.
	*
	*	parameter 1 &other - a Vector4.
	*	@returns Vector4
	*/
	Vector4 operator-(Vector4 &other);

	/*	void Vector4::operator-=(const Vector4 &other);
	*	This function overloads the -= operator so that a Vector4's can subtract by itself followed by another Vector4.
	*
	*	parameter 1 &other - a Vector4.
	*	@returns Vector4
	*/
	void Vector4::operator-=(const Vector4 &other);
	
	/*	void Vector4::operator*=(const Vector4 &other);
	*	This function overloads the *= operator so that a Vector4's can multiply by itself followed by another Vector4.
	*
	*	parameter 1 &other - a Vector4.
	*	@returns Vector4
	*/
	void Vector4::operator*=(const Vector4 &other);
	
	//V = V x f (vector scale)
	/*	Vector4 operator*(real scalar);
	*	This function overloads the * operator so that a Vector4 can be multiplied by a real value.
	*
	*	parameter 1 scalar - a 'real' value.
	*	@returns Vector4
	*/
	Vector4 operator*(real scalar);



	//V = f x V (vector scale)
	/*	friend Vector4 operator*(real scalar, Vector4 &other);
	*	This function overloads the * operator so that a Vector4 can be equal to a 'real' value multiplied by a Vector4.
	*
	*	parameter 1 scalar - a 'real' value.
	*	parameter 2 &other - a Vector4.
	*	@returns Vector4
	*/
	friend DLL Vector4 operator*(real scalar, Vector4 &other);

	//f = V.dot(V)
	/*	real dot(Vector4 &other);
	*	This function returns a 'real' value that is based on the dot product of a inputted Vector4.
	*
	*	parameter 1 &other - a Vector4.
	*	@returns 'real'
	*/
	real dot(Vector4 &other);

	//V = V.cross(V)
	/*	Vector4 cross(Vector4 &other);
	*	This function returns a Vector4 that is based on the cross product of a Vector4.
	*
	*	parameter 1 &other - a Vector4.
	*	@returns Vector4
	*/
	Vector4 cross(Vector4 &other);


	//f = V.magnitude()
	/*	real magnitude();
	*	This function returns a 'real' value that is the magnitude of a Vector4.
	*
	*	@returns 'real' (defined in typeDef.h)
	*/
	real magnitude();

	//V.normalised
	/*	Vector4 normalised();
	*	This function returns a Vector4 that has been normalised.
	*
	*
	*	@returns Vector4
	*/
	Vector4 normalised();

	//V.normalise()
	/*	void normalise();
	*	This function normalises a Vector4.
	*
	*
	*	@returns void
	*/
	void normalise();

	real operator[](int n)const;

	real &operator[](int n);


	/* operator Vector2();
	*
	* This function allows a Vector4 to be used as a Vector2.
	*
	* @returns Vector2(x,y)
	*/
	operator Vector2();

	/* operator Vector3();
	*
	* This function allows a Vector4 to be used as a Vector3.
	*
	* @returns Vector3(x,y,z)
	*/
	operator Vector3();

	operator real*() { return &e[0]; };



};
	