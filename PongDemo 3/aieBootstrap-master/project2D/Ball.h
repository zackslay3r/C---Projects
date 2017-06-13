#pragma once
#include "Object.h"
class Ball :public Object
{
public:
	Ball();
	~Ball();

private:
	int posx, posy;
	int originalX, originalY;
};

