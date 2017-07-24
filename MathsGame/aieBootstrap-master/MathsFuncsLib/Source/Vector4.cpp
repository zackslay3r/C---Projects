#include "Vector4.h"
#include <math.h>
#include "Vector3.h"
#include "Vector2.h"

/*
This is the default constructor for a Vector4.
this should return a blank Vector4 with the identity matrix.
*/
Vector4::Vector4()
{
	
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}
/*
This is a different Vector4 constructor, it will create a default 1d array of type "real" with the parameters taken in.
*/
Vector4::Vector4( real newx, real newy, real newz, real neww)
{
	
	x = newx;
	y = newy;
	z = newz;
	w = neww;
}

/* ~Vector4();
* This is the default destructor, it will destroy a Vector3.
* This is called when a the main program has reached the end of its scope.
*/
Vector4::~Vector4()
{
}

#pragma region swizzling
//swizzling
Vector2 Vector4::GetXX()
{
	return Vector2{ x,x };
}

//swizzling
Vector2 Vector4::GetXY()
{
	return Vector2{ x,y };
}

//swizzling
Vector2 Vector4::GetXZ()
{
	return Vector2{ x,z };
}

//swizzling
Vector2 Vector4::GetXW()
{
	return Vector2{ x,w };
}

//swizzling
Vector2 Vector4::GetYX()
{
	return Vector2{ y,x };
}

//swizzling
Vector2 Vector4::GetYY()
{
	return Vector2{ y,y };
}

//swizzling
Vector2 Vector4::GetYZ()
{
	return Vector2{ y,z };
}

//swizzling
Vector2 Vector4::GetYW()
{
	return Vector2{ y,w };
}

//swizzling
Vector2 Vector4::GetZX()
{
	return Vector2{ z,x };
}

//swizzling
Vector2 Vector4::GetZY()
{
	return Vector2{ z,y };
}

//swizzling
Vector2 Vector4::GetZZ()
{
	return Vector2{ z,z };
}

//swizzling
Vector2 Vector4::GetZW()
{
	return Vector2{ z,w };
}

//swizzling
Vector2 Vector4::GetWX()
{
	return Vector2{ w,x };
}

//swizzling
Vector2 Vector4::GetWY()
{
	return Vector2{ w,y };
}

//swizzling
Vector2 Vector4::GetWZ()
{
	return Vector2{ w,z };
}

//swizzling
Vector2 Vector4::GetWW()
{
	return Vector2{ w,w };
}

//swizzling
Vector3 Vector4::GetXXX()
{
	return Vector3{ x,x,x };
}

//swizzling
Vector3 Vector4::GetXXY()
{
	return Vector3{ x,x,y };
}

//swizzling
Vector3 Vector4::GetXXZ()
{
	return Vector3{ x,x,z };
}

//swizzling
Vector3 Vector4::GetXXW()
{
	return Vector3{ x,x,w };
}

//swizzling
Vector3 Vector4::GetXYX()
{
	return Vector3{ x,y,x };
}

//swizzling
Vector3 Vector4::GetXYY()
{
	return Vector3{ x,y,y };
}

//swizzling
Vector3 Vector4::GetXYZ()
{
	return Vector3{ x,y,z };
}

//swizzling
Vector3 Vector4::GetXYW()
{
	return Vector3{ x,y,w };
}

//swizzling
Vector3 Vector4::GetXZX()
{
	return Vector3{ x,z,x };
}

//swizzling
Vector3 Vector4::GetXZY()
{
	return Vector3{ x,z,y };
}

//swizzling
Vector3 Vector4::GetXZZ()
{
	return Vector3{ x,z,z };
}

//swizzling
Vector3 Vector4::GetXZW()
{
	return Vector3{ x,z,w };
}

//swizzling
Vector3 Vector4::GetXWX()
{
	return Vector3{ x,w,x };
}

//swizzling
Vector3 Vector4::GetXWY()
{
	return Vector3{ x,w,y };
}

//swizzling
Vector3 Vector4::GetXWZ()
{
	return Vector3{ x,w,z };
}

//swizzling
Vector3 Vector4::GetXWW()
{
	return Vector3{ x,w,w };
}

//swizzling
Vector3 Vector4::GetYXX()
{
	return Vector3{ y,x,x };
}

//swizzling
Vector3 Vector4::GetYXY()
{
	return Vector3{ y,x,y };
}

//swizzling
Vector3 Vector4::GetYXZ()
{
	return Vector3{ y,x,z };
}

//swizzling
Vector3 Vector4::GetYXW()
{
	return Vector3{ y,x,w };
}

//swizzling
Vector3 Vector4::GetYYX()
{
	return Vector3{ y,y,x };
}

//swizzling
Vector3 Vector4::GetYYY()
{
	return Vector3{ y,y,y };
}

//swizzling
Vector3 Vector4::GetYYZ()
{
	return Vector3{ y,y,z };
}

//swizzling
Vector3 Vector4::GetYYW()
{
	return Vector3{ y,y,w };
}

//swizzling
Vector3 Vector4::GetYZX()
{
	return Vector3{ y,z,x };
}

//swizzling
Vector3 Vector4::GetYZY()
{
	return Vector3{ y,z,y };
}

