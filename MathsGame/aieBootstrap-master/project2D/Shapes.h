#pragma once
#include "Vector2.h"
#include "Matrix3.h"
#include <vector>
#include "Renderer2D.h"



/*
* struct ArraySquare
*
* This struct allows for the storing of an array of Vector2's that will store points like a square.
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
	struct ArraySquare
	{
		Vector2 points[4];
	};

/*
* struct CollisionResults
*
* This struct allows for the storing of collision results.
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
	struct CollisionResults
	{
		bool colliding;
		Vector2 pushOutVector;
	};


	/*
	* class shape
	*
	* This class is used to draw squares around game objects to allow for collisions to happen 
	* and to be detected.
	* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
	*/

	class shape
	{
	public:
		enum shapeType { Square, Circle };
		shapeType myShapeChoice;
		const bool DEBUG_SHOW = true;
		ArraySquare square;
		Matrix3 *shapeMatrix;
		Vector2 scale;
		Vector2 Origin;

		/* shape();
		*
		* This function is the default constructor.
		*
		*
		*/
		shape();
		
		/* shape( Vector2 scale, Matrix3 *Global);
		*
		* This function is the constructor that takes in a scale and the globalTranslate.
		*
		* @param Vector2 - scale
		* @param Matrix3* - GlobalTranslate
		*/
		shape( Vector2 scale, Matrix3 *Global);
		
		/* void SetShape(Vector2 scale, Matrix3 *Global, shapeType shapeSelection,Vector2 Origion = { 0,0 });
		*
		* This function sets the shape based upon the paramaters recieved.
		*
		* @param Vector2 - scale
		* @param Matrix3* - GlobalTranslate
		* @param shapeType - shapeSelection
		* @param Vector2 - the Origion, defaulted to 0,0
		*
		* @returns void
		*/
		void SetShape(Vector2 scale, Matrix3 *Global, shapeType shapeSelection,Vector2 Origion = { 0,0 });
		
		/* void ReCalcShape();
		*
		* This function recalculates the shape based on the points of ArraySquare.
		*
		*@returns void
		*/
		void ReCalcShape();

		/* ArraySquare getNormals();
		*
		* This function gets the normals of the points within ArraySquare and returns them normalised.
		*
		* @returns ArraySquare- normalised points
		*/
		ArraySquare getNormals();
		
		/* ArraySquare getNormalsUnNormalized();
		*
		* This function gets the normals of the points within ArraySquare and returns them as if they were unnormalised.
		*
		* @returns ArraySquare- unnormalised points
		*/
		ArraySquare getNormalsUnNormalized();
		
		/* Vector2 ProjectPolygon(Vector2 AxisNorm);
		*
		* This function projects the polygon base upon the x and y axis that will be used for collision detection.
		*
		* @param Vector2 - AxisNorm are the Axis that have been normalised.
		* @return Vector2 - returns the projection.
		*/
		Vector2 ProjectPolygon(Vector2 AxisNorm);

		/*	float IntervalDistance(Vector2 minMax1, Vector2 minMax2);
		*
		* This function checks the interval distance between two shapes and returns the distance between them.
		*
		* @param Vector2 - minMax1 is the min and max dot product of shape1.
		* @param Vector2 - minMax2 is the min and max dot product of shape2.
		*
		* @returns float
		*/
		float IntervalDistance(Vector2 minMax1, Vector2 minMax2);
		/* void Update();
		*
		* This function updates each shape object to be able to redraw the shape to a new location in the game world.
		* @returns void
		*/
		void Update();
		/* void DrawDebug( aie::Renderer2D*	Renderer);
		*
		* This function draws the shape around the game object for the shape to be visually seen.
		* @param aie::Renderer2D*- the aie renderer
		* 
		* @returns void
		*/
		void DrawDebug( aie::Renderer2D*	Renderer);
		/* bool isColliding(shape other);
		*
		* This function tests to see if two shapes are colliding with each other and will return true if they
		* are and false if they arent.
		* @param shape - other is the 2nd shape thats being tested
		* @returns bool
		*/
		bool isColliding(shape other);
		
		/* CollisionResults isCollidingExtra(shape other);
		*
		* This function allows for the direction and for the push out vector to be calculated. this function is called only if two shapes
		* have been found to be colliding.
		* @param shape - other is the 2nd shape thats being tested
		* @returns CollisionResults
		*/
		CollisionResults isCollidingExtra(shape other);
	};
	
