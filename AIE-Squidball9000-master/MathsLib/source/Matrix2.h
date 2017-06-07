#pragma once
#include "DllExport.h"
#include "RealType.h"
#include "MathsTools.h"
#include <vector>
#include <math.h>
#include "Vector2.h"

/**
* A Matrix class that provides essential matrix data storage and functions.
* @author Ashley Flynn - AIE - 2017
*/

class DLL Matrix2
{
   
public:

	/**
	* Define matrix size.
	*/
	static const int SIZE = 4; //Number of elements in the matrix.
	static const int ROWS = 2; //Number of rows in the matrix.
	static const int COLS = 2; //Number of columns in the matrix.

	/**
	* Store matrix values as vectors.
	*/
    Vector2 v[ROWS];

    /**
    * Constructor.
    */
    Matrix2();

    /**
    * Constructor with ability to set matrix element values.
    * @param newX1 The x1 value to set for the matrix.
    * @param newX2 The x2 value to set for the matrix.
    * @param newY1 The y1 value to set for the matrix.
    * @param newY2 The y2 value to set for the matrix.
    */
    Matrix2(real x1, real x2, real y1, real y2);

    /**
    * Copy constructor.
    * @param other The matrix to copy
    */
    Matrix2(const Matrix2 &other);

    /**
    * Destructor.
    */
    ~Matrix2();

	/**
	* Assignment operator overload.
	* @params other The matrix to copy from.
	* @returns Reference to the new matrix.
	*/
	Matrix2 &Matrix2::operator=(const Matrix2 &other);

    /**
    * Cast to float pointer operator overload.
    * @returns A pointer to the first float in the first vector.
    */
    inline operator real *() { return &v[0][0]; };

    /**
    * Transform a vector using this matrix.
    * @param other The vector to use.
    * @returns The resulting vector.
    */
    Vector2 operator* (const Vector2 &other) const;

    /**
    * Concatenate this matrix with another.
    * @param other The other matrix to use.
    * @returns The resulting matrix.
    */
    Matrix2 operator* (const Matrix2 &other) const;

    /**
    * Multiply this matrix by a scalar.
    * @returns void.
    */
    Matrix2 operator* (real scalar);

    /**
    * Multiply this matrix by a scalar.
    * @returns void.
    */
    inline void operator*= (real scalar) { *this = *this * scalar; };

    /**
    * Get or Set the Nth vector of the matrix.
    * Eg: Vector2 myVector = myMatrix[0]; myMatrix[0] = myVector;
    * @param The element number to set.
    * @returns A reference to the requested vector.
    */
    Vector2 &operator[] (const int n);

    /**
    * Get the Nth element of the matrix. CONST SAFE overload.
    * Eg: Vector2 myVector = myMatrix[0];
    * @param The element number to return.
    * @returns The requested vector.
    */
    const Vector2 operator[] (const int n) const;

    /**
    * Set scale using a vector.
    * @params scale The vector to use for scale values.
    * @returns void.
    */
    void setScale(const Vector2 &scale);

    /**
    * Change scale using a vector.
    * @params scale The vector to use for scale values.
    * @returns void.
    */
    void scale(const Vector2 &scale);

	/**
	* Change scale of X a vector.
	* @params scale The scalar to change scale by.
	* @returns void.
	*/
	void scaleX(real scalar);

	/**
	* Change scale of Y a vector.
	* @params scale The scalar to change scale by.
	* @returns void.
	*/
	void scaleY(real scalar);

    /**
    * Set rotation in RADIANS for the matrix.
	* Alternate name to call setRotateZ.
    * @param rot The rotation amount in RADIANS.
    * @returns void.
    */
    inline void setRotate(real radians) { setRotateZ(radians); };

	/**
	* Set rotation in RADIANS for the matrix.
	* @param rot The rotation amount in RADIANS.
	* @returns void.
	*/
	void setRotateZ(real radians);

	/**
	* Set rotation around Z dimension in DEGREES for the matrix.
	* @param rot The rotation amount in DEGREES.
	* @returns void.
	*/
	inline void setRotateDeg(real degrees) { setRotateZ(MathsLib::deg2rad(degrees)); };

	/**
	* Set rotation around Z dimension in DEGREES for the matrix.
	* @param rot The rotation amount in DEGREES.
	* @returns void.
	*/
	inline void setRotateZDeg(real degrees) { setRotateZ(MathsLib::deg2rad(degrees)); };

	/**
	* Add rotation in RADIANS to existing Z rotation.
	* @params radians The RADIANS to add.
	* @returns void.
	*/
	void rotateZ(float radians);

	/**
	* Add rotation in DEGREES to existing Z rotation.
	* @params radians The DEGREES to add.
	* @returns void.
	*/
	inline void rotateZDeg(float degrees) { rotateZ(MathsLib::deg2rad(degrees)); };

    /**
    * Transpose this matrix.
    * @returns void;
    */
    void transpose();

    /**
    * Get the inverted form of this matrix.
    * @returns The inverted matrix.
    */
    Matrix2 inverted() const;

    /**
    * Invert this matrix.
    * @returns void.
    */
    void invert();

    /**
    * Get the determinant of this matrix.
    * @returns The determinant of this matrix.
    */
    real determinant() const;

	/**
	* Get the rotation component of this matrix in RADIANS.
	* Uses Matrix Decomposition to determine the value.
	* Alternate name to call getRotateZ.
	* @returns The rotation in RADIANS.
	*/
	inline real getRotate() const { return getRotateZ(); };

	/**
	* Get the rotation component of this matrix in DEGREES.
	* Uses Matrix Decomposition to determine the value.
	* Alternate name to call getRotateZDeg.
	* @returns The rotation in DEGREES.
	*/
	inline real getRotateDeg() const { return getRotateZDeg(); };

	/**
	* Get the rotation component of this matrix in RADIANS.
	* Uses Matrix Decomposition to determine the value.
	* @returns The rotation in RADIANS.
	*/
	real getRotateZ() const;

	/**
	* Get the rotation component of this matrix in DEGREES.
	* Uses Matrix Decomposition to determine the value.
	* @returns The rotation in DEGREES.
	*/
	inline real getRotateZDeg() const { return MathsLib::rad2deg(getRotateZ()); };

	/**
	* Get the scale component of this matrix.
	* Uses Matrix Decomposition to determine the value.
	* @returns A vector of the scale.
	*/
	Vector2 getScale() const;

};