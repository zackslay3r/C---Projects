#pragma once
#include "IBehavior.h"
#include "Global.h"
/*
* class Seeking
*
* This is an IBehavior class, which is responsible for Alignment towards the enemy.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class Alignment : public IBehavior
{
public:
	/*
	* Alignment(Object* myself);
	*
	* This is a constructor. it takes on 1 parameter of an Object*.
	*
	*/
	Alignment(Object* myself);
	/*	 Vector2 Update(float dt);
	*
	*	This function is responsible for updating the behaviour and returns a Vector2.
	*
	*/
	Vector2 Update(float dt);
	/*
	* ~Alignment();
	*
	* This is the destructor.
	*
	*/
	~Alignment();
};

