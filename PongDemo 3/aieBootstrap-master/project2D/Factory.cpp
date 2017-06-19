#include "Factory.h"
#include "Object.h"

// This is the factory constructor.
Factory::Factory()
{
}
// This is the makeBall function that is used to create a ball object. this is done by returning a new ball object
// at position x,y that is passed in as parameters and creating it at that position.
Object* Factory::makeBall(float positionX, float positionY)
{
	return new Ball(positionX, positionY);
}
// This is the makePaddle function that is used to create a paddle object. this is done by returning a new paddle object
// at position x,y that is passed in as parameters and creating it at that position.
Object* Factory::makePaddle(float positionX, float positionY)
{
	return new Paddle(positionX, positionY);
}

// This is the factory destructor.
Factory::~Factory()
{
}
