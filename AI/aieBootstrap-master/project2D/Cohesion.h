#pragma once
#include "IBehavior.h"
#include "Global.h"
/*
* class Cohesion
*
* This is an IBehavior class, which is responsible for Cohesion towards the enemy.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class Cohesion : public IBehavior
{
public:
	
	Cohesion();
	/*
	* Cohesion(Object* myself);
	*
	* This is a constructor. it takes on 1 parameter of an Object*.
	*
	*/
	Cohesion(Object* myself);
	/*	 Vector2 Update(float dt);
	*
	*	This function is responsible for updating the behaviour and returns a Vector2.
	*
	*/
	Vector2 Update(float dt);
	/*
	* ~Cohesion();
	*
	* This is the destructor.
	*
	*/
	~Cohesion();
};

