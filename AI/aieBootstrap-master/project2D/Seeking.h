#pragma once
#include "IBehavior.h"
/*
* class Seeking
*
* This is an IBehavior class, which is responsible for Seeking towards the enemy.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class Seeking : public IBehavior
{
public:
	/*
	* Seeking(Object* myself);
	*
	* This is a constructor. it takes on 1 parameter of an Object*.
	*
	*/
	Seeking(Object* myself);
	/*	 Vector2 Update(float dt);
	*
	*	This function is responsible for updating the behaviour and returns a Vector2.
	*
	*/
	Vector2 Update(float dt);
	/*
	* ~Seeking();
	*
	* This is the destructor.
	*
	*/
	~Seeking();
};

