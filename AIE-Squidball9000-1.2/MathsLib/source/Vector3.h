#pragma once
#include "DllExport.h"
#include "RealType.h"
#include "MathsTools.h"
#include <vector>
#include <math.h>

/**
* Forward declarations.
*/
class Vector2;
class Vector4;

/**
* A Vector class that provides essential vector data storage and functions.
* @author Ashley Flynn - AIE - 2017
*/

class DLL Vector3
{

public:
	
	/************************************************************************************
	* NOTE: This class relies on precise byte alignment to work with matrices
	* that depend on it. DO NOT add more member variables ouside the union or it will 
	* break the byte alignment!
	*************************************************************************************/

    /**
    * The vector elements as a series of byte-aligned types in a union.
    */
	union 
	{
		struct { real x, y, z; };
        real e[3]; //Elements as a single list of numbers.
	};

    /**
    * Enum of all axis names.
    */
    enum axes { X, Y, Z };

	/**
	* Define the number of elements in this vector.
	* Defined via a function as we can't add member variables to this class.
	* See note about byte alignment.
	* @returns The number of elements in this vector.
	*/
	const inline int getSize() const { return 3; };

	/**
	* Define the number of rows in this vector.
	* Defined via a function as we can't add member variables to this class.
	* See note about byte alignment.
	* @returns The number of rows in this vector.
	*/
	const inline int getRows() const { return 3; };

	/**
	* Define the number of columns in this vector.
	* Defined via a function as we can't add member variables to this class.
	* See note about byte alignment.
	* @returns The number of columns in this vector.
	*/
	const inline int getCols() const { return 1; };

    /**
    * Constructor.
    */
    Vector3();

    /**
    * Constructor with preset x and y coords.
    * @param newX The x value to set for the vector.
    * @param newY The y value to set for the vector.
	* @param newZ The z value to set for the vector.
    */
    Vector3(real newX, real newY, real newZ);

    /**
    * Copy constructor.
    * @param other The vector to copy.
    */
    Vector3(const Vector3 &other);

    /**
    * Destructor.
    */
    ~Vector3();

	/**
	* Cast to float pointer operator overload.
    * @returns A pointer to the first float in the vector.
	*/
    inline operator real *() { return &x; }

	/**
	* Cast to Vector2.
	* @returns A new Vector2 created from the x and y axes of the Vector3.
	*/
	operator Vector2();

	/**
	* Cast to Vector4.
	* @returns A new Vector4 created from the x, y and z axes of the Vector3, with 1.0 as the w axis.
	*/
	operator Vector4();

    /**
    * Multiply vector by -1.
    * @returns The new vector.
    */
    Vector3 operator- () const;

	/**
	* Copy data from another vector to this vector.
	* @param other The vector to copy from.
	* @returns A reference to the vector.
	*/
	Vector3 &operator= (const Vector3 &other);

    /**
    * Translate a point by a vector using addition.
    * @param other The vector to translate the point by.
    * @returns The new point.
    */
    Vector3 operator+ (const Vector3 &other) const;

    /**
    * Translate this point by a vector using addition.
    * @param other The vector to translate the point by.
    * @returns void.
    */
    void operator+= (const Vector3 &other);

    /**
    * Translate a point by a vector using subtraction.
    * @param other The vector to translate the point by.
    * @returns The new point.
    */
    Vector3 operator- (const Vector3 &other) const;

    /**
    * Translate this point by a vector using subtraction.
    * @param other The vector to translate the point by.
    * @returns void.
    */
    void operator-= (const Vector3 &other);

    /**
    * Multiply this vector by a scalar.
    * @param scalar The scalar to multiply this vector by.
    * @returns The new vector.
    */
    Vector3 operator* (real scalar) const;

	/**
	* Divide this vector by a scalar.
	* @param scalar The scalar to divied this vector by.
	* @returns The new vector.
	*/
	Vector3 operator/ (real scalar) const;

