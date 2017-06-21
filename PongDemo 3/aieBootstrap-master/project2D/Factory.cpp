#include "Factory.h"


// This is the factory constructor.
Factory::Factory()
{
}
// This is the makeBall function that is used to create a ball object. this is done by returning a new ball object
// at position x,y that is passed in as parameters and creating it at that position.
Object* Factory::makeBall(float positionX, float positionY)
{
	Object* tmp = POOL->pullBall();
	if (!tmp)
	{
		tmp = new Ball(positionX, positionY);
	}
	else
	{
		tmp->posX = positionX;
		tmp->posY = positionY;
	}
	return tmp;
}
// This is the makePaddle function that is used to create a paddle object. this is done by returning a new paddle object
// at position x,y that is passed in as parameters and creating it at that position.
Object* Factory::makePaddle(float positionX, float positionY)
{
	Object* tmp = POOL->pullPaddle();
	if (!tmp)
	{
		tmp = new Paddle(positionX, positionY);
	}
	else
	{
		tmp->posX = positionX;
		tmp->posY = positionY;
	}
	return tmp;
}

// This will filled the BallPool with the amount specificed in the parameter. these balls are defaulted.
void Factory::fillBallPool(int n)
{
	for (int i = 0; i < n; i++)
	{
		POOL->pushBall(new Ball(0, 0));
	}

}
// This will filled the PaddlePool with the amount specificed in the parameter. these paddles. are defaulted.
void Factory::fillPaddlePool(int n)
{
	for (int i = 0; i < n; i++)
	{
		POOL->pushPaddle(new Paddle(0, 0));
	}
}

// This is the factory destructor.
Factory::~Factory()
{
}