//swizzling
Vector3 Vector4::GetYZZ()
{
	return Vector3{ y,z,z };
}

//swizzling
Vector3 Vector4::GetYZW()
{
	return Vector3{ y,z,w };
}

//swizzling
Vector3 Vector4::GetYWX()
{
	return Vector3{ y,w,x };
}

//swizzling
Vector3 Vector4::GetYWY()
{
	return Vector3{ y,w,y };
}

//swizzling
Vector3 Vector4::GetYWZ()
{
	return Vector3{ y,w,z };
}

//swizzling
Vector3 Vector4::GetYWW()
{
	return Vector3{ y,w,w };
}

//swizzling
Vector3 Vector4::GetZXX()
{
	return Vector3{ z,x,x };
}

//swizzling
Vector3 Vector4::GetZXY()
{
	return Vector3{ z,x,y };
}

//swizzling
Vector3 Vector4::GetZXZ()
{
	return Vector3{ z,x,z };
}

//swizzling
Vector3 Vector4::GetZXW()
{
	return Vector3{ z,x,w };
}

//swizzling
Vector3 Vector4::GetZYX()
{
	return Vector3{ z,y,x };
}

//swizzling
Vector3 Vector4::GetZYY()
{
	return Vector3{ z,y,y };
}

//swizzling
Vector3 Vector4::GetZYZ()
{
	return Vector3{ z,y,z };
}

//swizzling
Vector3 Vector4::GetZYW()
{
	return Vector3{ z,y,w };
}

//swizzling
Vector3 Vector4::GetZZX()
{
	return Vector3{ z,z,x };
}

//swizzling
Vector3 Vector4::GetZZY()
{
	return Vector3{ z,z,y };
}

//swizzling
Vector3 Vector4::GetZZZ()
{
	return Vector3{ z,z,z };
}

//swizzling
Vector3 Vector4::GetZZW()
{
	return Vector3{ z,z,w };
}

//swizzling
Vector3 Vector4::GetZWX()
{
	return Vector3{ z,w,x };
}

//swizzling
Vector3 Vector4::GetZWY()
{
	return Vector3{ z,w,y };
}

//swizzling
Vector3 Vector4::GetZWZ()
{
	return Vector3{ z,w,z };
}

//swizzling
Vector3 Vector4::GetZWW()
{
	return Vector3{ z,w,w };
}

//swizzling
Vector3 Vector4::GetWXX()
{
	return Vector3{ w,x,x };
}

//swizzling
Vector3 Vector4::GetWXY()
{
	return Vector3{ w,x,y };
}

//swizzling
Vector3 Vector4::GetWXZ()
{
	return Vector3{ w,x,z };
}

//swizzling
Vector3 Vector4::GetWXW()
{
	return Vector3{ w,x,w };
}

//swizzling
Vector3 Vector4::GetWYX()
{
	return Vector3{ w,y,x };
}

//swizzling
Vector3 Vector4::GetWYY()
{
	return Vector3{ w,y,y };
}

//swizzling
Vector3 Vector4::GetWYZ()
{
	return Vector3{ w,y,z };
}

//swizzling
Vector3 Vector4::GetWYW()
{
	return Vector3{ w,y,w };
}

//swizzling
Vector3 Vector4::GetWZX()
{
	return Vector3{ w,z,x };
}

//swizzling
Vector3 Vector4::GetWZY()
{
	return Vector3{ w,z,y };
}

//swizzling
Vector3 Vector4::GetWZZ()
{
	return Vector3{ w,z,z };
}

//swizzling
Vector3 Vector4::GetWZW()
{
	return Vector3{ w,z,w };
}

//swizzling
Vector3 Vector4::GetWWX()
{
	return Vector3{ w,w,x };
}

//swizzling
Vector3 Vector4::GetWWY()
{
	return Vector3{ w,w,y };
}

//swizzling
Vector3 Vector4::GetWWZ()
{
	return Vector3{ w,w,z };
}

//swizzling
Vector3 Vector4::GetWWW()
{
	return Vector3{ w,w,w };
}

//swizzling
Vector4 Vector4::GetXXXX()
{
	return Vector4{ x,x,x,x };
}

//swizzling
Vector4 Vector4::GetXXXY()
{
	return Vector4{ x,x,x,y };
}

//swizzling
Vector4 Vector4::GetXXXZ()
{
	return Vector4{ x,x,x,z };
}

//swizzling
Vector4 Vector4::GetXXXW()
{
	return Vector4{ x,x,x,w };
}

//swizzling
Vector4 Vector4::GetXXYX()
{
	return Vector4{ x,x,y,x };
}

//swizzling
Vector4 Vector4::GetXXYY()
{
	return Vector4{ x,x,y,y };
}

//swizzling
Vector4 Vector4::GetXXYZ()
{
	return Vector4{ x,x,y,z };
}

//swizzling
Vector4 Vector4::GetXXYW()
{
	return Vector4{ x,x,y,w };
}

//swizzling
Vector4 Vector4::GetXXZX()
{
	return Vector4{ x,x,z,x };
}

//swizzling
Vector4 Vector4::GetXXZY()
{
	return Vector4{ x,x,z,y };
}

