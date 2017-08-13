#pragma once

#include "Object.h"
#include "Vector2.h"

/*
* class FlockCube
*
* this is the flockCube class, in which, a flock cube will help me demonstrate flocking for this assessment.
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class FlockCube :
	public Object
{
public:
	/*
	* FlockCube(float positionX, float positionY);
	*
	* This is the constructor for FlockCube, it will set the position of the flockcube based on the two parameters 
	* of position X and Y.
	* 
	*/
	FlockCube(float positionX, float positionY);
	
	/*
	* void render();
	*
	* this is the render function. it is responsible for rendering the flockcube itself and returns void.
	*
	*/
	void render();
	/*
	* void update(float dt);
	*
	* this is the update function. it is responsible for updating the flockcube itself
	* it takes the parameter of deltatime which is a float and returns void.
	*
	*/
	void update(float dt);
	float maxSpeed = 800.0f;
	float minSpeed = 0.0f;
	std::list<IBehavior*> m_behaviours;
	Vector2 desiredVelocity;
	Object* target;
	/*
	* void changeToSeek();
	*
	* this is the changeToSeek function. this will allow a flockcube to have a seek behaviour.
	*
	*/
	void changeToSeek();
	int id;
	
	/*
	* ~FlockCube();
	*
	* This is the destructor for FlockCube.
	*
	*/
	~FlockCube();
};

