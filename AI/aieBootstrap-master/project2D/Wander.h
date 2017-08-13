#pragma once
#include "IBehavior.h"
#include "Enemy.h"
#include "Vector2.h"
#include "Global.h"
/*
* class Wander
*
* This is an IBehavior class, which is responsible for Wander towards the enemy.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class Wander :
	public IBehavior
{
public:
	/*
	* Wander(Object* myself);
	*
	* This is a constructor. it takes on 1 parameter of an Object*.
	*
	*/
	Wander(Object* myself);
	/*	 Vector2 Update(float dt);
	*
	*	This function is responsible for updating the behaviour and returns a Vector2.
	*
	*/
	Vector2 Update(float dt);
	/*	 int random();
	*
	*	This function is responsible for returning a random number of type int.
	*
	*/
	int random();
	float wanderRadius = 200;
	float wanderDistance = 150;
	float wanderJitter = 0.1f;
	float wanderAngle = 0.0f;

	/*
	* void setAngle(Vector2* displacement, float wanderAngle);
	*
	* This is the setAngle function, it is responsible for setting the angle of a enemy. it takes in a Vector2* and float as parameters and returns void.
	*
	*/
	void setAngle(Vector2* displacement, float wanderAngle);
	/*
	* ~Wander();
	*
	* This is the destructor.
	*
	*/
	~Wander();
};

