#pragma once
#include "Object.h"
// This is the Paddle class which is the child of a object. 
class Paddle : public Object
{
public:
	Paddle(float positionX, float positionY);
	~Paddle();
};

