#pragma once
#include "Object.h"
// This is the Paddle class which is the child of a object. 
/*
* class Paddle : public Object
*
* This is an Paddle object which is based of the the Object class.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class Paddle : public Object
{
public:
	/*
	* Paddle(float positionX, float positionY);
	*
	* This is the Paddle constructor which will be placed at the location of the two parameters passed.
	*
	*/
	Paddle(float positionX, float positionY);
	/*
	* ~Paddle();
	*
	* This is the Paddle destructor.
	*
	*/
	~Paddle();
};

