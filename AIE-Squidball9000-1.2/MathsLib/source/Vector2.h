#pragma once
#include "DllExport.h"
#include "RealType.h"
#include "MathsTools.h"
#include <vector>
#include <math.h>

/**
* Forward declarations.
*/
class Vector3;
class Vector4;

/**
* A Vector class that provides essential vector data storage and functions.
* @author Ashley Flynn - AIE - 2017
*/

class DLL Vector2
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
		struct { real x, y; };
        real e[2]; //Elements as a single list of numbers.
	};

    /**
    * Enum of all axis names.
    */
    enum axes { X, Y };

	/**
	* Define the number of elements in this vector.
	* Defined via a function as we can't add member variables to this class.
	* See note about byte alignment.
	* @returns The number of elements in this vector.
	*/
	const inline int getSize() const { return 2; };

	/**
	* Define the number of rows in this vector.
	* Defined via a function as we can't add member variables to this class.
	* See note about byte alignment.
	* @returns The number of rows in this vector.
	*/
	const inline int getRows() const { return 2; };

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
    Vector2();

    /**
    * Constructor with preset x and y coords.
    * @param newX The x value to set for the vector.
    * @param newY The y value to set for the vector.
    */
    Vector2(real newX, real newY);

    /**
    * Copy constructor.
    * @param other The vector to copy.
    */
    Vector2(const Vector2 &other);

    /**
    * Destructor.
    */
    ~Vector2();

	/**
	* Cast to float pointer operator overload.
    * @returns A pointer to the first float in the vector. 
	*/
    inline operator real *() { return &x; }

	/**
	* Cast to Vector3.
	* @returns A new Vector3 created from the x and y axes of the Vector2, with 1.0 as the z axis.
	*/
	operator Vector3();

	/**
	* Cast to Vector4.
	* @returns A new Vector4 created from the x and y axes of the Vector2, with 1.0 as the z and w axes.
	*/
	operator Vector4();

    /**
    * Multiply vector by -1.
    * @returns The new vector.
    */
    Vector2 operator- () const;

	/**
	* Copy data from another vector to this vector.
	* @param other The vector to copy from.
	* @returns A reference to the vector.
	*/
	Vector2 &operator= (const Vector2 &other);

    /**
    * Translate a point by a vector using addition.
    * @param other The vector to translate the point by.
    * @returns The new point.
    */
    Vector2 operator+ (const Vector2 &other) const;

    /**
    * Translate this point by a vector using addition.
    * @param other The vector to translate the point by.
    * @returns void.
    */
    void operator+= (const Vector2 &other);

    /**
    * Translate a point by a vector using subtraction.
    * @param other The vector to translate the point by.
    * @returns The new point.
    */
    Vector2 operator- (const Vector2 &other) const;

    /**
    * Translate this point by a vector using subtraction.
    * @param other The vector to translate the point by.
    * @returns void.
    */
    void operator-= (const Vector2 &other);

    /**
    * Multiply this vector by a scalar.
    * @param scalar The scalar to multiply this vector by.
    * @returns The new vector.
    */
    Vector2 operator* (real scalar) const;

	/**
	* Divide this vector by a scalar.
	* @param scalar The scalar to divide this vector by.
	* @returns The new vector.
	*/
	Vector2 operator/ (real scalar) const;

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
    friend inline Vector2 operator* (real scalar, const Vector2 &vector) { return vector * scalar; };

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
    real getAngleBetween(const Vector2 &other) const;

    /**
    * Get the angle between this vector and another in DEGREES.
    * @params other The other vector to compare against.
    * @returns The angle between the vectors.
    */
    inline real getAngleBetweenDeg(const Vector2 &other) const { return getAngleBetween(other) * (180.0f / PI); };

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
    Vector2 normalised() const;

    /**
    * Get the dot product of this vector and another vector.
    * @param other The other vector to dot product with this vector.
    * @returns The dot product of the two vectors.
    */
    real dot(const Vector2 &other) const;

	/**
	* Get the 2D cross product of this vector and another.
	* http://www.randygaul.net/2013/03/27/game-physics-engine-part-1-impulse-resolution/
	* See "Cross two vectors in 2D".
	* Note that the value returns as a float, not a vector.
	* @params other The other vector to cross with this vector.
	* @returns The float value of the cross product.
	*/
    real cross(const Vector2 &other) const;

	/**
	* Get the 2D cross product of this vector times a float.
	* http://www.randygaul.net/2013/03/27/game-physics-engine-part-1-impulse-resolution/
	* See "Cross two vectors in 2D".
	* @params other The float to cross with this vector.
	* @returns The vector of the cross product.
	*/
	inline Vector2 crossVecFloat(float a) const { return Vector2(a * y, -a * x); }

	/**
	* Get the 2D cross product of a float times this vector.
	* http://www.randygaul.net/2013/03/27/game-physics-engine-part-1-impulse-resolution/
	* See "Cross two vectors in 2D".
	* @params other The float to cross with this vector.
	* @returns The vector of the cross product.
	*/
	inline Vector2 crossFloatVec(float a) const { return Vector2(-a * y, a * x); }

    /**
    * Return swizzled vector. See https://en.wikipedia.org/wiki/Swizzling_(computer_graphics)
    * @param ax1 The first axis value as defined in enum axes.
    * @returns The swizzled vector.
    */
    inline Vector2 swizzle(axes ax1) const { return Vector2(e[ax1], e[ax1]); };

    /**
    * Return swizzled vector. See https://en.wikipedia.org/wiki/Swizzling_(computer_graphics)
    * @param ax1 The first axis value as defined in enum axes.
    * @param ax2 The second axis value as defined in enum axes.
    * @returns The swizzled vector.
    */
    inline Vector2 swizzle(axes ax1, axes ax2) const { return Vector2(e[ax1], e[ax2]); };

#pragma region swizzleDecs
    
    /**
    * Swizzle vector to (x,x).
    * @returns The swizzled vector.
    */
    Vector2 GetXX();

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
    * Swizzle vector to (y,y,y,x).
    * @returns The swizzled vector.
    */
    Vector4 GetYYYX();

    /**
    * Swizzle vector to (y,y,y,y).
    * @returns The swizzled vector.
    */
    Vector4 GetYYYY();

#pragma endregion

};