#pragma once
#include "IBehavior.h"
#include "Global.h"
/*
* class Separation
*
* This is an IBehavior class, which is responsible for Seperation towards the enemy.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class Separation : public IBehavior
{
public:
	/*
	* Separation(Object* myself);
	*
	* This is a constructor. it takes on 1 parameter of an Object*.
	*
	*/
	Separation(Object* myself);
	/*	 Vector2 Update(float dt);
	*
	*	This function is responsible for updating the behaviour and returns a Vector2.
	*
	*/
	Vector2 Update(float dt);
	/*
	* ~Separation();
	*
	* This is the destructor.
	*
	*/
	~Separation();
};

