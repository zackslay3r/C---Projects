#pragma once
#include "../ContainerLibrary/ContainerLibrary/ContainerLibrary/Stack.h"
#include "Ball.h"
#include "Paddle.h"

// This makes objectPool a singleton.
#define POOL ObjectPool::getInstance()

class ObjectPool
{
public:

	static ObjectPool *getInstance();
	
	// Constructor
	ObjectPool();
	//Destructor
	~ObjectPool();
	// Pull a ball from the stack
	Ball* pullBall();
	// Pull a paddle from the stack.
	Paddle* pullPaddle();
	// Push a new paddle and ball within their respective stacks.
	void pushBall(Ball* newball);
	void pushPaddle(Paddle* newpaddle);

private:
	// Have the stacks be private.
	Stack<Ball*> ballStack;
	Stack<Paddle*> paddleStack;
};