//swizzling
Vector4 Vector4::GetXXZZ()
{
	return Vector4{ x,x,z,z };
}

//swizzling
Vector4 Vector4::GetXXZW()
{
	return Vector4{ x,x,z,w };
}

//swizzling
Vector4 Vector4::GetXXWX()
{
	return Vector4{ x,x,w,x };
}

//swizzling
Vector4 Vector4::GetXXWY()
{
	return Vector4{ x,x,w,y };
}

//swizzling
Vector4 Vector4::GetXXWZ()
{
	return Vector4{ x,x,w,z };
}

//swizzling
Vector4 Vector4::GetXXWW()
{
	return Vector4{ x,x,w,w };
}

//swizzling
Vector4 Vector4::GetXYXX()
{
	return Vector4{ x,y,x,x };
}

//swizzling
Vector4 Vector4::GetXYXY()
{
	return Vector4{ x,y,x,y };
}

//swizzling
Vector4 Vector4::GetXYXZ()
{
	return Vector4{ x,y,x,z };
}

//swizzling
Vector4 Vector4::GetXYXW()
{
	return Vector4{ x,y,x,w };
}

//swizzling
Vector4 Vector4::GetXYYX()
{
	return Vector4{ x,y,y,x };
}

//swizzling
Vector4 Vector4::GetXYYY()
{
	return Vector4{ x,y,y,y };
}

//swizzling
Vector4 Vector4::GetXYYZ()
{
	return Vector4{ x,y,y,z };
}

//swizzling
Vector4 Vector4::GetXYYW()
{
	return Vector4{ x,y,y,w };
}

//swizzling
Vector4 Vector4::GetXYZX()
{
	return Vector4{ x,y,z,x };
}

//swizzling
Vector4 Vector4::GetXYZY()
{
	return Vector4{ x,y,z,y };
}

//swizzling
Vector4 Vector4::GetXYZZ()
{
	return Vector4{ x,y,z,z };
}

//swizzling
Vector4 Vector4::GetXYWX()
{
	return Vector4{ x,y,w,x };
}

//swizzling
Vector4 Vector4::GetXYWY()
{
	return Vector4{ x,y,w,y };
}

//swizzling
Vector4 Vector4::GetXYWZ()
{
	return Vector4{ x,y,w,z };
}

//swizzling
Vector4 Vector4::GetXYWW()
{
	return Vector4{ x,y,w,w };
}

//swizzling
Vector4 Vector4::GetXZXX()
{
	return Vector4{ x,z,x,x };
}

//swizzling
Vector4 Vector4::GetXZXY()
{
	return Vector4{ x,z,x,y };
}

//swizzling
Vector4 Vector4::GetXZXZ()
{
	return Vector4{ x,z,x,z };
}

//swizzling
Vector4 Vector4::GetXZXW()
{
	return Vector4{ x,z,x,w };
}

//swizzling
Vector4 Vector4::GetXZYX()
{
	return Vector4{ x,z,y,x };
}

//swizzling
Vector4 Vector4::GetXZYY()
{
	return Vector4{ x,z,y,y };
}

//swizzling
Vector4 Vector4::GetXZYZ()
{
	return Vector4{ x,z,y,z };
}

//swizzling
Vector4 Vector4::GetXZYW()
{
	return Vector4{ x,z,y,w };
}

//swizzling
Vector4 Vector4::GetXZZX()
{
	return Vector4{ x,z,z,x };
}

//swizzling
Vector4 Vector4::GetXZZY()
{
	return Vector4{ x,z,z,y };
}

//swizzling
Vector4 Vector4::GetXZZZ()
{
	return Vector4{ x,z,z,z };
}

//swizzling
Vector4 Vector4::GetXZZW()
{
	return Vector4{ x,z,z,w };
}

//swizzling
Vector4 Vector4::GetXZWX()
{
	return Vector4{ x,z,w,x };
}

//swizzling
Vector4 Vector4::GetXZWY()
{
	return Vector4{ x,z,w,y };
}

//swizzling
Vector4 Vector4::GetXZWZ()
{
	return Vector4{ x,z,w,z };
}

//swizzling
Vector4 Vector4::GetXZWW()
{
	return Vector4{ x,z,w,w };
}

//swizzling
Vector4 Vector4::GetXWXX()
{
	return Vector4{ x,w,x,x };
}

//swizzling
Vector4 Vector4::GetXWXY()
{
	return Vector4{ x,w,x,y };
}

//swizzling
Vector4 Vector4::GetXWXZ()
{
	return Vector4{ x,w,x,z };
}

//swizzling
Vector4 Vector4::GetXWXW()
{
	return Vector4{ x,w,x,w };
}

//swizzling
Vector4 Vector4::GetXWYX()
{
	return Vector4{ x,w,y,x };
}

//swizzling
Vector4 Vector4::GetXWYY()
{
	return Vector4{ x,w,y,y };
}

//swizzling
Vector4 Vector4::GetXWYZ()
{
	return Vector4{ x,w,y,z };
}

//swizzling
Vector4 Vector4::GetXWYW()
{
	return Vector4{ x,w,y,w };
}