	/**
	* Divide this vector by a scalar.
	* @param scalar The scalar to divide this vector by.
	* @returns void.
	*/
	void operator/= (real scalar);

    /**
    * Multiply this vector by a scalar.
    * @param scalar The scalar to multiply this vector by.
    * @returns void.
    */
    void operator*= (real scalar);

    /**
    * Multiply scalar by this vector.
    * @param scalar The scalar to multiply this vector by.
    * @param vector The vector to multiply.
    * @returns The new vector.
    */
    friend inline Vector3 operator* (real scalar, const Vector3 &vector) { return vector * scalar; };

    /**
    * Get or set the Nth element of the vector.
    * Eg: float test = myvector[1]; myvector[1] = 2.2f;
    * @param The element number to return.
    * @returns A reference to the requested element.
    */
    real &operator[] (const int n);

    /**
    * Get the Nth element value of the vector. CONST SAFE version.
    * Eg: float test = myvector[1];
    * @param The element number to return.
    * @returns The value of the requested element.
    */
    const real operator[] (const int n) const;

    /**
    * Get the angle between this vector and another in RADIANS.
    * @params other The other vector to compare against.
    * @returns The angle between the vectors.
    */
    real getAngleBetween(const Vector3 &other) const;

    /**
    * Get the angle between this vector and another in DEGREES.
    * @params other The other vector to compare against.
    * @returns The angle between the vectors.
    */
	inline real getAngleBetweenDeg(const Vector3 &other) const { return getAngleBetween(other) * (180.0f / PI); };

    /**
    * Get vector magnitude.
    * @returns Vector magnitude.
    */
    real magnitude() const;

    /**
    * Get the vector magnitude squared.
    * Faster than calculating magnitude (which uses a slow square root).
    * @returns Vector magnitude squared.
    */
    real magnitudeSqr() const;

    /**
    * Normalise this vector.
    * @returns void.
    */
    void normalise();

    /**
    * Get a normalised copy of this vector.
    * @returns The normalised vector.
    */
    Vector3 normalised() const;

    /**
    * Get the dot product of this vector and another vector.
    * @param other The other vector to dot product with this vector.
    * @returns The dot product of the two vectors.
    */
    real dot(const Vector3 &other) const;

	/**
	* Get the cross product of this vector and another vector.
	* @param other The other vector to cross product with this vector.
	* @returns The cross product vector of the two vectors.
	*/
	Vector3 cross(const Vector3 &other) const;

    /**
    * Return swizzled vector. See https://en.wikipedia.org/wiki/Swizzling_(computer_graphics)
    * @param ax1 The first axis value as defined in enum axes.
    * @returns The swizzled vector.
    */
    inline Vector3 swizzle(axes ax1) const { return Vector3(e[ax1], e[ax1], e[ax1]); };
    
    /**
    * Return swizzled vector. See https://en.wikipedia.org/wiki/Swizzling_(computer_graphics)
    * @param ax1 The first axis value as defined in enum axes.
    * @param ax2 The second axis value as defined in enum axes.
    * @returns The swizzled vector.
    */
    inline Vector3 swizzle(axes ax1, axes ax2) const { return Vector3(e[ax1], e[ax2], e[ax2]); };

    /**
    * Return swizzled vector. See https://en.wikipedia.org/wiki/Swizzling_(computer_graphics)
    * @param ax1 The first axis value as defined in enum axes.
    * @param ax2 The second axis value as defined in enum axes.
    * @param ax3 The third axis value as defined in enum axes.
    * @returns The swizzled vector.
    */
    inline Vector3 swizzle(axes ax1, axes ax2, axes ax3) const { return Vector3(e[ax1], e[ax2], e[ax3]); };

#pragma region swizzleDecs

    /**
    * Swizzle vector to (x,x).
    * @returns The swizzled vector.
    */
    Vector2 GetXX();

    /**
    * Swizzle vector to (x,y).
    * @returns The swizzled vector.
    */
    Vector2 GetXY();

