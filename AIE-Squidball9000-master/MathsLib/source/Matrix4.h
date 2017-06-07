#pragma once
#include "DllExport.h"
#include "RealType.h"
#include "MathsTools.h"
#include <vector>
#include <math.h>
#include "Vector4.h"
#include "Vector3.h"

/**
* A Matrix class that provides essential matrix data storage and functions.
* @author Ashley Flynn - AIE - 2017
*/

class DLL Matrix4
{

public:

    /**
    * Define matrix size.
    */
    static const int SIZE = 16; //Number of elements in the matrix.
    static const int ROWS = 4; //Number of rows in the matrix.
    static const int COLS = 4; //Number of columns in the matrix.

	/**
	* Store matrix values as vectors.
	*/
    Vector4 v[ROWS];

    /**
    * Constructor.
    */
    Matrix4();

    /**
    * Constructor with ability to set matrix element values.
    * @param newX1 The x1 value to set for the matrix.
    * @param newX2 The x2 value to set for the matrix.
    * @param newX3 The x3 value to set for the matrix.
	* @param newX3 The x4 value to set for the matrix.
    * @param newY1 The y1 value to set for the matrix.
    * @param newY2 The y2 value to set for the matrix.
    * @param newY3 The y3 value to set for the matrix.
	* @param newY3 The y4 value to set for the matrix.
    * @param newZ1 The z1 value to set for the matrix.
    * @param newZ2 The z2 value to set for the matrix.
    * @param newZ3 The z3 value to set for the matrix.
	* @param newZ3 The z4 value to set for the matrix.
	* @param newW1 The w1 value to set for the matrix.
	* @param newW2 The w2 value to set for the matrix.
	* @param newW3 The w3 value to set for the matrix.
	* @param newW3 The w4 value to set for the matrix.
    */
    Matrix4(real newX1, real newX2, real newX3, real newX4,
		real newY1, real newY2, real newY3, real newY4, 
		real newZ1, real newZ2, real newZ3, real newZ4,
		real newW1, real newW2, real newW3, real newW4 );

    /**
    * Copy constructor.
    * @param other The matrix to copy
    */
    Matrix4(const Matrix4 &other);

    /**
    * Destructor.
    */
    ~Matrix4();
	
	/**
	* Assignment operator overload.
	* @params other The matrix to copy from.
	* @returns Reference to the new matrix.
	*/
	Matrix4 &Matrix4::operator=(const Matrix4 &other);

    /**
    * Cast to float pointer operator overload.
    * @returns A pointer to the first float in the first vector.
    */
    inline operator real *() { return &v[0][0]; };

    /**
    * Transform a vector4 using this matrix.
    * @param other The vector4 to use.
    * @returns The resulting vector4.
    */
    Vector4 operator* (const Vector4 &other) const;

	/**
	* Transform a vector3 using this matrix.
	* @param other The vector3 to use.
	* @returns The resulting vector3.
	*/
	Vector3 operator* (const Vector3 &other) const;

    /**
    * Concatenate this matrix with another.
    * @param other The other matrix to use.
    * @returns The resulting matrix.
    */
    Matrix4 operator* (const Matrix4 &other) const;

    /**
    * Multiply this matrix by a scalar.
    * @returns void.
    */
    Matrix4 operator* (real scalar);

    /**
    * Multiply this matrix by a scalar.
    * @returns void.
    */
    inline void operator*= (real scalar) { *this = *this * scalar; };

    /**
    * Get or Set the Nth vector of the matrix.
    * Eg: Vector3 myVector = myMatrix[0]; myMatrix[0] = myVector;
    * @param The element number to set.
    * @returns A reference to the requested vector.
    */
	Vector4 &operator[] (const int n);

    /**
    * Get the Nth element of the matrix. CONST SAFE overload.
    * Eg: Vector3 myVector = myMatrix[0];
    * @param The element number to return.
    * @returns The requested vector.
    */
    const Vector4 operator[] (const int n) const;

    /**
    * Change rotation values in this matrix to look at another matrix position.
	* This is for manipulating 3D transforms via a Matrix4.
    * @params other The other matrix to look at.
    * @returns void.
    */
    inline void Matrix4::lookAt(const Matrix4 &other) { Vector3 at = other * Vector3(); lookAt(at); };

    /**
    * Change rotation values in this matrix to look at a vector coordinate.
	* This is for manipulating 3D transforms via a Matrix4.
    * @params other The vector coordinates to look at.
    * @returns void.
    */
    void Matrix4::lookAt(const Vector3 &at);

    /**
    * Set scale using a vector.
    * @params scale The vector to use for scale values.
    * @returns void.
    */
    void setScale(const Vector4 &scale);

    /**
    * Change scale using a vector.
    * @params scale The vector to use for scale values.
    * @returns void.
    */
    void scale(const Vector4 &scale);

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
	* Change scale of Z a vector.
	* @params scale The scalar to change scale by.
	* @returns void.
	*/
	void scaleZ(real scalar);

	/**
	* Change scale of W a vector.
	* @params scale The scalar to change scale by.
	* @returns void.
	*/
	void scaleW(real scalar);

	/**
	* Set rotation around X dimension in RADIANS for the matrix.
	* @param rot The rotation amount in RADIANS.
	* @returns void.
	*/
	void setRotateX(real radians);

	/**
	* Set rotation around X dimension in DEGREES for the matrix.
	* @param rot The rotation amount in DEGREES.
	* @returns void.
	*/
	inline void setRotateXDeg(real degrees) { return setRotateX(MathsLib::deg2rad(degrees)); };

	/**
	* Set rotation around Y dimension in RADIANS for the matrix.
	* @param rot The rotation amount in RADIANS.
	* @returns void.
	*/
	void setRotateY(real radians);

