#include "Vector3.h"
#include "Vector2.h"
#include "Vector4.h"
#include <math.h>
/*
This is the default constructor for a Vector3.
this should return a blank Vector3 with the identity matrix.
*/
Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}
/*
This is a different Vector3 constructor, it will create a default 1d array of type "real" with the parameters taken in.
*/
Vector3::Vector3(real newx, real newy, real newz)
{
	x = newx;
	y = newy;
	z = newz;
}
/* ~Vector3();
* This is the default destructor, it will destroy a Vector3.
* This is called when a the main program has reached the end of its scope.
*/
Vector3::~Vector3()
{
}

#pragma region swizzling
//swizzling
Vector2 Vector3::GetXX()
{
	return Vector2{ x,x };
}

//swizzling
Vector2 Vector3::GetXY()
{
	return Vector2{ x,y };
}

//swizzling
Vector2 Vector3::GetXZ()
{
	return Vector2{ x,z };
}

//swizzling
Vector2 Vector3::GetYX()
{
	return Vector2{ y,x };
}

//swizzling
Vector2 Vector3::GetYY()
{
	return Vector2{ y,y };
}

//swizzling
Vector2 Vector3::GetYZ()
{
	return Vector2{ y,z };
}

//swizzling
Vector2 Vector3::GetZX()
{
	return Vector2{ z,x };
}

//swizzling
Vector2 Vector3::GetZY()
{
	return Vector2{ z,y };
}

//swizzling
Vector2 Vector3::GetZZ()
{
	return Vector2{ z,z };
}

//swizzling
Vector3 Vector3::GetXXX()
{
	return Vector3{ x,x,x };
}

//swizzling
Vector3 Vector3::GetXXY()
{
	return Vector3{ x,x,y };
}

//swizzling
Vector3 Vector3::GetXXZ()
{
	return Vector3{ x,x,z };
}

//swizzling
Vector3 Vector3::GetXYX()
{
	return Vector3{ x,y,x };
}

//swizzling
Vector3 Vector3::GetXYY()
{
	return Vector3{ x,y,y };
}

//swizzling
Vector3 Vector3::GetXZX()
{
	return Vector3{ x,z,x };
}

//swizzling
Vector3 Vector3::GetXZY()
{
	return Vector3{ x,z,y };
}

//swizzling
Vector3 Vector3::GetXZZ()
{
	return Vector3{ x,z,z };
}

//swizzling
Vector3 Vector3::GetYXX()
{
	return Vector3{ y,x,x };
}

//swizzling
Vector3 Vector3::GetYXY()
{
	return Vector3{ y,x,y };
}

//swizzling
Vector3 Vector3::GetYXZ()
{
	return Vector3{ y,x,z };
}

//swizzling
Vector3 Vector3::GetYYX()
{
	return Vector3{ y,y,x };
}

//swizzling
Vector3 Vector3::GetYYY()
{
	return Vector3{ y,y,y };
}

//swizzling
Vector3 Vector3::GetYYZ()
{
	return Vector3{ y,y,z };
}

//swizzling
Vector3 Vector3::GetYZX()
{
	return Vector3{ y,z,x };
}

//swizzling
Vector3 Vector3::GetYZY()
{
	return Vector3{ y,z,y };
}

//swizzling
Vector3 Vector3::GetYZZ()
{
	return Vector3{ y,z,z };
}

//swizzling
Vector3 Vector3::GetZXX()
{
	return Vector3{ z,x,x };
}

//swizzling
Vector3 Vector3::GetZXY()
{
	return Vector3{ z,x,y };
}

//swizzling
Vector3 Vector3::GetZXZ()
{
	return Vector3{ z,x,z };
}

//swizzling
Vector3 Vector3::GetZYX()
{
	return Vector3{ z,y,x };
}

//swizzling
Vector3 Vector3::GetZYY()
{
	return Vector3{ z,y,y };
}

//swizzling
Vector3 Vector3::GetZYZ()
{
	return Vector3{ z,y,z };
}

//swizzling
Vector3 Vector3::GetZZX()
{
	return Vector3{ z,z,x };
}

//swizzling
Vector3 Vector3::GetZZY()
{
	return Vector3{ z,z,y };
}

