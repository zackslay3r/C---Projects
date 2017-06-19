#pragma once
#include "Object.h"
#include "Ball.h"
#include "Paddle.h"

// This is the factory class, it is essential in the creation of the objects in my game. 
// With the only purpose of this class to make objects that are either paddles or balls.
class Factory
{
public:
	// This is the default constructor.
	Factory();
	// This function is to be able to create a Ball.
	static Object* makeBall(float positionX, float positionY);
	

	// This function is to be able to create a Paddle.
	static Object* makePaddle(float positionX, float psotionY);
	
	// This is the factory destructor.
	~Factory();
};