    /**
    * Swizzle vector to (x,z).
    * @returns The swizzled vector.
    */
    Vector2 GetXZ();

    /**
    * Swizzle vector to (y,x).
    * @returns The swizzled vector.
    */
    Vector2 GetYX();

    /**
    * Swizzle vector to (y,y).
    * @returns The swizzled vector.
    */
    Vector2 GetYY();

    /**
    * Swizzle vector to (y,z).
    * @returns The swizzled vector.
    */
    Vector2 GetYZ();

    /**
    * Swizzle vector to (z,x).
    * @returns The swizzled vector.
    */
    Vector2 GetZX();

    /**
    * Swizzle vector to (z,y).
    * @returns The swizzled vector.
    */
    Vector2 GetZY();

    /**
    * Swizzle vector to (z,z).
    * @returns The swizzled vector.
    */
    Vector2 GetZZ();

    /**
    * Swizzle vector to (x,x,x).
    * @returns The swizzled vector.
    */
    Vector3 GetXXX();

    /**
    * Swizzle vector to (x,x,y).
    * @returns The swizzled vector.
    */
    Vector3 GetXXY();

    /**
    * Swizzle vector to (x,x,z).
    * @returns The swizzled vector.
    */
    Vector3 GetXXZ();

    /**
    * Swizzle vector to (x,y,x).
    * @returns The swizzled vector.
    */
    Vector3 GetXYX();

    /**
    * Swizzle vector to (x,y,y).
    * @returns The swizzled vector.
    */
    Vector3 GetXYY();

    /**
    * Swizzle vector to (x,z,x).
    * @returns The swizzled vector.
    */
    Vector3 GetXZX();

    /**
    * Swizzle vector to (x,z,y).
    * @returns The swizzled vector.
    */
    Vector3 GetXZY();

    /**
    * Swizzle vector to (x,z,z).
    * @returns The swizzled vector.
    */
    Vector3 GetXZZ();

    /**
    * Swizzle vector to (y,x,x).
    * @returns The swizzled vector.
    */
    Vector3 GetYXX();

    /**
    * Swizzle vector to (y,x,y).
    * @returns The swizzled vector.
    */
    Vector3 GetYXY();

    /**
    * Swizzle vector to (y,x,z).
    * @returns The swizzled vector.
    */
    Vector3 GetYXZ();

    /**
    * Swizzle vector to (y,y,x).
    * @returns The swizzled vector.
    */
    Vector3 GetYYX();

    /**
    * Swizzle vector to (y,y,y).
    * @returns The swizzled vector.
    */
    Vector3 GetYYY();

    /**
    * Swizzle vector to (y,y,z).
    * @returns The swizzled vector.
    */
    Vector3 GetYYZ();

    /**
    * Swizzle vector to (y,z,x).
    * @returns The swizzled vector.
    */
    Vector3 GetYZX();

    /**
    * Swizzle vector to (y,z,y).
    * @returns The swizzled vector.
    */
    Vector3 GetYZY();

    /**
    * Swizzle vector to (y,z,z).
    * @returns The swizzled vector.
    */
    Vector3 GetYZZ();

    /**
    * Swizzle vector to (z,x,x).
    * @returns The swizzled vector.
    */
    Vector3 GetZXX();

    /**
    * Swizzle vector to (z,x,y).
    * @returns The swizzled vector.
    */
    Vector3 GetZXY();

    /**
    * Swizzle vector to (z,x,z).
    * @returns The swizzled vector.
    */
    Vector3 GetZXZ();

    /**
    * Swizzle vector to (z,y,x).
    * @returns The swizzled vector.
    */
    Vector3 GetZYX();

    /**
    * Swizzle vector to (z,y,y).
    * @returns The swizzled vector.
    */
    Vector3 GetZYY();

    /**
    * Swizzle vector to (z,y,z).
    * @returns The swizzled vector.
    */
    Vector3 GetZYZ();

