#pragma once
#include "IBehavior.h"
class Avoidance : public IBehavior
{
public:
	// This behaviour will be cloned for as many feelers as
	Avoidance(Object* myself, float angle, float weighting);

	Vector2 Update(float dt);
	
	//this will be set in the constructor 
	float feelerAngle;

	Vector2 rotateVector(Vector2 feelerPos, float degrees);
	Vector2 lineEnd;

	bool lineLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
	bool lineRec(float x1, float y1, float x2, float y2, float rx, float ry, float rw, float rh);
	~Avoidance();
};