//swizzling
Vector4 Vector4::GetXWZX()
{
	return Vector4{ x,w,z,x };
}

//swizzling
Vector4 Vector4::GetXWZY()
{
	return Vector4{ x,w,z,y };
}

//swizzling
Vector4 Vector4::GetXWZZ()
{
	return Vector4{ x,w,z,z };
}

//swizzling
Vector4 Vector4::GetXWZW()
{
	return Vector4{ x,w,z,w };
}

//swizzling
Vector4 Vector4::GetXWWX()
{
	return Vector4{ x,w,w,x };
}

//swizzling
Vector4 Vector4::GetXWWY()
{
	return Vector4{ x,w,w,y };
}

//swizzling
Vector4 Vector4::GetXWWZ()
{
	return Vector4{ x,w,w,z };
}

//swizzling
Vector4 Vector4::GetXWWW()
{
	return Vector4{ x,w,w,w };
}

//swizzling
Vector4 Vector4::GetYXXX()
{
	return Vector4{ y,x,x,x };
}

//swizzling
Vector4 Vector4::GetYXXY()
{
	return Vector4{ y,x,x,y };
}

//swizzling
Vector4 Vector4::GetYXXZ()
{
	return Vector4{ y,x,x,z };
}

//swizzling
Vector4 Vector4::GetYXXW()
{
	return Vector4{ y,x,x,w };
}

//swizzling
Vector4 Vector4::GetYXYX()
{
	return Vector4{ y,x,y,x };
}

//swizzling
Vector4 Vector4::GetYXYY()
{
	return Vector4{ y,x,y,y };
}

//swizzling
Vector4 Vector4::GetYXYZ()
{
	return Vector4{ y,x,y,z };
}

//swizzling
Vector4 Vector4::GetYXYW()
{
	return Vector4{ y,x,y,w };
}

//swizzling
Vector4 Vector4::GetYXZX()
{
	return Vector4{ y,x,z,x };
}

//swizzling
Vector4 Vector4::GetYXZY()
{
	return Vector4{ y,x,z,y };
}

//swizzling
Vector4 Vector4::GetYXZZ()
{
	return Vector4{ y,x,z,z };
}

//swizzling
Vector4 Vector4::GetYXZW()
{
	return Vector4{ y,x,z,w };
}

//swizzling
Vector4 Vector4::GetYXWX()
{
	return Vector4{ y,x,w,x };
}

//swizzling
Vector4 Vector4::GetYXWY()
{
	return Vector4{ y,x,w,y };
}

//swizzling
Vector4 Vector4::GetYXWZ()
{
	return Vector4{ y,x,w,z };
}

//swizzling
Vector4 Vector4::GetYXWW()
{
	return Vector4{ y,x,w,w };
}

//swizzling
Vector4 Vector4::GetYYXX()
{
	return Vector4{ y,y,x,x };
}

//swizzling
Vector4 Vector4::GetYYXY()
{
	return Vector4{ y,y,x,y };
}

//swizzling
Vector4 Vector4::GetYYXZ()
{
	return Vector4{ y,y,x,z };
}

//swizzling
Vector4 Vector4::GetYYXW()
{
	return Vector4{ y,y,x,w };
}

//swizzling
Vector4 Vector4::GetYYYX()
{
	return Vector4{ y,y,y,x };
}

//swizzling
Vector4 Vector4::GetYYYY()
{
	return Vector4{ y,y,y,y };
}

//swizzling
Vector4 Vector4::GetYYYZ()
{
	return Vector4{ y,y,y,z };
}

//swizzling
Vector4 Vector4::GetYYYW()
{
	return Vector4{ y,y,y,w };
}

//swizzling
Vector4 Vector4::GetYYZX()
{
	return Vector4{ y,y,z,x };
}

//swizzling
Vector4 Vector4::GetYYZY()
{
	return Vector4{ y,y,z,y };
}

//swizzling
Vector4 Vector4::GetYYZZ()
{
	return Vector4{ y,y,z,z };
}

//swizzling
Vector4 Vector4::GetYYZW()
{
	return Vector4{ y,y,z,w };
}

//swizzling
Vector4 Vector4::GetYYWX()
{
	return Vector4{ y,y,w,x };
}

//swizzling
Vector4 Vector4::GetYYWY()
{
	return Vector4{ y,y,w,y };
}

//swizzling
Vector4 Vector4::GetYYWZ()
{
	return Vector4{ y,y,w,z };
}

//swizzling
Vector4 Vector4::GetYYWW()
{
	return Vector4{ y,y,w,w };
}

//swizzling
Vector4 Vector4::GetYZXX()
{
	return Vector4{ y,z,x,x };
}

//swizzling
Vector4 Vector4::GetYZXY()
{
	return Vector4{ y,z,x,y };
}

//swizzling
Vector4 Vector4::GetYZXZ()
{
	return Vector4{ y,z,x,z };
}

//swizzling
Vector4 Vector4::GetYZXW()
{
	return Vector4{ y,z,x,w };
}

//swizzling
Vector4 Vector4::GetYZYX()
{
	return Vector4{ y,z,y,x };
}

//swizzling
Vector4 Vector4::GetYZYY()
{
	return Vector4{ y,z,y,y };
}