    /**
    * Swizzle vector to (z,z,x).
    * @returns The swizzled vector.
    */
    Vector3 GetZZX();

    /**
    * Swizzle vector to (z,z,y).
    * @returns The swizzled vector.
    */
    Vector3 GetZZY();

    /**
    * Swizzle vector to (z,z,z).
    * @returns The swizzled vector.
    */
    Vector3 GetZZZ();

    /**
    * Swizzle vector to (x,x,x,x).
    * @returns The swizzled vector.
    */
    Vector4 GetXXXX();

    /**
    * Swizzle vector to (x,x,x,y).
    * @returns The swizzled vector.
    */
    Vector4 GetXXXY();

    /**
    * Swizzle vector to (x,x,x,z).
    * @returns The swizzled vector.
    */
    Vector4 GetXXXZ();

    /**
    * Swizzle vector to (x,x,y,x).
    * @returns The swizzled vector.
    */
    Vector4 GetXXYX();

    /**
    * Swizzle vector to (x,x,y,y).
    * @returns The swizzled vector.
    */
    Vector4 GetXXYY();

    /**
    * Swizzle vector to (x,x,y,z).
    * @returns The swizzled vector.
    */
    Vector4 GetXXYZ();

    /**
    * Swizzle vector to (x,x,z,x).
    * @returns The swizzled vector.
    */
    Vector4 GetXXZX();

    /**
    * Swizzle vector to (x,x,z,y).
    * @returns The swizzled vector.
    */
    Vector4 GetXXZY();

    /**
    * Swizzle vector to (x,x,z,z).
    * @returns The swizzled vector.
    */
    Vector4 GetXXZZ();

    /**
    * Swizzle vector to (x,y,x,x).
    * @returns The swizzled vector.
    */
    Vector4 GetXYXX();

    /**
    * Swizzle vector to (x,y,x,y).
    * @returns The swizzled vector.
    */
    Vector4 GetXYXY();

    /**
    * Swizzle vector to (x,y,x,z).
    * @returns The swizzled vector.
    */
    Vector4 GetXYXZ();

    /**
    * Swizzle vector to (x,y,y,x).
    * @returns The swizzled vector.
    */
    Vector4 GetXYYX();

    /**
    * Swizzle vector to (x,y,y,y).
    * @returns The swizzled vector.
    */
    Vector4 GetXYYY();

    /**
    * Swizzle vector to (x,y,y,z).
    * @returns The swizzled vector.
    */
    Vector4 GetXYYZ();

    /**
    * Swizzle vector to (x,y,z,x).
    * @returns The swizzled vector.
    */
    Vector4 GetXYZX();

    /**
    * Swizzle vector to (x,y,z,y).
    * @returns The swizzled vector.
    */
    Vector4 GetXYZY();

    /**
    * Swizzle vector to (x,y,z,z).
    * @returns The swizzled vector.
    */
    Vector4 GetXYZZ();

    /**
    * Swizzle vector to (x,z,x,x).
    * @returns The swizzled vector.
    */
    Vector4 GetXZXX();

    /**
    * Swizzle vector to (x,z,x,y).
    * @returns The swizzled vector.
    */
    Vector4 GetXZXY();

    /**
    * Swizzle vector to (x,z,x,z).
    * @returns The swizzled vector.
    */
    Vector4 GetXZXZ();

    /**
    * Swizzle vector to (x,z,y,x).
    * @returns The swizzled vector.
    */
    Vector4 GetXZYX();

    /**
    * Swizzle vector to (x,z,y,y).
    * @returns The swizzled vector.
    */
    Vector4 GetXZYY();

    /**
    * Swizzle vector to (x,z,y,z).
    * @returns The swizzled vector.
    */
    Vector4 GetXZYZ();

    /**
    * Swizzle vector to (x,z,z,x).
    * @returns The swizzled vector.
    */
    Vector4 GetXZZX();

