#pragma once
class Vector2
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
	Vector2(float newx, float newy);

	/* Vector2();
	* This is the default destructor, it will destroy a Vector2.
	* This is called when a the main program has reached the end of its scope.
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
	Vector2 operator*(float scalar);

	union
	{
		struct { float x, y; };
		float e[2];
	};

	/*	void normalise();
	*	This function normalises a Vector2.
	*
	*
	*	@returns void
	*/
	void normalise();

	/*	float magnitude();
	*	This function returns a 'float' value that is the magnitude of a Vector2.
	*
	*	@returns 'float'
	*/
	float magnitude();


	~Vector2();
};

