#include "Ball.h"



Ball::Ball(float positionX, float positionY)
{
	posX = positionX;
	posY = positionY;
	width = 20;
	height = 20;
	velocityX = 200;
	velocityY = 200;
}


Ball::~Ball()
{
}
