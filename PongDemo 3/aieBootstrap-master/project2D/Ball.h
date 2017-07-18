#pragma once
#include "Object.h"



/*
* class Ball : public Object
*
* This is an Ball object which is based of the the Object class.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
class Ball :public Object
{
public:
	/*
	* Ball(float positionX, float positionY);
	*
	* This is the Ball constructor which will be placed at the location of the two parameters passed.
	*
	*/
	Ball(float positionX, float positionY);
	/*
	* ~Ball();
	*
	* This is the Paddle destructor.
	*
	*/
	~Ball();


};

