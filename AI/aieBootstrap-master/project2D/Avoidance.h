#pragma once
#include "IBehavior.h"
class Avoidance : public IBehavior
{
public:
	/*
	* Avoidance(Object* myself, float angle, float weighting);
	*
	* This is the constructor. it takes on 3 parameters. an Object* and two floats.
	*
	*/
	Avoidance(Object* myself, float angle, float weighting);

	/*
	* Vector2 Update(float dt);
	*
	* This is the update function, it is responsible for helping to update the velocity of the Agent and returns a vector2 to later be used. it takes on the parameter of float deltaTime.
	*
	*/
	Vector2 Update(float dt);
	
	//this will be set in the constructor 
	float feelerAngle;
	/*
	* Vector2 rotateVector(Vector2 feelerPos, float degrees);
	*
	* This is the rotateVector function, it is responsible for setting the rotation of a feeler and returns a Vector2.
	*
	*/
	Vector2 rotateVector(Vector2 feelerPos, float degrees);
	Vector2 lineEnd;

	/*
	* bool lineLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
	*
	* This function is responsible for line line collision. it takes on 8 floats and check if two lines are colliding and returns a bool.
	*
	*/
	bool lineLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
	/*
	* bool lineRec(float x1, float y1, float x2, float y2, float rx, float ry, float rw, float rh);
	*
	* This function is responsible for line rectangle collision. it takes on 8 floats and check if a line and rectangle  are colliding and returns a bool.
	*
	*/
	bool lineRec(float x1, float y1, float x2, float y2, float rx, float ry, float rw, float rh);
	/*
	* ~Avoidance();
	*
	* This is the destructor.
	*
	*/
	~Avoidance();
};

