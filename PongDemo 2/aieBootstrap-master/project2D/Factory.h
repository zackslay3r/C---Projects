#pragma once
#include "Object.h"
#include "Ball.h"
#include "Paddle.h"
class Factory
{
public:
	Factory();
	static Object* makeBall(float positionX, float positionY);
	//void makeLeftPaddle();
	//void makeRightPaddle();
	static Object* makePaddle(float positionX, float psotionY);
	~Factory();
};

