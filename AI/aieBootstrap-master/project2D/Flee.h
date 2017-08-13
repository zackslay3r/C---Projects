#pragma once
#include "IBehavior.h"
/*
* class Flee
*
* This is an IBehavior class, which is responsible for Flee towards the enemy.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class Flee : public IBehavior
{
public:
	/*
	* Flee(Object* myself);
	*
	* This is a constructor. it takes on 1 parameter of an Object*.
	*
	*/
	Flee(Object* myself);
	/*	 Vector2 Update(float dt);
	*
	*	This function is responsible for updating the behaviour and returns a Vector2.
	*
	*/
	Vector2 Update(float dt);
	/*
	* ~Flee();
	*
	* This is the destructor.
	*
	*/
	~Flee();
};