//swizzling
Vector4 Vector4::GetYZYZ()
{
	return Vector4{ y,z,y,z };
}

//swizzling
Vector4 Vector4::GetYZYW()
{
	return Vector4{ y,z,y,w };
}

//swizzling
Vector4 Vector4::GetYZZX()
{
	return Vector4{ y,z,z,x };
}

//swizzling
Vector4 Vector4::GetYZZY()
{
	return Vector4{ y,z,z,y };
}

//swizzling
Vector4 Vector4::GetYZZZ()
{
	return Vector4{ y,z,z,z };
}

//swizzling
Vector4 Vector4::GetYZZW()
{
	return Vector4{ y,z,z,w };
}

//swizzling
Vector4 Vector4::GetYZWX()
{
	return Vector4{ y,z,w,x };
}

//swizzling
Vector4 Vector4::GetYZWY()
{
	return Vector4{ y,z,w,y };
}

//swizzling
Vector4 Vector4::GetYZWZ()
{
	return Vector4{ y,z,w,z };
}

//swizzling
Vector4 Vector4::GetYZWW()
{
	return Vector4{ y,z,w,w };
}

//swizzling
Vector4 Vector4::GetYWXX()
{
	return Vector4{ y,w,x,x };
}

//swizzling
Vector4 Vector4::GetYWXY()
{
	return Vector4{ y,w,x,y };
}

//swizzling
Vector4 Vector4::GetYWXZ()
{
	return Vector4{ y,w,x,z };
}

//swizzling
Vector4 Vector4::GetYWXW()
{
	return Vector4{ y,w,x,w };
}

//swizzling
Vector4 Vector4::GetYWYX()
{
	return Vector4{ y,w,y,x };
}

//swizzling
Vector4 Vector4::GetYWYY()
{
	return Vector4{ y,w,y,y };
}

//swizzling
Vector4 Vector4::GetYWYZ()
{
	return Vector4{ y,w,y,z };
}

//swizzling
Vector4 Vector4::GetYWYW()
{
	return Vector4{ y,w,y,w };
}

//swizzling
Vector4 Vector4::GetYWZX()
{
	return Vector4{ y,w,z,x };
}

//swizzling
Vector4 Vector4::GetYWZY()
{
	return Vector4{ y,w,z,y };
}

//swizzling
Vector4 Vector4::GetYWZZ()
{
	return Vector4{ y,w,z,z };
}

//swizzling
Vector4 Vector4::GetYWZW()
{
	return Vector4{ y,w,z,w };
}

//swizzling
Vector4 Vector4::GetYWWX()
{
	return Vector4{ y,w,w,x };
}

//swizzling
Vector4 Vector4::GetYWWY()
{
	return Vector4{ y,w,w,y };
}

//swizzling
Vector4 Vector4::GetYWWZ()
{
	return Vector4{ y,w,w,z };
}

//swizzling
Vector4 Vector4::GetYWWW()
{
	return Vector4{ y,w,w,w };
}

//swizzling
Vector4 Vector4::GetZXXX()
{
	return Vector4{ z,x,x,x };
}

//swizzling
Vector4 Vector4::GetZXXY()
{
	return Vector4{ z,x,x,y };
}

//swizzling
Vector4 Vector4::GetZXXZ()
{
	return Vector4{ z,x,x,z };
}

//swizzling
Vector4 Vector4::GetZXXW()
{
	return Vector4{ z,x,x,w };
}

//swizzling
Vector4 Vector4::GetZXYX()
{
	return Vector4{ z,x,y,x };
}

//swizzling
Vector4 Vector4::GetZXYY()
{
	return Vector4{ z,x,y,y };
}

//swizzling
Vector4 Vector4::GetZXYZ()
{
	return Vector4{ z,x,y,z };
}

//swizzling
Vector4 Vector4::GetZXYW()
{
	return Vector4{ z,x,y,w };
}

//swizzling
Vector4 Vector4::GetZXZX()
{
	return Vector4{ z,x,z,x };
}

//swizzling
Vector4 Vector4::GetZXZY()
{
	return Vector4{ z,x,z,y };
}

//swizzling
Vector4 Vector4::GetZXZZ()
{
	return Vector4{ z,x,z,z };
}

//swizzling
Vector4 Vector4::GetZXZW()
{
	return Vector4{ z,x,z,w };
}

//swizzling
Vector4 Vector4::GetZXWX()
{
	return Vector4{ z,x,w,x };
}

//swizzling
Vector4 Vector4::GetZXWY()
{
	return Vector4{ z,x,w,y };
}

//swizzling
Vector4 Vector4::GetZXWZ()
{
	return Vector4{ z,x,w,z };
}

//swizzling
Vector4 Vector4::GetZXWW()
{
	return Vector4{ z,x,w,w };
}

//swizzling
Vector4 Vector4::GetZYXX()
{
	return Vector4{ z,y,x,x };
}

//swizzling
Vector4 Vector4::GetZYXY()
{
	return Vector4{ z,y,x,y };
}

//swizzling
Vector4 Vector4::GetZYXZ()
{
	return Vector4{ z,y,x,z };
}

//swizzling
Vector4 Vector4::GetZYXW()
{
	return Vector4{ z,y,x,w };
}

