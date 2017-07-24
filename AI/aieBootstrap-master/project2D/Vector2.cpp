#include "Vector2.h"



Vector2::Vector2()
{
	x = 0;
	y = 0;
}


Vector2::Vector2(float newx, float newy)
{
	x = newx;
	y = newy;
}

Vector2::~Vector2()
{
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
Vector2 Vector2::operator*(float scalar)
{
	return Vector2(x*scalar, y*scalar);
}
