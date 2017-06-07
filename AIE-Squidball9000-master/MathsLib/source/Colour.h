#pragma once
#include "DllExport.h"
#include "RealType.h"

/**
* Colour class.
* Defines the four standard colour channels: Red, Green, Blue and Alpha.
* Colour values are in the range 0.0f .. 1.0f.
* @author Ashley Flynn - AIE - 2017
*/

class DLL Colour
{

public:

	/**
	* The red, green, blue and alpha channel values in the range 0.0f .. 1.0f.
	*/
	float r, g, b, a;

	/**
	* Default constructor.
	*/
	inline Colour() { r = g = b = a = (real)1.0; }

	/**
	* Constructor from four floats.
	* @params nR The red channel in the range 0.0f .. 1.0f.
	* @params nG The green channel in the range 0.0f .. 1.0f.
	* @params nB The blue channel in the range 0.0f .. 1.0f.
	* @params nA The alpha (transparency) channel in the range 0.0f .. 1.0f.
	*/
	inline Colour(real nR, real nG, real nB, real nA) { r = nR; g = nG; b = nB; a = nA; }

	/**
	* Copy constructor.
	* @params other The Colour object to copy data from.
	*/
	inline Colour(const Colour &other) { r = other.r; g = other.g; b = other.b; a = other.a; }

	/**
	* Asignment operator overload.
	* Copy one colour to another.
	* @params other The Colour object to copy data from.
	* @returns Reference to the colour object.
	*/
	inline Colour &operator=(const Colour &other) { r = other.r; g = other.g; b = other.b; a = other.a; return *this; }

	/**
	* Add another colour to this colour and return a new colour.
	* @returns The new colour.
	*/
	inline Colour operator+ (const Colour &other) const { return Colour(r + other.r, g + other.g, b + other.b, a + other.a); };

	/**
	* Subtract another colour from this colour and return a new colour.
	* @returns The new colour.
	*/
	inline Colour operator- (const Colour &other) const { return Colour(r - other.r, g - other.g, b - other.b, a - other.a); };

	/**
	* Divide this colour by another colour and return a new colour.
	* @returns The new colour.
	*/
	inline Colour operator/ (const Colour &other) const { return Colour(r / other.r, g / other.g, b / other.b, a / other.a); };

	/**
	* Multiply this colour by another colour and return a new colour.
	* @returns The new colour.
	*/
	inline Colour operator* (const Colour &other) const { return Colour(r * other.r, g * other.g, b * other.b, a * other.a); };

	/**
	* Add another colour to this colour.
	* @returns void.
	*/
	inline void operator+= (const Colour &other) { *this = *this + other; };

	/**
	* Subtract another colour from this colour.
	* @returns void.
	*/
	inline void operator-= (const Colour &other) { *this = *this - other; };

	/**
	* Divide this colour by another colour.
	* @returns void.
	*/
	inline void operator/= (const Colour &other) { *this = *this / other; };

	/**
	* Muliply this colour by another colour.
	* @returns void.
	*/
	inline void operator*= (const Colour &other) { *this = *this * other; };

};