//swizzling
Vector4 Vector4::GetZYYX()
{
	return Vector4{ z,y,y,x };
}

//swizzling
Vector4 Vector4::GetZYYY()
{
	return Vector4{ z,y,y,y };
}

//swizzling
Vector4 Vector4::GetZYYZ()
{
	return Vector4{ z,y,y,z };
}

//swizzling
Vector4 Vector4::GetZYYW()
{
	return Vector4{ z,y,y,w };
}

//swizzling
Vector4 Vector4::GetZYZX()
{
	return Vector4{ z,y,z,x };
}

//swizzling
Vector4 Vector4::GetZYZY()
{
	return Vector4{ z,y,z,y };
}

//swizzling
Vector4 Vector4::GetZYZZ()
{
	return Vector4{ z,y,z,z };
}

//swizzling
Vector4 Vector4::GetZYZW()
{
	return Vector4{ z,y,z,w };
}

//swizzling
Vector4 Vector4::GetZYWX()
{
	return Vector4{ z,y,w,x };
}

//swizzling
Vector4 Vector4::GetZYWY()
{
	return Vector4{ z,y,w,y };
}

//swizzling
Vector4 Vector4::GetZYWZ()
{
	return Vector4{ z,y,w,z };
}

//swizzling
Vector4 Vector4::GetZYWW()
{
	return Vector4{ z,y,w,w };
}

//swizzling
Vector4 Vector4::GetZZXX()
{
	return Vector4{ z,z,x,x };
}

//swizzling
Vector4 Vector4::GetZZXY()
{
	return Vector4{ z,z,x,y };
}

//swizzling
Vector4 Vector4::GetZZXZ()
{
	return Vector4{ z,z,x,z };
}

//swizzling
Vector4 Vector4::GetZZXW()
{
	return Vector4{ z,z,x,w };
}

//swizzling
Vector4 Vector4::GetZZYX()
{
	return Vector4{ z,z,y,x };
}

//swizzling
Vector4 Vector4::GetZZYY()
{
	return Vector4{ z,z,y,y };
}

//swizzling
Vector4 Vector4::GetZZYZ()
{
	return Vector4{ z,z,y,z };
}

//swizzling
Vector4 Vector4::GetZZYW()
{
	return Vector4{ z,z,y,w };
}

//swizzling
Vector4 Vector4::GetZZZX()
{
	return Vector4{ z,z,z,x };
}

//swizzling
Vector4 Vector4::GetZZZY()
{
	return Vector4{ z,z,z,y };
}

//swizzling
Vector4 Vector4::GetZZZZ()
{
	return Vector4{ z,z,z,z };
}

//swizzling
Vector4 Vector4::GetZZZW()
{
	return Vector4{ z,z,z,w };
}

//swizzling
Vector4 Vector4::GetZZWX()
{
	return Vector4{ z,z,w,x };
}

//swizzling
Vector4 Vector4::GetZZWY()
{
	return Vector4{ z,z,w,y };
}

//swizzling
Vector4 Vector4::GetZZWZ()
{
	return Vector4{ z,z,w,z };
}

//swizzling
Vector4 Vector4::GetZZWW()
{
	return Vector4{ z,z,w,w };
}

//swizzling
Vector4 Vector4::GetZWXX()
{
	return Vector4{ z,w,x,x };
}

//swizzling
Vector4 Vector4::GetZWXY()
{
	return Vector4{ z,w,x,y };
}

//swizzling
Vector4 Vector4::GetZWXZ()
{
	return Vector4{ z,w,x,z };
}

//swizzling
Vector4 Vector4::GetZWXW()
{
	return Vector4{ z,w,x,w };
}

//swizzling
Vector4 Vector4::GetZWYX()
{
	return Vector4{ z,w,y,x };
}

//swizzling
Vector4 Vector4::GetZWYY()
{
	return Vector4{ z,w,y,y };
}

//swizzling
Vector4 Vector4::GetZWYZ()
{
	return Vector4{ z,w,y,z };
}

//swizzling
Vector4 Vector4::GetZWYW()
{
	return Vector4{ z,w,y,w };
}

//swizzling
Vector4 Vector4::GetZWZX()
{
	return Vector4{ z,w,z,x };
}

//swizzling
Vector4 Vector4::GetZWZY()
{
	return Vector4{ z,w,z,y };
}

//swizzling
Vector4 Vector4::GetZWZZ()
{
	return Vector4{ z,w,z,z };
}

//swizzling
Vector4 Vector4::GetZWZW()
{
	return Vector4{ z,w,z,w };
}

//swizzling
Vector4 Vector4::GetZWWX()
{
	return Vector4{ z,w,w,x };
}

//swizzling
Vector4 Vector4::GetZWWY()
{
	return Vector4{ z,w,w,y };
}

//swizzling
Vector4 Vector4::GetZWWZ()
{
	return Vector4{ z,w,w,z };
}

//swizzling
Vector4 Vector4::GetZWWW()
{
	return Vector4{ z,w,w,w };
}

//swizzling
Vector4 Vector4::GetWXXX()
{
	return Vector4{ w,x,x,x };
}

