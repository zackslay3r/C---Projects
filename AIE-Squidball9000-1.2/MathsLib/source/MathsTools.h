#pragma once
#include "DllExport.h"
#include "RealType.h"


/**
* Useful maths functions made avalable via the custom namespace "MathsLib::".
* @author Ashley Flynn - AIE - 2017
*/

#define PI 3.141592f

namespace MathsLib
{
	/**
	* Clamp a value between min and max.
	* Template class that can accept any number type.
	* @params value The value to clamp. Passed by reference.
	* @params min The minimum value.
	* @params max The maximum value.
	* @returns void.
	*/
	template <class T>
	inline DLL void clamp(T &value, T min, T max)
	{
		if (value > max) value = max;
		if (value < min) value = min;
	};

	/**
	* Convert radians to degrees.
	* @params radians The number of radians.
	* @returns The value in degrees.
	*/
	template <class T>
	inline DLL T rad2deg(T radians)
	{
		return radians * ((T)180.0 / (T)PI);
	};

	/**
	* Convert degrees to radians.
	* @params degrees The number of degrees.
	* @returns The value in radians.
	*/
	template <class T>
	inline DLL T deg2rad(T degrees)
	{
		return (degrees * (T)PI) / (T)180.0;
	};

	/**
	* Distance between two points of any combination of dimensions.
	* @params vec1 The first point.
	* @params vec2 The second point.
	* @return The distance between the points.
	*/
	template <class T>
	inline DLL real distance(T vec1, T vec2)
	{
		return (vec2 - vec1).magnitude();
	};

	/**
	* Squared distance between two points of any combination of dimensions.
	* @params vec1 The first point.
	* @params vec2 The second point.
	* @return The squared distance between the points.
	*/
	template <class T>
	inline DLL real sqrDistance(T vec1, T vec2)
	{
		return (vec2 - vec1).magnitude();
	};

}