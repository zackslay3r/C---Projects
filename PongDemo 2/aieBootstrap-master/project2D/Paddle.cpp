#include "Paddle.h"



Paddle::Paddle(float positionX, float positionY)
{
	posX = positionX;
	posY = positionY;
	width = 5;
	height = 300;
	velocityX = 0;
	velocityY = 0;
}


Paddle::~Paddle()
{
}
