#include "Factory.h"
#include "Object.h"


Factory::Factory()
{
}

Object* Factory::makeBall(float positionX, float positionY)
{
	return new Ball(positionX, positionY);
}





//Factory::makeLeftPaddle()
//{
//}
//
//Factory::makeRightPaddle()
//{
//}




Object* Factory::makePaddle(float positionX, float positionY)
{
	return new Paddle(positionX, positionY);
}

Factory::~Factory()
{
}
