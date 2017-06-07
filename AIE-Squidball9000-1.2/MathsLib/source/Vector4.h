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
class Vector3;


/**
* A Vector class that provides essential vector data storage and functions.
* @author Ashley Flynn - AIE - 2017
*/

class DLL Vector4
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
		struct { real x, y, z, w; };
        real e[4]; //Elements as a single list of numbers.
	};

    /**
    * Enum of all axis names.
    */
    enum axes { X, Y, Z, W };

	/**
	* Define the number of elements in this vector.
	* Defined via a function as we can't add member variables to this class.
	* See note about byte alignment.
	* @returns The number of elements in this vector.
	*/
	const inline int getSize() const { return 4; };

	/**
	* Define the number of rows in this vector.
	* Defined via a function as we can't add member variables to this class.
	* See note about byte alignment.
	* @returns The number of rows in this vector.
	*/
	const inline int getRows() const { return 4; };

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
    Vector4();

    /**
    * Constructor with preset x and y coords.
    * @param newX The x value to set for the vector.
    * @param newY The y value to set for the vector.
	* @param newZ The z value to set for the vector.
	* @param newW The w value to set for the vector.
    */
    Vector4(real newX, real newY, real newZ, real newW);

    /**
    * Copy constructor.
    * @param other The vector to copy.
    */
    Vector4(const Vector4 &other);

    /**
    * Destructor.
    */
    ~Vector4();

	/**
	* Cast to float pointer operator overload.
    * @returns A pointer to the first float in the vector.
	*/
    inline operator real *() { return &x; }

	/**
	* Cast to Vector3.
	* @returns A new Vector3 created from the x, y and z axes of the Vector4.
	*/
	operator Vector3();

	/**
	* Cast to Vector2.
	* @returns A new Vector2 created from the x and y axes of the Vector4.
	*/
	operator Vector2();

    /**
    * Multiply vector by -1.
    * @returns The new vector.
    */
    Vector4 operator- () const;

	/**
	* Copy data from another vector to this vector.
	* @param other The vector to copy from.
	* @returns A reference to the vector.
	*/
	Vector4 &operator= (const Vector4 &other);

    /**
    * Translate a point by a vector using addition.
    * @param other The vector to translate the point by.
    * @returns The new point.
    */
    Vector4 operator+ (const Vector4 &other) const;

    /**
    * Translate this point by a vector using addition.
    * @param other The vector to translate the point by.
    * @returns void.
    */
    void operator+= (const Vector4 &other);

    /**
    * Translate a point by a vector using subtraction.
    * @param other The vector to translate the point by.
    * @returns The new point.
    */
    Vector4 operator- (const Vector4 &other) const;

    /**
    * Translate this point by a vector using subtraction.
    * @param other The vector to translate the point by.
    * @returns void.
    */
    void operator-= (const Vector4 &other);

    /**
    * Multiply this vector by a scalar.
    * @param scalar The scalar to multiply the vector by.
    * @returns The new vector.
    */
    Vector4 operator* (real scalar) const;

	/**
    * Divide this vector by a scalar.
    * @param scalar The scalar to divide the vector by.
    * @returns The new vector.
    */
    Vector4 operator/ (real scalar) const;

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
    friend inline Vector4 operator* (real scalar, const Vector4 &vector) { return vector * scalar; };

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
    real getAngleBetween(const Vector4 &other) const;

    /**
    * Get the angle between this vector and another in DEGREES.
    * @params other The other vector to compare against.
    * @returns The angle between the vectors.
    */
	inline real getAngleBetweenDeg(const Vector4 &other) const { return getAngleBetween(other) * (180.0f / PI); };

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
    Vector4 normalised() const;

    /**
    * Get the dot product of this vector and another vector.
    * @param other The other vector to dot product with this vector.
    * @returns The dot product of the two vectors.
    */
    real dot(const Vector4 &other) const;

	/**
	* Get the cross product of this vector and another vector.
	* @param other The other vector to cross product with this vector.
	* @returns The cross product vector of the two vectors.
	*/
	Vector4 cross(const Vector4 &other) const;

    /**
    * Return swizzled vector. See https://en.wikipedia.org/wiki/Swizzling_(computer_graphics)
    * @param ax1 The first axis value as defined in enum axes.
    * @returns The swizzled vector.
    */
    inline Vector4 swizzle(axes ax1) const { return Vector4(e[ax1], e[ax1], e[ax1], e[ax1]); };

    /**
    * Return swizzled vector. See https://en.wikipedia.org/wiki/Swizzling_(computer_graphics)
    * @param ax1 The first axis value as defined in enum axes.
    * @param ax2 The second axis value as defined in enum axes.
    * @returns The swizzled vector.
    */
    inline Vector4 swizzle(axes ax1, axes ax2) const { return Vector4(e[ax1], e[ax2], e[ax2], e[ax2]); };

    /**
    * Return swizzled vector. See https://en.wikipedia.org/wiki/Swizzling_(computer_graphics)
    * @param ax1 The first axis value as defined in enum axes.
    * @param ax2 The second axis value as defined in enum axes.
    * @param ax3 The third axis value as defined in enum axes.
    * @returns The swizzled vector.
    */
    inline Vector4 swizzle(axes ax1, axes ax2, axes ax3) const { return Vector4(e[ax1], e[ax2], e[ax3], e[ax3]); };

    /**
    * Return swizzled vector. See https://en.wikipedia.org/wiki/Swizzling_(computer_graphics)
    * @param ax1 The first axis value as defined in enum axes.
    * @param ax2 The second axis value as defined in enum axes.
    * @param ax3 The third axis value as defined in enum axes.
    * @param ax4 The fourth axis value as defined in enum axes.
    * @returns The swizzled vector.
    */
    inline Vector4 swizzle(axes ax1, axes ax2, axes ax3, axes ax4) const { return Vector4(e[ax1], e[ax2], e[ax3], e[ax4]); };

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
    * Swizzle vector to (x,w).
    * @returns The swizzled vector.
    */
    Vector2 GetXW();

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
    * Swizzle vector to (y,w).
    * @returns The swizzled vector.
    */
    Vector2 GetYW();

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
    * Swizzle vector to (z,w).
    * @returns The swizzled vector.
    */
    Vector2 GetZW();

    /**
    * Swizzle vector to (w,x).
    * @returns The swizzled vector.
    */
    Vector2 GetWX();

    /**
    * Swizzle vector to (w,y).
    * @returns The swizzled vector.
    */
    Vector2 GetWY();

    /**
    * Swizzle vector to (w,z).
    * @returns The swizzled vector.
    */
    Vector2 GetWZ();

    /**
    * Swizzle vector to (w,w).
    * @returns The swizzled vector.
    */
    Vector2 GetWW();

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
    * Swizzle vector to (x,x,w).
    * @returns The swizzled vector.
    */
    Vector3 GetXXW();

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
    * Swizzle vector to (x,y,z).
    * @returns The swizzled vector.
    */
    Vector3 GetXYZ();

    /**
    * Swizzle vector to (x,y,w).
    * @returns The swizzled vector.
    */
    Vector3 GetXYW();

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
    * Swizzle vector to (x,z,w).
    * @returns The swizzled vector.
    */
    Vector3 GetXZW();

    /**
    * Swizzle vector to (x,w,x).
    * @returns The swizzled vector.
    */
    Vector3 GetXWX();

    /**
    * Swizzle vector to (x,w,y).
    * @returns The swizzled vector.
    */
    Vector3 GetXWY();

    /**
    * Swizzle vector to (x,w,z).
    * @returns The swizzled vector.
    */
    Vector3 GetXWZ();

    /**
    * Swizzle vector to (x,w,w).
    * @returns The swizzled vector.
    */
    Vector3 GetXWW();

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
    * Swizzle vector to (y,x,w).
    * @returns The swizzled vector.
    */
    Vector3 GetYXW();

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
    * Swizzle vector to (y,y,w).
    * @returns The swizzled vector.
    */
    Vector3 GetYYW();

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
    * Swizzle vector to (y,z,w).
    * @returns The swizzled vector.
    */
    Vector3 GetYZW();

    /**
    * Swizzle vector to (y,w,x).
    * @returns The swizzled vector.
    */
    Vector3 GetYWX();

    /**
    * Swizzle vector to (y,w,y).
    * @returns The swizzled vector.
    */
    Vector3 GetYWY();

    /**
    * Swizzle vector to (y,w,z).
    * @returns The swizzled vector.
    */
    Vector3 GetYWZ();

    /**
    * Swizzle vector to (y,w,w).
    * @returns The swizzled vector.
    */
    Vector3 GetYWW();

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
    * Swizzle vector to (z,x,w).
    * @returns The swizzled vector.
    */
    Vector3 GetZXW();

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
    * Swizzle vector to (z,y,w).
    * @returns The swizzled vector.
    */
    Vector3 GetZYW();

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
    * Swizzle vector to (z,z,w).
    * @returns The swizzled vector.
    */
    Vector3 GetZZW();

    /**
    * Swizzle vector to (z,w,x).
    * @returns The swizzled vector.
    */
    Vector3 GetZWX();

    /**
    * Swizzle vector to (z,w,y).
    * @returns The swizzled vector.
    */
    Vector3 GetZWY();

    /**
    * Swizzle vector to (z,w,z).
    * @returns The swizzled vector.
    */
    Vector3 GetZWZ();

    /**
    * Swizzle vector to (z,w,w).
    * @returns The swizzled vector.
    */
    Vector3 GetZWW();

    /**
    * Swizzle vector to (w,x,x).
    * @returns The swizzled vector.
    */
    Vector3 GetWXX();

    /**
    * Swizzle vector to (w,x,y).
    * @returns The swizzled vector.
    */
    Vector3 GetWXY();

    /**
    * Swizzle vector to (w,x,z).
    * @returns The swizzled vector.
    */
    Vector3 GetWXZ();

    /**
    * Swizzle vector to (w,x,w).
    * @returns The swizzled vector.
    */
    Vector3 GetWXW();

    /**
    * Swizzle vector to (w,y,x).
    * @returns The swizzled vector.
    */
    Vector3 GetWYX();

    /**
    * Swizzle vector to (w,y,y).
    * @returns The swizzled vector.
    */
    Vector3 GetWYY();

    /**
    * Swizzle vector to (w,y,z).
    * @returns The swizzled vector.
    */
    Vector3 GetWYZ();

    /**
    * Swizzle vector to (w,y,w).
    * @returns The swizzled vector.
    */
    Vector3 GetWYW();

    /**
    * Swizzle vector to (w,z,x).
    * @returns The swizzled vector.
    */
    Vector3 GetWZX();

    /**
    * Swizzle vector to (w,z,y).
    * @returns The swizzled vector.
    */
    Vector3 GetWZY();

    /**
    * Swizzle vector to (w,z,z).
    * @returns The swizzled vector.
    */
    Vector3 GetWZZ();

    /**
    * Swizzle vector to (w,z,w).
    * @returns The swizzled vector.
    */
    Vector3 GetWZW();

    /**
    * Swizzle vector to (w,w,x).
    * @returns The swizzled vector.
    */
    Vector3 GetWWX();

    /**
    * Swizzle vector to (w,w,y).
    * @returns The swizzled vector.
    */
    Vector3 GetWWY();

    /**
    * Swizzle vector to (w,w,z).
    * @returns The swizzled vector.
    */
    Vector3 GetWWZ();

    /**
    * Swizzle vector to (w,w,w).
    * @returns The swizzled vector.
    */
    Vector3 GetWWW();

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
    * Swizzle vector to (x,x,x,w).
    * @returns The swizzled vector.
    */
    Vector4 GetXXXW();

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
    * Swizzle vector to (x,x,y,w).
    * @returns The swizzled vector.
    */
    Vector4 GetXXYW();

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
    * Swizzle vector to (x,x,z,w).
    * @returns The swizzled vector.
    */
    Vector4 GetXXZW();

    /**
    * Swizzle vector to (x,x,w,x).
    * @returns The swizzled vector.
    */
    Vector4 GetXXWX();

    /**
    * Swizzle vector to (x,x,w,y).
    * @returns The swizzled vector.
    */
    Vector4 GetXXWY();

    /**
    * Swizzle vector to (x,x,w,z).
    * @returns The swizzled vector.
    */
    Vector4 GetXXWZ();

    /**
    * Swizzle vector to (x,x,w,w).
    * @returns The swizzled vector.
    */
    Vector4 GetXXWW();

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
    * Swizzle vector to (x,y,x,w).
    * @returns The swizzled vector.
    */
    Vector4 GetXYXW();

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
    * Swizzle vector to (x,y,y,w).
    * @returns The swizzled vector.
    */
    Vector4 GetXYYW();

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
    * Swizzle vector to (x,y,w,x).
    * @returns The swizzled vector.
    */
    Vector4 GetXYWX();

    /**
    * Swizzle vector to (x,y,w,y).
    * @returns The swizzled vector.
    */
    Vector4 GetXYWY();

    /**
    * Swizzle vector to (x,y,w,z).
    * @returns The swizzled vector.
    */
    Vector4 GetXYWZ();

    /**
    * Swizzle vector to (x,y,w,w).
    * @returns The swizzled vector.
    */
    Vector4 GetXYWW();

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
    * Swizzle vector to (x,z,x,w).
    * @returns The swizzled vector.
    */
    Vector4 GetXZXW();

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
    * Swizzle vector to (x,z,y,w).
    * @returns The swizzled vector.
    */
    Vector4 GetXZYW();

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
    * Swizzle vector to (x,z,z,w).
    * @returns The swizzled vector.
    */
    Vector4 GetXZZW();

    /**
    * Swizzle vector to (x,z,w,x).
    * @returns The swizzled vector.
    */
    Vector4 GetXZWX();

    /**
    * Swizzle vector to (x,z,w,y).
    * @returns The swizzled vector.
    */
    Vector4 GetXZWY();

    /**
    * Swizzle vector to (x,z,w,z).
    * @returns The swizzled vector.
    */
    Vector4 GetXZWZ();

    /**
    * Swizzle vector to (x,z,w,w).
    * @returns The swizzled vector.
    */
    Vector4 GetXZWW();

    /**
    * Swizzle vector to (x,w,x,x).
    * @returns The swizzled vector.
    */
    Vector4 GetXWXX();

    /**
    * Swizzle vector to (x,w,x,y).
    * @returns The swizzled vector.
    */
    Vector4 GetXWXY();

    /**
    * Swizzle vector to (x,w,x,z).
    * @returns The swizzled vector.
    */
    Vector4 GetXWXZ();

    /**
    * Swizzle vector to (x,w,x,w).
    * @returns The swizzled vector.
    */
    Vector4 GetXWXW();

    /**
    * Swizzle vector to (x,w,y,x).
    * @returns The swizzled vector.
    */
    Vector4 GetXWYX();

    /**
    * Swizzle vector to (x,w,y,y).
    * @returns The swizzled vector.
    */
    Vector4 GetXWYY();

    /**
    * Swizzle vector to (x,w,y,z).
    * @returns The swizzled vector.
    */
    Vector4 GetXWYZ();

    /**
    * Swizzle vector to (x,w,y,w).
    * @returns The swizzled vector.
    */
    Vector4 GetXWYW();

    /**
    * Swizzle vector to (x,w,z,x).
    * @returns The swizzled vector.
    */
    Vector4 GetXWZX();

    /**
    * Swizzle vector to (x,w,z,y).
    * @returns The swizzled vector.
    */
    Vector4 GetXWZY();

    /**
    * Swizzle vector to (x,w,z,z).
    * @returns The swizzled vector.
    */
    Vector4 GetXWZZ();

    /**
    * Swizzle vector to (x,w,z,w).
    * @returns The swizzled vector.
    */
    Vector4 GetXWZW();

    /**
    * Swizzle vector to (x,w,w,x).
    * @returns The swizzled vector.
    */
    Vector4 GetXWWX();

    /**
    * Swizzle vector to (x,w,w,y).
    * @returns The swizzled vector.
    */
    Vector4 GetXWWY();

    /**
    * Swizzle vector to (x,w,w,z).
    * @returns The swizzled vector.
    */
    Vector4 GetXWWZ();

    /**
    * Swizzle vector to (x,w,w,w).
    * @returns The swizzled vector.
    */
    Vector4 GetXWWW();

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
    * Swizzle vector to (y,x,x,w).
    * @returns The swizzled vector.
    */
    Vector4 GetYXXW();

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
    * Swizzle vector to (y,x,y,w).
    * @returns The swizzled vector.
    */
    Vector4 GetYXYW();

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
    * Swizzle vector to (y,x,z,w).
    * @returns The swizzled vector.
    */
    Vector4 GetYXZW();

    /**
    * Swizzle vector to (y,x,w,x).
    * @returns The swizzled vector.
    */
    Vector4 GetYXWX();

    /**
    * Swizzle vector to (y,x,w,y).
    * @returns The swizzled vector.
    */
    Vector4 GetYXWY();

    /**
    * Swizzle vector to (y,x,w,z).
    * @returns The swizzled vector.
    */
    Vector4 GetYXWZ();

    /**
    * Swizzle vector to (y,x,w,w).
    * @returns The swizzled vector.
    */
    Vector4 GetYXWW();

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
    * Swizzle vector to (y,y,x,w).
    * @returns The swizzled vector.
    */
    Vector4 GetYYXW();

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
    * Swizzle vector to (y,y,y,w).
    * @returns The swizzled vector.
    */
    Vector4 GetYYYW();

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
    * Swizzle vector to (y,y,z,w).
    * @returns The swizzled vector.
    */
    Vector4 GetYYZW();

    /**
    * Swizzle vector to (y,y,w,x).
    * @returns The swizzled vector.
    */
    Vector4 GetYYWX();

    /**
    * Swizzle vector to (y,y,w,y).
    * @returns The swizzled vector.
    */
    Vector4 GetYYWY();

    /**
    * Swizzle vector to (y,y,w,z).
    * @returns The swizzled vector.
    */
    Vector4 GetYYWZ();

    /**
    * Swizzle vector to (y,y,w,w).
    * @returns The swizzled vector.
    */
    Vector4 GetYYWW();

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
    * Swizzle vector to (y,z,x,w).
    * @returns The swizzled vector.
    */
    Vector4 GetYZXW();

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
    * Swizzle vector to (y,z,y,w).
    * @returns The swizzled vector.
    */
    Vector4 GetYZYW();

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
    * Swizzle vector to (y,z,z,w).
    * @returns The swizzled vector.
    */
    Vector4 GetYZZW();

    /**
    * Swizzle vector to (y,z,w,x).
    * @returns The swizzled vector.
    */
    Vector4 GetYZWX();

    /**
    * Swizzle vector to (y,z,w,y).
    * @returns The swizzled vector.
    */
    Vector4 GetYZWY();

    /**
    * Swizzle vector to (y,z,w,z).
    * @returns The swizzled vector.
    */
    Vector4 GetYZWZ();

    /**
    * Swizzle vector to (y,z,w,w).
    * @returns The swizzled vector.
    */
    Vector4 GetYZWW();

    /**
    * Swizzle vector to (y,w,x,x).
    * @returns The swizzled vector.
    */
    Vector4 GetYWXX();

    /**
    * Swizzle vector to (y,w,x,y).
    * @returns The swizzled vector.
    */
    Vector4 GetYWXY();

    /**
    * Swizzle vector to (y,w,x,z).
    * @returns The swizzled vector.
    */
    Vector4 GetYWXZ();

    /**
    * Swizzle vector to (y,w,x,w).
    * @returns The swizzled vector.
    */
    Vector4 GetYWXW();

    /**
    * Swizzle vector to (y,w,y,x).
    * @returns The swizzled vector.
    */
    Vector4 GetYWYX();

    /**
    * Swizzle vector to (y,w,y,y).
    * @returns The swizzled vector.
    */
    Vector4 GetYWYY();

    /**
    * Swizzle vector to (y,w,y,z).
    * @returns The swizzled vector.
    */
    Vector4 GetYWYZ();

    /**
    * Swizzle vector to (y,w,y,w).
    * @returns The swizzled vector.
    */
    Vector4 GetYWYW();

    /**
    * Swizzle vector to (y,w,z,x).
    * @returns The swizzled vector.
    */
    Vector4 GetYWZX();

    /**
    * Swizzle vector to (y,w,z,y).
    * @returns The swizzled vector.
    */
    Vector4 GetYWZY();

    /**
    * Swizzle vector to (y,w,z,z).
    * @returns The swizzled vector.
    */
    Vector4 GetYWZZ();

    /**
    * Swizzle vector to (y,w,z,w).
    * @returns The swizzled vector.
    */
    Vector4 GetYWZW();

    /**
    * Swizzle vector to (y,w,w,x).
    * @returns The swizzled vector.
    */
    Vector4 GetYWWX();

    /**
    * Swizzle vector to (y,w,w,y).
    * @returns The swizzled vector.
    */
    Vector4 GetYWWY();

    /**
    * Swizzle vector to (y,w,w,z).
    * @returns The swizzled vector.
    */
    Vector4 GetYWWZ();

    /**
    * Swizzle vector to (y,w,w,w).
    * @returns The swizzled vector.
    */
    Vector4 GetYWWW();

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
    * Swizzle vector to (z,x,x,w).
    * @returns The swizzled vector.
    */
    Vector4 GetZXXW();

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
    * Swizzle vector to (z,x,y,w).
    * @returns The swizzled vector.
    */
    Vector4 GetZXYW();

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
    * Swizzle vector to (z,x,z,w).
    * @returns The swizzled vector.
    */
    Vector4 GetZXZW();

    /**
    * Swizzle vector to (z,x,w,x).
    * @returns The swizzled vector.
    */
    Vector4 GetZXWX();

    /**
    * Swizzle vector to (z,x,w,y).
    * @returns The swizzled vector.
    */
    Vector4 GetZXWY();

    /**
    * Swizzle vector to (z,x,w,z).
    * @returns The swizzled vector.
    */
    Vector4 GetZXWZ();

    /**
    * Swizzle vector to (z,x,w,w).
    * @returns The swizzled vector.
    */
    Vector4 GetZXWW();

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
    * Swizzle vector to (z,y,x,w).
    * @returns The swizzled vector.
    */
    Vector4 GetZYXW();

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
    * Swizzle vector to (z,y,y,w).
    * @returns The swizzled vector.
    */
    Vector4 GetZYYW();

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
    * Swizzle vector to (z,y,z,w).
    * @returns The swizzled vector.
    */
    Vector4 GetZYZW();

    /**
    * Swizzle vector to (z,y,w,x).
    * @returns The swizzled vector.
    */
    Vector4 GetZYWX();

    /**
    * Swizzle vector to (z,y,w,y).
    * @returns The swizzled vector.
    */
    Vector4 GetZYWY();

    /**
    * Swizzle vector to (z,y,w,z).
    * @returns The swizzled vector.
    */
    Vector4 GetZYWZ();

    /**
    * Swizzle vector to (z,y,w,w).
    * @returns The swizzled vector.
    */
    Vector4 GetZYWW();

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
    * Swizzle vector to (z,z,x,w).
    * @returns The swizzled vector.
    */
    Vector4 GetZZXW();

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
    * Swizzle vector to (z,z,y,w).
    * @returns The swizzled vector.
    */
    Vector4 GetZZYW();

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

    /**
    * Swizzle vector to (z,z,z,w).
    * @returns The swizzled vector.
    */
    Vector4 GetZZZW();

    /**
    * Swizzle vector to (z,z,w,x).
    * @returns The swizzled vector.
    */
    Vector4 GetZZWX();

    /**
    * Swizzle vector to (z,z,w,y).
    * @returns The swizzled vector.
    */
    Vector4 GetZZWY();

    /**
    * Swizzle vector to (z,z,w,z).
    * @returns The swizzled vector.
    */
    Vector4 GetZZWZ();

    /**
    * Swizzle vector to (z,z,w,w).
    * @returns The swizzled vector.
    */
    Vector4 GetZZWW();

    /**
    * Swizzle vector to (z,w,x,x).
    * @returns The swizzled vector.
    */
    Vector4 GetZWXX();

    /**
    * Swizzle vector to (z,w,x,y).
    * @returns The swizzled vector.
    */
    Vector4 GetZWXY();

    /**
    * Swizzle vector to (z,w,x,z).
    * @returns The swizzled vector.
    */
    Vector4 GetZWXZ();

    /**
    * Swizzle vector to (z,w,x,w).
    * @returns The swizzled vector.
    */
    Vector4 GetZWXW();

    /**
    * Swizzle vector to (z,w,y,x).
    * @returns The swizzled vector.
    */
    Vector4 GetZWYX();

    /**
    * Swizzle vector to (z,w,y,y).
    * @returns The swizzled vector.
    */
    Vector4 GetZWYY();

    /**
    * Swizzle vector to (z,w,y,z).
    * @returns The swizzled vector.
    */
    Vector4 GetZWYZ();

    /**
    * Swizzle vector to (z,w,y,w).
    * @returns The swizzled vector.
    */
    Vector4 GetZWYW();

    /**
    * Swizzle vector to (z,w,z,x).
    * @returns The swizzled vector.
    */
    Vector4 GetZWZX();

    /**
    * Swizzle vector to (z,w,z,y).
    * @returns The swizzled vector.
    */
    Vector4 GetZWZY();

    /**
    * Swizzle vector to (z,w,z,z).
    * @returns The swizzled vector.
    */
    Vector4 GetZWZZ();

    /**
    * Swizzle vector to (z,w,z,w).
    * @returns The swizzled vector.
    */
    Vector4 GetZWZW();

    /**
    * Swizzle vector to (z,w,w,x).
    * @returns The swizzled vector.
    */
    Vector4 GetZWWX();

    /**
    * Swizzle vector to (z,w,w,y).
    * @returns The swizzled vector.
    */
    Vector4 GetZWWY();

    /**
    * Swizzle vector to (z,w,w,z).
    * @returns The swizzled vector.
    */
    Vector4 GetZWWZ();

    /**
    * Swizzle vector to (z,w,w,w).
    * @returns The swizzled vector.
    */
    Vector4 GetZWWW();

    /**
    * Swizzle vector to (w,x,x,x).
    * @returns The swizzled vector.
    */
    Vector4 GetWXXX();

    /**
    * Swizzle vector to (w,x,x,y).
    * @returns The swizzled vector.
    */
    Vector4 GetWXXY();

    /**
    * Swizzle vector to (w,x,x,z).
    * @returns The swizzled vector.
    */
    Vector4 GetWXXZ();

    /**
    * Swizzle vector to (w,x,x,w).
    * @returns The swizzled vector.
    */
    Vector4 GetWXXW();

    /**
    * Swizzle vector to (w,x,y,x).
    * @returns The swizzled vector.
    */
    Vector4 GetWXYX();

    /**
    * Swizzle vector to (w,x,y,y).
    * @returns The swizzled vector.
    */
    Vector4 GetWXYY();

    /**
    * Swizzle vector to (w,x,y,z).
    * @returns The swizzled vector.
    */
    Vector4 GetWXYZ();

    /**
    * Swizzle vector to (w,x,y,w).
    * @returns The swizzled vector.
    */
    Vector4 GetWXYW();

    /**
    * Swizzle vector to (w,x,z,x).
    * @returns The swizzled vector.
    */
    Vector4 GetWXZX();

    /**
    * Swizzle vector to (w,x,z,y).
    * @returns The swizzled vector.
    */
    Vector4 GetWXZY();

    /**
    * Swizzle vector to (w,x,z,z).
    * @returns The swizzled vector.
    */
    Vector4 GetWXZZ();

    /**
    * Swizzle vector to (w,x,z,w).
    * @returns The swizzled vector.
    */
    Vector4 GetWXZW();

    /**
    * Swizzle vector to (w,x,w,x).
    * @returns The swizzled vector.
    */
    Vector4 GetWXWX();

    /**
    * Swizzle vector to (w,x,w,y).
    * @returns The swizzled vector.
    */
    Vector4 GetWXWY();

    /**
    * Swizzle vector to (w,x,w,z).
    * @returns The swizzled vector.
    */
    Vector4 GetWXWZ();

    /**
    * Swizzle vector to (w,x,w,w).
    * @returns The swizzled vector.
    */
    Vector4 GetWXWW();

    /**
    * Swizzle vector to (w,y,x,x).
    * @returns The swizzled vector.
    */
    Vector4 GetWYXX();

    /**
    * Swizzle vector to (w,y,x,y).
    * @returns The swizzled vector.
    */
    Vector4 GetWYXY();

    /**
    * Swizzle vector to (w,y,x,z).
    * @returns The swizzled vector.
    */
    Vector4 GetWYXZ();

    /**
    * Swizzle vector to (w,y,x,w).
    * @returns The swizzled vector.
    */
    Vector4 GetWYXW();

    /**
    * Swizzle vector to (w,y,y,x).
    * @returns The swizzled vector.
    */
    Vector4 GetWYYX();

    /**
    * Swizzle vector to (w,y,y,y).
    * @returns The swizzled vector.
    */
    Vector4 GetWYYY();

    /**
    * Swizzle vector to (w,y,y,z).
    * @returns The swizzled vector.
    */
    Vector4 GetWYYZ();

    /**
    * Swizzle vector to (w,y,y,w).
    * @returns The swizzled vector.
    */
    Vector4 GetWYYW();

    /**
    * Swizzle vector to (w,y,z,x).
    * @returns The swizzled vector.
    */
    Vector4 GetWYZX();

    /**
    * Swizzle vector to (w,y,z,y).
    * @returns The swizzled vector.
    */
    Vector4 GetWYZY();

    /**
    * Swizzle vector to (w,y,z,z).
    * @returns The swizzled vector.
    */
    Vector4 GetWYZZ();

    /**
    * Swizzle vector to (w,y,z,w).
    * @returns The swizzled vector.
    */
    Vector4 GetWYZW();

    /**
    * Swizzle vector to (w,y,w,x).
    * @returns The swizzled vector.
    */
    Vector4 GetWYWX();

    /**
    * Swizzle vector to (w,y,w,y).
    * @returns The swizzled vector.
    */
    Vector4 GetWYWY();

    /**
    * Swizzle vector to (w,y,w,z).
    * @returns The swizzled vector.
    */
    Vector4 GetWYWZ();

    /**
    * Swizzle vector to (w,y,w,w).
    * @returns The swizzled vector.
    */
    Vector4 GetWYWW();

    /**
    * Swizzle vector to (w,z,x,x).
    * @returns The swizzled vector.
    */
    Vector4 GetWZXX();

    /**
    * Swizzle vector to (w,z,x,y).
    * @returns The swizzled vector.
    */
    Vector4 GetWZXY();

    /**
    * Swizzle vector to (w,z,x,z).
    * @returns The swizzled vector.
    */
    Vector4 GetWZXZ();

    /**
    * Swizzle vector to (w,z,x,w).
    * @returns The swizzled vector.
    */
    Vector4 GetWZXW();

    /**
    * Swizzle vector to (w,z,y,x).
    * @returns The swizzled vector.
    */
    Vector4 GetWZYX();

    /**
    * Swizzle vector to (w,z,y,y).
    * @returns The swizzled vector.
    */
    Vector4 GetWZYY();

    /**
    * Swizzle vector to (w,z,y,z).
    * @returns The swizzled vector.
    */
    Vector4 GetWZYZ();

    /**
    * Swizzle vector to (w,z,y,w).
    * @returns The swizzled vector.
    */
    Vector4 GetWZYW();

    /**
    * Swizzle vector to (w,z,z,x).
    * @returns The swizzled vector.
    */
    Vector4 GetWZZX();

    /**
    * Swizzle vector to (w,z,z,y).
    * @returns The swizzled vector.
    */
    Vector4 GetWZZY();

    /**
    * Swizzle vector to (w,z,z,z).
    * @returns The swizzled vector.
    */
    Vector4 GetWZZZ();

    /**
    * Swizzle vector to (w,z,z,w).
    * @returns The swizzled vector.
    */
    Vector4 GetWZZW();

    /**
    * Swizzle vector to (w,z,w,x).
    * @returns The swizzled vector.
    */
    Vector4 GetWZWX();

    /**
    * Swizzle vector to (w,z,w,y).
    * @returns The swizzled vector.
    */
    Vector4 GetWZWY();

    /**
    * Swizzle vector to (w,z,w,z).
    * @returns The swizzled vector.
    */
    Vector4 GetWZWZ();

    /**
    * Swizzle vector to (w,z,w,w).
    * @returns The swizzled vector.
    */
    Vector4 GetWZWW();

    /**
    * Swizzle vector to (w,w,x,x).
    * @returns The swizzled vector.
    */
    Vector4 GetWWXX();

    /**
    * Swizzle vector to (w,w,x,y).
    * @returns The swizzled vector.
    */
    Vector4 GetWWXY();

    /**
    * Swizzle vector to (w,w,x,z).
    * @returns The swizzled vector.
    */
    Vector4 GetWWXZ();

    /**
    * Swizzle vector to (w,w,x,w).
    * @returns The swizzled vector.
    */
    Vector4 GetWWXW();

    /**
    * Swizzle vector to (w,w,y,x).
    * @returns The swizzled vector.
    */
    Vector4 GetWWYX();

    /**
    * Swizzle vector to (w,w,y,y).
    * @returns The swizzled vector.
    */
    Vector4 GetWWYY();

    /**
    * Swizzle vector to (w,w,y,z).
    * @returns The swizzled vector.
    */
    Vector4 GetWWYZ();

    /**
    * Swizzle vector to (w,w,y,w).
    * @returns The swizzled vector.
    */
    Vector4 GetWWYW();

    /**
    * Swizzle vector to (w,w,z,x).
    * @returns The swizzled vector.
    */
    Vector4 GetWWZX();

    /**
    * Swizzle vector to (w,w,z,y).
    * @returns The swizzled vector.
    */
    Vector4 GetWWZY();

    /**
    * Swizzle vector to (w,w,z,z).
    * @returns The swizzled vector.
    */
    Vector4 GetWWZZ();

    /**
    * Swizzle vector to (w,w,z,w).
    * @returns The swizzled vector.
    */
    Vector4 GetWWZW();

    /**
    * Swizzle vector to (w,w,w,x).
    * @returns The swizzled vector.
    */
    Vector4 GetWWWX();

    /**
    * Swizzle vector to (w,w,w,y).
    * @returns The swizzled vector.
    */
    Vector4 GetWWWY();

    /**
    * Swizzle vector to (w,w,w,z).
    * @returns The swizzled vector.
    */
    Vector4 GetWWWZ();

    /**
    * Swizzle vector to (w,w,w,w).
    * @returns The swizzled vector.
    */
    Vector4 GetWWWW();

#pragma endregion

};