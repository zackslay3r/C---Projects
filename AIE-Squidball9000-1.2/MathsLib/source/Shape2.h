#pragma once
#include "DllExport.h"
#include "RealType.h"
#include "MathsTools.h"
#include <vector>
#include "Vector2.h"
#include "Matrix3.h"
#include "Colour.h"

/**
* The Shape2 class provides a definition of basic shapes in 2 dimensions such as lines, polygons and circles.
* @author Ashley Flynn - AIE - 2017
*/

class Shape2
{

public:

	/**
	* Default constructor.
	*/
    DLL Shape2();

	/**
	* Constructor for a circle.
	* @params r Radius of the circle, relative to circle origin.
	*/
    DLL Shape2(real r);

	/**
	* Constructor for a circle.
	* @params r Radius of the circle, relative to circle origin.
	* @params pos Position of the circle relative to the origin.
	*/
    DLL Shape2(real r, Vector2 pos);

	/**
	* Constructor for a polygon or a line.
	* Lines have 2 points. Polygons have 3 or more.
	* @params newPoints Points of the polygon or line, relative to polygon origin.
	*/
    DLL Shape2(const std::vector<Vector2> &newPoints);

	/**
	* Copy constructor.
	*/
    DLL Shape2(const Shape2 &other);

	/**
	* Default destructor.
	*/
    DLL ~Shape2();

	/**
	* Assignment operator overload.
	* @params other The shape to copy from.
	* @returns Reference to the new shape.
	*/
	DLL Shape2 &Shape2::operator=(const Shape2 &other);

	/**
	* Vector array of points in LOCAL SPACE that make up the shape, relative to SHAPE ORIGIN. 
	* Points for polygons are defined in clockwise wrapping order.
	* Circles have one point.
	*/
	std::vector<Vector2> pointsLocal;

	/**
	* Vector array of points in WORLD SPACE that make up the shape, relative to WORLD ORIGIN.
	* Points for polygons are defined in clockwise wrapping order.
	* Circles have one point.
	*/
	std::vector<Vector2> pointsWorld;

	/**
	* Vector array of face normals in LOCAL SPACE.
	*/
	std::vector<Vector2> normalsLocal;

	/**
	* Radius of the shape, relative to shape origin. For circles this is the standard radius.
	* For polygons and lines, this is optional and describes the maximum distance any of the points 
	* are from the shape origin.
	*/
    real radius;

	/**
	* Update the pointsWorld points from pointsLocal transformed by a matrix.
	* @params matrix The matrix to use.
	* @returns void.
	*/
    DLL void updatePointsWorldByMatrix(const Matrix3 &matrix);

	/**
	* Update face normals vector array, based on vertexes form pointsLocal vector array.
	* @returns void.
	*/
    DLL void updateNormals();

};