#pragma once
#include "IBehavior.h"
#include "Global.h"

/*
* class MoveAlongPath
*
* this is the behaviour that is responsible for getting the enemys to move along the A* path.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class MoveAlongPath : public IBehavior
{
public:
	/*
	* MoveAlongPath(Object* myself);
	*
	* this is the constructor that will take an Object* of itself and set it so that it is able to be used later for behaviour stuff.
	*
	*/
	MoveAlongPath(Object* myself);
	/*
	* Vector2 Update(float dt);
	*
	* this is an update function that updates the enemy behaviour based on the parameter of deltaTime and returns a Vector2.
	*
	*/
	Vector2 Update(float dt);
	
	/*
	* ~MoveAlongPath();
	*
	* this is the destructor of MoveAlongPath.
	*
	*/
	~MoveAlongPath();
};