    /**
    * Swizzle vector to (x,z,z,y).
    * @returns The swizzled vector.
    */
    Vector4 GetXZZY();

    /**
    * Swizzle vector to (x,z,z,z).
    * @returns The swizzled vector.
    */
    Vector4 GetXZZZ();

    /**
    * Swizzle vector to (y,x,x,x).
    * @returns The swizzled vector.
    */
    Vector4 GetYXXX();

    /**
    * Swizzle vector to (y,x,x,y).
    * @returns The swizzled vector.
    */
    Vector4 GetYXXY();

    /**
    * Swizzle vector to (y,x,x,z).
    * @returns The swizzled vector.
    */
    Vector4 GetYXXZ();

    /**
    * Swizzle vector to (y,x,y,x).
    * @returns The swizzled vector.
    */
    Vector4 GetYXYX();

    /**
    * Swizzle vector to (y,x,y,y).
    * @returns The swizzled vector.
    */
    Vector4 GetYXYY();

    /**
    * Swizzle vector to (y,x,y,z).
    * @returns The swizzled vector.
    */
    Vector4 GetYXYZ();

    /**
    * Swizzle vector to (y,x,z,x).
    * @returns The swizzled vector.
    */
    Vector4 GetYXZX();

    /**
    * Swizzle vector to (y,x,z,y).
    * @returns The swizzled vector.
    */
    Vector4 GetYXZY();

    /**
    * Swizzle vector to (y,x,z,z).
    * @returns The swizzled vector.
    */
    Vector4 GetYXZZ();

    /**
    * Swizzle vector to (y,y,x,x).
    * @returns The swizzled vector.
    */
    Vector4 GetYYXX();

    /**
    * Swizzle vector to (y,y,x,y).
    * @returns The swizzled vector.
    */
    Vector4 GetYYXY();

    /**
    * Swizzle vector to (y,y,x,z).
    * @returns The swizzled vector.
    */
    Vector4 GetYYXZ();

    /**
    * Swizzle vector to (y,y,y,x).
    * @returns The swizzled vector.
    */
    Vector4 GetYYYX();

    /**
    * Swizzle vector to (y,y,y,y).
    * @returns The swizzled vector.
    */
    Vector4 GetYYYY();

    /**
    * Swizzle vector to (y,y,y,z).
    * @returns The swizzled vector.
    */
    Vector4 GetYYYZ();

    /**
    * Swizzle vector to (y,y,z,x).
    * @returns The swizzled vector.
    */
    Vector4 GetYYZX();

    /**
    * Swizzle vector to (y,y,z,y).
    * @returns The swizzled vector.
    */
    Vector4 GetYYZY();

    /**
    * Swizzle vector to (y,y,z,z).
    * @returns The swizzled vector.
    */
    Vector4 GetYYZZ();

    /**
    * Swizzle vector to (y,z,x,x).
    * @returns The swizzled vector.
    */
    Vector4 GetYZXX();

    /**
    * Swizzle vector to (y,z,x,y).
    * @returns The swizzled vector.
    */
    Vector4 GetYZXY();

    /**
    * Swizzle vector to (y,z,x,z).
    * @returns The swizzled vector.
    */
    Vector4 GetYZXZ();

    /**
    * Swizzle vector to (y,z,y,x).
    * @returns The swizzled vector.
    */
    Vector4 GetYZYX();

    /**
    * Swizzle vector to (y,z,y,y).
    * @returns The swizzled vector.
    */
    Vector4 GetYZYY();

    /**
    * Swizzle vector to (y,z,y,z).
    * @returns The swizzled vector.
    */
    Vector4 GetYZYZ();

    /**
    * Swizzle vector to (y,z,z,x).
    * @returns The swizzled vector.
    */
    Vector4 GetYZZX();

    /**
    * Swizzle vector to (y,z,z,y).
    * @returns The swizzled vector.
    */
    Vector4 GetYZZY();

