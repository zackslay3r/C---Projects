#pragma once
#include "Object.h"

// This is the ball class which is the child of a object. 
class Ball :public Object
{
public:
	Ball(float positionX, float positionY);
	~Ball();


};