	/**
	* Set rotation around Y dimension in DEGREES for the matrix.
	* @param rot The rotation amount in DEGREES.
	* @returns void.
	*/
	inline void setRotateYDeg(real degrees) { return setRotateY(MathsLib::deg2rad(degrees)); };

	/**
	* Set rotation around Z dimension in RADIANS for the matrix.
	* @param rot The rotation amount in RADIANS.
	* @returns void.
	*/
	void setRotateZ(real radians);

	/**
	* Set rotation around Z dimension in DEGREES for the matrix.
	* @param rot The rotation amount in DEGREES.
	* @returns void.
	*/
	inline void setRotateZDeg(real degrees) { return setRotateZ(MathsLib::deg2rad(degrees)); };

    /**
    * Set rotation around all dimension in RADIANS for the matrix using a vector.
    * @param radians A vector of the RADIANS for each axis.
    * @returns void.
    */
    void setRotate(const Vector3 &radians);

    /**
    * Set rotation around all dimension in DEGREES for the matrix using a vector.
    * @param degrees A vector of the DEGREES for each axis.
    * @returns void.
    */
    inline void setRotateDeg(const Vector3 &degrees) { setRotate(Vector3(MathsLib::deg2rad(degrees.x),
		MathsLib::deg2rad(degrees.y), MathsLib::deg2rad(degrees.z))); };

	/**
	* Add rotation around all dimension in RADIANS for the matrix using a vector.
	* @param degrees A vector of the RADIANS for each axis.
	* @returns void.
	*/
	void rotate(const Vector3 &radians);
	
	/**
	* Add rotation around all dimension in DEGREES for the matrix using a vector.
	* @param degrees A vector of the DEGREES for each axis.
	* @returns void.
	*/
	inline void rotateDeg(const Vector3 &degrees) { rotate(Vector3(MathsLib::deg2rad(degrees.x),
		MathsLib::deg2rad(degrees.y), MathsLib::deg2rad(degrees.z))); };

	/**
	* Add rotation in RADIANS to existing X rotation.
	* @params radians The RADIANS to add.
	* @returns void.
	*/
	void rotateX(float radians);

	/**
	* Add rotation in RADIANS to existing Y rotation.
	* @params radians The RADIANS to add.
	* @returns void.
	*/
	void rotateY(float radians);

	/**
	* Add rotation in RADIANS to existing Z rotation.
	* @params radians The RADIANS to add.
	* @returns void.
	*/
	void rotateZ(float radians);

	/**
	* Add rotation in DEGREES to existing X rotation.
	* @params radians The DEGREES to add.
	* @returns void.
	*/
	inline void rotateXDeg(float degrees) { rotateX(MathsLib::deg2rad(degrees)); };

	/**
	* Add rotation in DEGREES to existing Y rotation.
	* @params radians The DEGREES to add.
	* @returns void.
	*/
	inline void rotateYDeg(float degrees) { rotateY(MathsLib::deg2rad(degrees)); };

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
    Matrix4 inverted() const;

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
	* Get the translation component of this matrix.
	* Uses Matrix Decomposition to determine the value.
	* @returns A vector of the translation.
	*/
	Vector3 getTranslate() const;

	/**
	* Set the translation component of this matrix using a vector.
	* @params translate The Vector4 to translate by.
	* @returns void.
	*/
	void setTranslate(const Vector3 &translate);

    /**
    * Add to the translation component of this matrix using a vector.
    * @params translate The vector to translate by.
    * @returns void.
    */
    void translate(const Vector3 &translate);

	/**
	* Get the X rotation component of this matrix in RADIANS.
	* Uses Matrix Decomposition to determine the value.
	* @returns The rotation in RADIANS.
	*/
	real getRotateX() const;

	/**
	* Get the X rotation component of this matrix in DEGREES.
	* Uses Matrix Decomposition to determine the value.
	* @returns The rotation in DEGREES.
	*/
	inline real getRotateXDeg() const { return MathsLib::rad2deg(getRotateX()); };

	/**
	* Get the Y rotation component of this matrix in RADIANS.
	* Uses Matrix Decomposition to determine the value.
	* @returns The rotation in RADIANS.
	*/
	real getRotateY() const;

	/**
	* Get the Y rotation component of this matrix in DEGREES.
	* Uses Matrix Decomposition to determine the value.
	* @returns The rotation in DEGREES.
	*/
	inline real getRotateYDeg() const { return MathsLib::rad2deg(getRotateY()); };

	/**
	* Get the Z rotation component of this matrix in RADIANS.
	* Uses Matrix Decomposition to determine the value.
	* @returns The rotation in RADIANS.
	*/
	real getRotateZ() const;

	/**
	* Get the Z rotation component of this matrix in DEGREES.
	* Uses Matrix Decomposition to determine the value.
	* @returns The rotation in DEGREES.
	*/
	inline real getRotateZDeg() const { return MathsLib::rad2deg(getRotateZ()); };

	/**
	* Get the rotation components of this matrix in vector in RADIANS.
	* @returns The rotations in a vector in RADIANS.
	*/
	inline Vector3 getEuler() { return Vector3(getRotateX(), getRotateY(), getRotateZ()); };

	/**
	* Get the rotation components of this matrix in vector in DEGREES.
	* @returns The rotations in a vector in DEGREES.
	*/
	inline Vector3 getEulerDeg() { return Vector3(MathsLib::rad2deg(getRotateX()),
		MathsLib::rad2deg(getRotateY()), MathsLib::rad2deg(getRotateZ())); };

	/**
	* Get the scale component of this matrix.
	* Uses Matrix Decomposition to determine the value.
	* @returns A vector of the scale.
	*/
	Vector4 getScale() const;
};