    /**
    * Swizzle vector to (y,z,z,z).
    * @returns The swizzled vector.
    */
    Vector4 GetYZZZ();

    /**
    * Swizzle vector to (z,x,x,x).
    * @returns The swizzled vector.
    */
    Vector4 GetZXXX();

    /**
    * Swizzle vector to (z,x,x,y).
    * @returns The swizzled vector.
    */
    Vector4 GetZXXY();

    /**
    * Swizzle vector to (z,x,x,z).
    * @returns The swizzled vector.
    */
    Vector4 GetZXXZ();

    /**
    * Swizzle vector to (z,x,y,x).
    * @returns The swizzled vector.
    */
    Vector4 GetZXYX();

    /**
    * Swizzle vector to (z,x,y,y).
    * @returns The swizzled vector.
    */
    Vector4 GetZXYY();

    /**
    * Swizzle vector to (z,x,y,z).
    * @returns The swizzled vector.
    */
    Vector4 GetZXYZ();

    /**
    * Swizzle vector to (z,x,z,x).
    * @returns The swizzled vector.
    */
    Vector4 GetZXZX();

    /**
    * Swizzle vector to (z,x,z,y).
    * @returns The swizzled vector.
    */
    Vector4 GetZXZY();

    /**
    * Swizzle vector to (z,x,z,z).
    * @returns The swizzled vector.
    */
    Vector4 GetZXZZ();

    /**
    * Swizzle vector to (z,y,x,x).
    * @returns The swizzled vector.
    */
    Vector4 GetZYXX();

    /**
    * Swizzle vector to (z,y,x,y).
    * @returns The swizzled vector.
    */
    Vector4 GetZYXY();

    /**
    * Swizzle vector to (z,y,x,z).
    * @returns The swizzled vector.
    */
    Vector4 GetZYXZ();

    /**
    * Swizzle vector to (z,y,y,x).
    * @returns The swizzled vector.
    */
    Vector4 GetZYYX();

    /**
    * Swizzle vector to (z,y,y,y).
    * @returns The swizzled vector.
    */
    Vector4 GetZYYY();

    /**
    * Swizzle vector to (z,y,y,z).
    * @returns The swizzled vector.
    */
    Vector4 GetZYYZ();

    /**
    * Swizzle vector to (z,y,z,x).
    * @returns The swizzled vector.
    */
    Vector4 GetZYZX();

    /**
    * Swizzle vector to (z,y,z,y).
    * @returns The swizzled vector.
    */
    Vector4 GetZYZY();

    /**
    * Swizzle vector to (z,y,z,z).
    * @returns The swizzled vector.
    */
    Vector4 GetZYZZ();

    /**
    * Swizzle vector to (z,z,x,x).
    * @returns The swizzled vector.
    */
    Vector4 GetZZXX();

    /**
    * Swizzle vector to (z,z,x,y).
    * @returns The swizzled vector.
    */
    Vector4 GetZZXY();

    /**
    * Swizzle vector to (z,z,x,z).
    * @returns The swizzled vector.
    */
    Vector4 GetZZXZ();

    /**
    * Swizzle vector to (z,z,y,x).
    * @returns The swizzled vector.
    */
    Vector4 GetZZYX();

    /**
    * Swizzle vector to (z,z,y,y).
    * @returns The swizzled vector.
    */
    Vector4 GetZZYY();

    /**
    * Swizzle vector to (z,z,y,z).
    * @returns The swizzled vector.
    */
    Vector4 GetZZYZ();

    /**
    * Swizzle vector to (z,z,z,x).
    * @returns The swizzled vector.
    */
    Vector4 GetZZZX();

    /**
    * Swizzle vector to (z,z,z,y).
    * @returns The swizzled vector.
    */
    Vector4 GetZZZY();

    /**
    * Swizzle vector to (z,z,z,z).
    * @returns The swizzled vector.
    */
    Vector4 GetZZZZ();

#pragma endregion

};