//swizzling
Vector4 Vector4::GetWXXY()
{
	return Vector4{ w,x,x,y };
}

//swizzling
Vector4 Vector4::GetWXXZ()
{
	return Vector4{ w,x,x,z };
}

//swizzling
Vector4 Vector4::GetWXXW()
{
	return Vector4{ w,x,x,w };
}

//swizzling
Vector4 Vector4::GetWXYX()
{
	return Vector4{ w,x,y,x };
}

//swizzling
Vector4 Vector4::GetWXYY()
{
	return Vector4{ w,x,y,y };
}

//swizzling
Vector4 Vector4::GetWXYZ()
{
	return Vector4{ w,x,y,z };
}

//swizzling
Vector4 Vector4::GetWXYW()
{
	return Vector4{ w,x,y,w };
}

//swizzling
Vector4 Vector4::GetWXZX()
{
	return Vector4{ w,x,z,x };
}

//swizzling
Vector4 Vector4::GetWXZY()
{
	return Vector4{ w,x,z,y };
}

//swizzling
Vector4 Vector4::GetWXZZ()
{
	return Vector4{ w,x,z,z };
}

//swizzling
Vector4 Vector4::GetWXZW()
{
	return Vector4{ w,x,z,w };
}

//swizzling
Vector4 Vector4::GetWXWX()
{
	return Vector4{ w,x,w,x };
}

//swizzling
Vector4 Vector4::GetWXWY()
{
	return Vector4{ w,x,w,y };
}

//swizzling
Vector4 Vector4::GetWXWZ()
{
	return Vector4{ w,x,w,z };
}

//swizzling
Vector4 Vector4::GetWXWW()
{
	return Vector4{ w,x,w,w };
}

//swizzling
Vector4 Vector4::GetWYXX()
{
	return Vector4{ w,y,x,x };
}

//swizzling
Vector4 Vector4::GetWYXY()
{
	return Vector4{ w,y,x,y };
}

//swizzling
Vector4 Vector4::GetWYXZ()
{
	return Vector4{ w,y,x,z };
}

//swizzling
Vector4 Vector4::GetWYXW()
{
	return Vector4{ w,y,x,w };
}

//swizzling
Vector4 Vector4::GetWYYX()
{
	return Vector4{ w,y,y,x };
}

//swizzling
Vector4 Vector4::GetWYYY()
{
	return Vector4{ w,y,y,y };
}

//swizzling
Vector4 Vector4::GetWYYZ()
{
	return Vector4{ w,y,y,z };
}

//swizzling
Vector4 Vector4::GetWYYW()
{
	return Vector4{ w,y,y,w };
}

//swizzling
Vector4 Vector4::GetWYZX()
{
	return Vector4{ w,y,z,x };
}

//swizzling
Vector4 Vector4::GetWYZY()
{
	return Vector4{ w,y,z,y };
}

//swizzling
Vector4 Vector4::GetWYZZ()
{
	return Vector4{ w,y,z,z };
}

//swizzling
Vector4 Vector4::GetWYZW()
{
	return Vector4{ w,y,z,w };
}

//swizzling
Vector4 Vector4::GetWYWX()
{
	return Vector4{ w,y,w,x };
}

//swizzling
Vector4 Vector4::GetWYWY()
{
	return Vector4{ w,y,w,y };
}

//swizzling
Vector4 Vector4::GetWYWZ()
{
	return Vector4{ w,y,w,z };
}

//swizzling
Vector4 Vector4::GetWYWW()
{
	return Vector4{ w,y,w,w };
}

//swizzling
Vector4 Vector4::GetWZXX()
{
	return Vector4{ w,z,x,x };
}

//swizzling
Vector4 Vector4::GetWZXY()
{
	return Vector4{ w,z,x,y };
}

//swizzling
Vector4 Vector4::GetWZXZ()
{
	return Vector4{ w,z,x,z };
}

//swizzling
Vector4 Vector4::GetWZXW()
{
	return Vector4{ w,z,x,w };
}

//swizzling
Vector4 Vector4::GetWZYX()
{
	return Vector4{ w,z,y,x };
}

//swizzling
Vector4 Vector4::GetWZYY()
{
	return Vector4{ w,z,y,y };
}

//swizzling
Vector4 Vector4::GetWZYZ()
{
	return Vector4{ w,z,y,z };
}

//swizzling
Vector4 Vector4::GetWZYW()
{
	return Vector4{ w,z,y,w };
}

//swizzling
Vector4 Vector4::GetWZZX()
{
	return Vector4{ w,z,z,x };
}

//swizzling
Vector4 Vector4::GetWZZY()
{
	return Vector4{ w,z,z,y };
}

//swizzling
Vector4 Vector4::GetWZZZ()
{
	return Vector4{ w,z,z,z };
}

//swizzling
Vector4 Vector4::GetWZZW()
{
	return Vector4{ w,z,z,w };
}

//swizzling
Vector4 Vector4::GetWZWX()
{
	return Vector4{ w,z,w,x };
}

//swizzling
Vector4 Vector4::GetWZWY()
{
	return Vector4{ w,z,w,y };
}

//swizzling
Vector4 Vector4::GetWZWZ()
{
	return Vector4{ w,z,w,z };
}