//swizzling
Vector3 Vector3::GetZZZ()
{
	return Vector3{ z,z,z };
}

//swizzling
Vector4 Vector3::GetXXXX()
{
	return Vector4{ x,x,x,x };
}

//swizzling
Vector4 Vector3::GetXXXY()
{
	return Vector4{ x,x,x,y };
}

//swizzling
Vector4 Vector3::GetXXXZ()
{
	return Vector4{ x,x,x,z };
}

//swizzling
Vector4 Vector3::GetXXYX()
{
	return Vector4{ x,x,y,x };
}

//swizzling
Vector4 Vector3::GetXXYY()
{
	return Vector4{ x,x,y,y };
}

//swizzling
Vector4 Vector3::GetXXYZ()
{
	return Vector4{ x,x,y,z };
}

//swizzling
Vector4 Vector3::GetXXZX()
{
	return Vector4{ x,x,z,x };
}

//swizzling
Vector4 Vector3::GetXXZY()
{
	return Vector4{ x,x,z,y };
}

//swizzling
Vector4 Vector3::GetXXZZ()
{
	return Vector4{ x,x,z,z };
}

//swizzling
Vector4 Vector3::GetXYXX()
{
	return Vector4{ x,y,x,x };
}

//swizzling
Vector4 Vector3::GetXYXY()
{
	return Vector4{ x,y,x,y };
}

//swizzling
Vector4 Vector3::GetXYXZ()
{
	return Vector4{ x,y,x,z };
}

//swizzling
Vector4 Vector3::GetXYYX()
{
	return Vector4{ x,y,y,x };
}

//swizzling
Vector4 Vector3::GetXYYY()
{
	return Vector4{ x,y,y,y };
}

//swizzling
Vector4 Vector3::GetXYYZ()
{
	return Vector4{ x,y,y,z };
}

//swizzling
Vector4 Vector3::GetXYZX()
{
	return Vector4{ x,y,z,x };
}

//swizzling
Vector4 Vector3::GetXYZY()
{
	return Vector4{ x,y,z,y };
}

//swizzling
Vector4 Vector3::GetXYZZ()
{
	return Vector4{ x,y,z,z };
}

//swizzling
Vector4 Vector3::GetXZXX()
{
	return Vector4{ x,z,x,x };
}

//swizzling
Vector4 Vector3::GetXZXY()
{
	return Vector4{ x,z,x,y };
}

//swizzling
Vector4 Vector3::GetXZXZ()
{
	return Vector4{ x,z,x,z };
}

//swizzling
Vector4 Vector3::GetXZYX()
{
	return Vector4{ x,z,y,x };
}

//swizzling
Vector4 Vector3::GetXZYY()
{
	return Vector4{ x,z,y,y };
}

//swizzling
Vector4 Vector3::GetXZYZ()
{
	return Vector4{ x,z,y,z };
}

//swizzling
Vector4 Vector3::GetXZZX()
{
	return Vector4{ x,z,z,x };
}

//swizzling
Vector4 Vector3::GetXZZY()
{
	return Vector4{ x,z,z,y };
}

//swizzling
Vector4 Vector3::GetXZZZ()
{
	return Vector4{ x,z,z,z };
}

//swizzling
Vector4 Vector3::GetYXXX()
{
	return Vector4{ y,x,x,x };
}

//swizzling
Vector4 Vector3::GetYXXY()
{
	return Vector4{ y,x,x,y };
}

//swizzling
Vector4 Vector3::GetYXXZ()
{
	return Vector4{ y,x,x,z };
}

//swizzling
Vector4 Vector3::GetYXYX()
{
	return Vector4{ y,x,y,x };
}

//swizzling
Vector4 Vector3::GetYXYY()
{
	return Vector4{ y,x,y,y };
}

//swizzling
Vector4 Vector3::GetYXYZ()
{
	return Vector4{ y,x,y,z };
}

//swizzling
Vector4 Vector3::GetYXZX()
{
	return Vector4{ y,x,z,x };
}

//swizzling
Vector4 Vector3::GetYXZY()
{
	return Vector4{ y,x,z,y };
}

