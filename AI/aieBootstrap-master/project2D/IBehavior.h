#pragma once
#include "Object.h"

class Object;

/*
* class IBehavior
*
* This is an IBehavior class, which is the blueprint for all behaviours.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class IBehavior
{
public:

	enum BehaviourNames { MOVEALONGPATH, SEEK, WANDER, FLEE, SEPERATION, COHESION, ALIGNMENT, AVOIDANCE };
	BehaviourNames type;

	Object* mySelf;
	
	/*
	* IBehavior(Object* myself);
	*
	* This is a constructor. it takes on 1 parameterm an Object*.
	*
	*/
	IBehavior(Object* myself);
	/*
	* IBehavior();
	*
	* This is the default constructor.
	*
	*/
	IBehavior();


	float behaviourWeight;

	/*	 virtual Vector2 Update( float deltaTime) = 0;
	*
	*	This function is a pure virtual function which is responsible for the Update of a behaviour and returns a vector2.
	*
	*/
	virtual Vector2 Update( float deltaTime) = 0;
	/*
	* ~IBehavior();
	*
	* This is the default destructor.
	*
	*/
	~IBehavior();

	

};

