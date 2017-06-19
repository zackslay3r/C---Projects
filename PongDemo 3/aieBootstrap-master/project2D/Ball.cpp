#include "Ball.h"


// THis is the default constructor of a ball, this sets out its default values of a ball object except the position
// which will be defined with the parameter's given in the constructor.
Ball::Ball(float positionX, float positionY)
{
	// This is the position of a Ball.
	posX = positionX;
	posY = positionY;
	// This is the size of the ball. 
	width = 20;
	height = 20;
	// This is the velocity of the ball along the x and y axis, this is set the same for to be able to move at 45 degrees.
	velocityX = 200;
	velocityY = 200;
}

// This is the ball deconstructor.
Ball::~Ball()
{
}