//swizzling
Vector4 Vector4::GetWZWW()
{
	return Vector4{ w,z,w,w };
}

//swizzling
Vector4 Vector4::GetWWXX()
{
	return Vector4{ w,w,x,x };
}

//swizzling
Vector4 Vector4::GetWWXY()
{
	return Vector4{ w,w,x,y };
}

//swizzling
Vector4 Vector4::GetWWXZ()
{
	return Vector4{ w,w,x,z };
}

//swizzling
Vector4 Vector4::GetWWXW()
{
	return Vector4{ w,w,x,w };
}

//swizzling
Vector4 Vector4::GetWWYX()
{
	return Vector4{ w,w,y,x };
}

//swizzling
Vector4 Vector4::GetWWYY()
{
	return Vector4{ w,w,y,y };
}

//swizzling
Vector4 Vector4::GetWWYZ()
{
	return Vector4{ w,w,y,z };
}

//swizzling
Vector4 Vector4::GetWWYW()
{
	return Vector4{ w,w,y,w };
}

//swizzling
Vector4 Vector4::GetWWZX()
{
	return Vector4{ w,w,z,x };
}

//swizzling
Vector4 Vector4::GetWWZY()
{
	return Vector4{ w,w,z,y };
}

//swizzling
Vector4 Vector4::GetWWZZ()
{
	return Vector4{ w,w,z,z };
}

//swizzling
Vector4 Vector4::GetWWZW()
{
	return Vector4{ w,w,z,w };
}

//swizzling
Vector4 Vector4::GetWWWX()
{
	return Vector4{ w,w,w,x };
}

//swizzling
Vector4 Vector4::GetWWWY()
{
	return Vector4{ w,w,w,y };
}

//swizzling
Vector4 Vector4::GetWWWZ()
{
	return Vector4{ w,w,w,z };
}

//swizzling
Vector4 Vector4::GetWWWW()
{
	return Vector4{ w,w,w,w };
}



#pragma endregion swizzling

//This allows two Vector4's to be added together
Vector4 Vector4::operator+(Vector4 & other)
{
	return Vector4( x + other.x, y + other.y, z + other.z, w + other.w);
}

//This lets a Vector4 equal a Vector2
void Vector4::operator=(Vector2 & other)
{
	x = other.x;
	y = other.y;
	z = 0;
	w = 0;
}
//This lets a Vector4 equal a Vector3
void Vector4::operator=(Vector3 & other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	w = 0;
}

//This allows a Vector4 to be added to itself plus another Vector4
void Vector4::operator+=(const Vector4 & other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
}
//This allows a Vector4 to be subtracted by another Vector4
Vector4 Vector4::operator-(Vector4 & other)
{
	return Vector4( x - other.x, y - other.y, z - other.z, w - other.w);
}
//This allows a Vector4 to be subtracted by itself plus another Vector4
void Vector4::operator-=(const Vector4 & other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
}
//This allows a Vector4 to be multiplied by itself plus another Vector4
void Vector4::operator*=(const Vector4 & other)
{
	x *= other.x;
	y *= other.y;
	z *= other.z;
	w *= other.w;
}


//This allows a Vector4 to be multiplied by a 'real' value
Vector4 Vector4::operator*(real scalar)
{
	return Vector4( x*scalar, y*scalar, z*scalar, w*scalar);
}
//This allows a Vector4 to be equaled to a Vector4 multiplied by a real value
Vector4 operator*(real scalar, Vector4 &other)
{
	return Vector4( other.x * scalar, other.y * scalar, other.z * scalar, other.w * scalar);

}
//This returns the dot product of a Vector4.
real Vector4::dot(Vector4 &other)
{
	real tempreal = 0.0;
	for (int i = 0; i < 4; i++)
	{
		tempreal =  x * other.x + y * other.y + z * other.z + w * other.w ;
	}

	return tempreal;
}
//This returns the cross product of a Vector4.
Vector4 Vector4::cross(Vector4 & other)
{

	return Vector4(y * other.z - z * other.y,
		z * other.x - x * other.z, 
		x * other.y - y * other.x,
		0);

}
//This returns the magnitude of a Vector4.
real Vector4::magnitude()
{
	real tempreal;
	tempreal = sqrt( (x * x) + (y * y) + (z * z) + (w * w) );
	return tempreal;
}

//This returns the normalised value of a Vector4.
Vector4 Vector4::normalised()
{
	real tempMag = magnitude();

	Vector4 tempVec( x / tempMag, y / tempMag, z / tempMag, w / tempMag);


	return tempVec;
}

//This normalises a Vector4.
void Vector4::normalise()
{
	real tempMag = magnitude();

	
	x /= tempMag;
	y /= tempMag;
	z /= tempMag;
	w /= tempMag;

}

real Vector4::operator[](int n)const
{
	return e[n];
}

real & Vector4::operator[](int n)
{
	return e[n];
}
//This function allows a Vector4 to be used as a Vector2.
Vector4::operator Vector2()
{
	return Vector2(x, y);
}
//This function allows a Vector4 to be used as a Vector3.
Vector4::operator Vector3()
{
	return Vector3(x, y, z);
}