//swizzling
Vector4 Vector3::GetYXZZ()
{
	return Vector4{ y,x,z,z };
}

//swizzling
Vector4 Vector3::GetYYXX()
{
	return Vector4{ y,y,x,x };
}

//swizzling
Vector4 Vector3::GetYYXY()
{
	return Vector4{ y,y,x,y };
}

//swizzling
Vector4 Vector3::GetYYXZ()
{
	return Vector4{ y,y,x,z };
}

//swizzling
Vector4 Vector3::GetYYYX()
{
	return Vector4{ y,y,y,x };
}

//swizzling
Vector4 Vector3::GetYYYY()
{
	return Vector4{ y,y,y,y };
}

//swizzling
Vector4 Vector3::GetYYYZ()
{
	return Vector4{ y,y,y,z };
}

//swizzling
Vector4 Vector3::GetYYZX()
{
	return Vector4{ y,y,z,x };
}

//swizzling
Vector4 Vector3::GetYYZY()
{
	return Vector4{ y,y,z,y };
}

//swizzling
Vector4 Vector3::GetYYZZ()
{
	return Vector4{ y,y,z,z };
}

//swizzling
Vector4 Vector3::GetYZXX()
{
	return Vector4{ y,z,x,x };
}

//swizzling
Vector4 Vector3::GetYZXY()
{
	return Vector4{ y,z,x,y };
}

//swizzling
Vector4 Vector3::GetYZXZ()
{
	return Vector4{ y,z,x,z };
}

//swizzling
Vector4 Vector3::GetYZYX()
{
	return Vector4{ y,z,y,x };
}

//swizzling
Vector4 Vector3::GetYZYY()
{
	return Vector4{ y,z,y,y };
}

//swizzling
Vector4 Vector3::GetYZYZ()
{
	return Vector4{ y,z,y,z };
}

//swizzling
Vector4 Vector3::GetYZZX()
{
	return Vector4{ y,z,z,x };
}

//swizzling
Vector4 Vector3::GetYZZY()
{
	return Vector4{ y,z,z,y };
}

//swizzling
Vector4 Vector3::GetYZZZ()
{
	return Vector4{ y,z,z,z };
}

//swizzling
Vector4 Vector3::GetZXXX()
{
	return Vector4{ z,x,x,x };
}

//swizzling
Vector4 Vector3::GetZXXY()
{
	return Vector4{ z,x,x,y };
}

//swizzling
Vector4 Vector3::GetZXXZ()
{
	return Vector4{ z,x,x,z };
}

//swizzling
Vector4 Vector3::GetZXYX()
{
	return Vector4{ z,x,y,x };
}

//swizzling
Vector4 Vector3::GetZXYY()
{
	return Vector4{ z,x,y,y };
}

//swizzling
Vector4 Vector3::GetZXYZ()
{
	return Vector4{ z,x,y,z };
}

//swizzling
Vector4 Vector3::GetZXZX()
{
	return Vector4{ z,x,z,x };
}

//swizzling
Vector4 Vector3::GetZXZY()
{
	return Vector4{ z,x,z,y };
}

//swizzling
Vector4 Vector3::GetZXZZ()
{
	return Vector4{ z,x,z,z };
}

//swizzling
Vector4 Vector3::GetZYXX()
{
	return Vector4{ z,y,x,x };
}

//swizzling
Vector4 Vector3::GetZYXY()
{
	return Vector4{ z,y,x,y };
}

//swizzling
Vector4 Vector3::GetZYXZ()
{
	return Vector4{ z,y,x,z };
}

//swizzling
Vector4 Vector3::GetZYYX()
{
	return Vector4{ z,y,y,x };
}

//swizzling
Vector4 Vector3::GetZYYY()
{
	return Vector4{ z,y,y,y };
}

//swizzling
Vector4 Vector3::GetZYYZ()
{
	return Vector4{ z,y,y,z };
}

//swizzling
Vector4 Vector3::GetZYZX()
{
	return Vector4{ z,y,z,x };
}

//swizzling
Vector4 Vector3::GetZYZY()
{
	return Vector4{ z,y,z,y };
}

//swizzling
Vector4 Vector3::GetZYZZ()
{
	return Vector4{ z,y,z,z };
}

