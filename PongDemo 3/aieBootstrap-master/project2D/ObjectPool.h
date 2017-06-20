#pragma once
#include "../ContainerLibrary/ContainerLibrary/ContainerLibrary/Stack.h"
#include "Ball.h"
#include "Paddle.h"

#define POOL ObjectPool::getInstance()
class ObjectPool
{
public:

	static ObjectPool *getInstance();
	ObjectPool();
	~ObjectPool();
	Ball* pullBall();
	Paddle* pullPaddle();
	void pushBall(Ball* newball);
	void pushPaddle(Paddle* newpaddle);

private:
	Stack<Ball*> ballStack;
	Stack<Paddle*> paddleStack;
};

