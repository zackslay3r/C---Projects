#include "ObjectPool.h"



ObjectPool::ObjectPool()
{
	ballStack = Stack<Ball*>(100);
	paddleStack = Stack<Paddle*>(100);
}


ObjectPool::~ObjectPool()
{
}

Ball * ObjectPool::pullBall()
{
	if (ballStack.empty())
	{
		return nullptr;
	}
	else
	{
		return ballStack.pop();
	}
}

Paddle * ObjectPool::pullPaddle()
{
	if (paddleStack.empty())
	{
		return nullptr;
	}
	else
	{
		return paddleStack.pop();
	}
}

void ObjectPool::pushBall(Ball* newball)
{
	ballStack.push(newball);
}

void ObjectPool::pushPaddle(Paddle* newpaddle)
{
	paddleStack.push(newpaddle);
}

ObjectPool* ObjectPool::getInstance()
{
	static ObjectPool objectpool;

	return &objectpool;
}