//swizzling
Vector4 Vector3::GetZZXX()
{
	return Vector4{ z,z,x,x };
}

//swizzling
Vector4 Vector3::GetZZXY()
{
	return Vector4{ z,z,x,y };
}

//swizzling
Vector4 Vector3::GetZZXZ()
{
	return Vector4{ z,z,x,z };
}

//swizzling
Vector4 Vector3::GetZZYX()
{
	return Vector4{ z,z,y,x };
}

//swizzling
Vector4 Vector3::GetZZYY()
{
	return Vector4{ z,z,y,y };
}

//swizzling
Vector4 Vector3::GetZZYZ()
{
	return Vector4{ z,z,y,z };
}

//swizzling
Vector4 Vector3::GetZZZX()
{
	return Vector4{ z,z,z,x };
}

//swizzling
Vector4 Vector3::GetZZZY()
{
	return Vector4{ z,z,z,y };
}

//swizzling
Vector4 Vector3::GetZZZZ()
{
	return Vector4{ z,z,z,z };
}


#pragma endregion swizzling

//This allows two Vector3's to be added together
Vector3 Vector3::operator+(Vector3 & other)
{
	return Vector3(x+other.x, y+other.y, z+other.z);
}
//This lets a Vector3 equal a Vector2
void Vector3::operator=(Vector2 & other)
{
	x = other.x;
	y = other.y;
	z = 0;
}
//This lets a Vector3 equal a Vector4
void Vector3::operator=(Vector4 & other)
{
	x = other.x;
	y = other.y;
	z = other.z;

}
//This allows a Vector3 to be added to itself plus another Vector3
void Vector3::operator+=(const Vector3 & other)
{
	x += other.x;
	y += other.y;
	z += other.z;
}
//This allows a Vector3 to be subtracted by another Vector3
Vector3 Vector3::operator-(Vector3 & other)
{
	return Vector3(x - other.x, y - other.y, z - other.z);
}
//This allows a Vector3 to be subtracted by itself plus another Vector3
void Vector3::operator-=(const Vector3 & other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
}
//This allows a Vector3 to be multiplied by itself plus another Vector3
void Vector3::operator*=(const Vector3 & other)
{
	x *= other.x;
	y *= other.y;
	z *= other.z;
}
//This allows a Vector3 to be multiplied by a 'real' value
Vector3 Vector3::operator*(real scalar)
{
	return Vector3(x*scalar, y*scalar, z*scalar);
}
//This allows a Vector3 to be equaled to a Vector3 multiplied by a real value
Vector3 operator*(real scalar, Vector3 & other)
{
	return Vector3(other.x * scalar, other.y * scalar, other.z * scalar );
}
//This returns the dot product of a Vector3.
real Vector3::dot(Vector3 &other)
{
	real tempreal = 0.0;
	for (int i = 0; i < 3; i++)
	{
		tempreal = x * other.x + y * other.y + z * other.z;
	}

	return tempreal;
}
//This returns the cross product of a Vector3.
Vector3 Vector3::cross(Vector3 & other)
{
	
	return Vector3(y * other.z - z * other.y,
		z * other.x - x * other.z, 
		x * other.y - y * other.x);
	
}
//This returns the magnitude of a Vector3.
real Vector3::magnitude()
{
	real tempreal;
	tempreal = sqrt((x * x) + (y * y) +( z * z));
	return tempreal;
}
//This returns the normalised value of a Vector3.
Vector3 Vector3::normalised()
{
	real tempMag = magnitude();

	Vector3 tempVec(x / tempMag, y / tempMag, z / tempMag);


	return tempVec;
}
//This normalises a Vector3.
void Vector3::normalise()
{
	real tempMag = magnitude();

	x /= tempMag;
	y /= tempMag;
	z /= tempMag;


}

real Vector3::operator[](int n)const
{
	return e[n];
}

real & Vector3::operator[](int n)
{
	return e[n];
}

//This function allows a Vector3 to be used as a Vector2.
Vector3::operator Vector2()
{
	return Vector2(x, y);
}

//This function allows a Vector3 to be used as a Vector4.
Vector3::operator Vector4()
{
	return Vector4(x, y,z,0);
}