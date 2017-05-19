#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include <math.h>


/*
This is the default constructor for a Vector2.
this should return a blank Vector2 with the identity matrix.
*/
Vector2::Vector2()
{
	x = 0;
	y = 0;
}

#pragma region swizzling
//swizzling
Vector2 Vector2::GetXX()
{
	return Vector2{ x,x };
}

//swizzling
Vector2 Vector2::GetYX()
{
	return Vector2{ y,x };
}

//swizzling
Vector2 Vector2::GetYY()
{
	return Vector2{ y,y };
}

//swizzling
Vector3 Vector2::GetXXX()
{
	return Vector3{ x,x,x };
}

//swizzling
Vector3 Vector2::GetXXY()
{
	return Vector3{ x,x,y };
}

//swizzling
Vector3 Vector2::GetXYX()
{
	return Vector3{ x,y,x };
}

//swizzling
Vector3 Vector2::GetXYY()
{
	return Vector3{ x,y,y };
}

//swizzling
Vector3 Vector2::GetYXX()
{
	return Vector3{ y,x,x };
}

//swizzling
Vector3 Vector2::GetYXY()
{
	return Vector3{ y,x,y };
}

//swizzling
Vector3 Vector2::GetYYX()
{
	return Vector3{ y,y,x };
}

//swizzling
Vector3 Vector2::GetYYY()
{
	return Vector3{ y,y,y };
}

//swizzling
Vector4 Vector2::GetXXXX()
{
	return Vector4{ x,x,x,x };
}

//swizzling
Vector4 Vector2::GetXXXY()
{
	return Vector4{ x,x,x,y };
}

//swizzling
Vector4 Vector2::GetXXYX()
{
	return Vector4{ x,x,y,x };
}

//swizzling
Vector4 Vector2::GetXXYY()
{
	return Vector4{ x,x,y,y };
}

//swizzling
Vector4 Vector2::GetXYXX()
{
	return Vector4{ x,y,x,x };
}

//swizzling
Vector4 Vector2::GetXYXY()
{
	return Vector4{ x,y,x,y };
}

//swizzling
Vector4 Vector2::GetXYYX()
{
	return Vector4{ x,y,y,x };
}

//swizzling
Vector4 Vector2::GetXYYY()
{
	return Vector4{ x,y,y,y };
}

//swizzling
Vector4 Vector2::GetYXXX()
{
	return Vector4{ y,x,x,x };
}

//swizzling
Vector4 Vector2::GetYXXY()
{
	return Vector4{ y,x,x,y };
}

//swizzling
Vector4 Vector2::GetYXYX()
{
	return Vector4{ y,x,y,x };
}

//swizzling
Vector4 Vector2::GetYXYY()
{
	return Vector4{ y,x,y,y };
}

//swizzling
Vector4 Vector2::GetYYXX()
{
	return Vector4{ y,y,x,x };
}

//swizzling
Vector4 Vector2::GetYYXY()
{
	return Vector4{ y,y,x,y };
}

//swizzling
Vector4 Vector2::GetYYYX()
{
	return Vector4{ y,y,y,x };
}

//swizzling
Vector4 Vector2::GetYYYY()
{
	return Vector4{ y,y,y,y };
}
#pragma endregion swizzling

/*
This is a different Vector2 constructor, it will create a default 1d array of type "real" with the parameters taken in.
*/
Vector2::Vector2(real newx, real newy)
{
	x = newx;
	y = newy;
}
/* ~Vector2();
* This is the default destructor, it will destroy a Vector2.
* This is called when a the main program has reached the end of its scope.
*/
Vector2::~Vector2()
{
}
//This lets a Vector2 equal a Vector4
void Vector2::operator=(Vector4 & other)
{
	
	x = other.x;
	y = other.y;
	
}
//This lets a Vector2 equal a Vector3
void Vector2::operator=(Vector3 & other)
{
	x = other.x;
	y = other.y;

}
//This allows two Vector2's to be added together
Vector2 Vector2::operator+(Vector2 & other)
{
	return Vector2(x + other.x, y + other.y);
}
//This allows a Vector2 to be added to itself plus another Vector2
void Vector2::operator+=(const Vector2 & other)
{
	x += other.x;
	y += other.y;
}

//This allows a Vector2 to be subtracted by another Vector2
Vector2 Vector2::operator-(Vector2 & other)
{
	return Vector2(x - other.x, y - other.y);
}
//This allows a Vector2 to be subtracted by itself plus another Vector2
void Vector2::operator-=(const Vector2 & other)
{
	x -= other.x;
	y -= other.y;
}
//This allows a Vector2 to be multiplied by itself plus another Vector2
void Vector2::operator*=(const Vector2 & other)
{
	x *= other.x;
	y *= other.y;
}
//This allows a Vector2 to be multiplied by a 'real' value
Vector2 Vector2::operator*(real scalar)
{
	return Vector2(x*scalar, y*scalar);
}




//This allows a Vector2 to be equaled to a Vector2 multiplied by a real value
Vector2 operator*(real scalar, Vector2 & other)
{
	return Vector2(other.x * scalar, other.y * scalar);
}

//This returns the dot product of a Vector2.
real Vector2::dot(Vector2 &other)
{
	real tempreal = 0.0;
	for (int i = 0; i < 2; i++)
	{
		tempreal = x * other.x + y * other.y;
	}

	return tempreal;
}
//This returns the magnitude of a Vector2.
real Vector2::magnitude()
{
	real tempreal;
	tempreal = sqrt((x * x) + (y * y));
	return tempreal;
}
//This returns the normalised value of a Vector2.
Vector2 Vector2::normalised()
{
	real tempMag = magnitude();

	Vector2 tempVec(x / tempMag, y / tempMag);


	return tempVec;
}
//This normalises a Vector2.
void Vector2::normalise()
{
	real tempMag = magnitude();

	x /= tempMag;
	y /= tempMag;


}
real Vector2::operator[](int n)const
{
	return e[n];
}

real & Vector2::operator[](int n)
{
	return e[n];
}
//This function allows a Vector2 to be used as a Vector3.
Vector2::operator Vector3()
{
	return Vector3(x, y, 0);
}
//This function allows a Vector2 to be used as a Vector4.
Vector2::operator Vector4()
{
	return Vector4(x, y, 0, 0);
}