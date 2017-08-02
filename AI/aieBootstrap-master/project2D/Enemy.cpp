#include "Enemy.h"
#include "Seek.h"
#include "seekState.h"

#include <string>

Enemy::Enemy()
{
	position.x = 0.0f;
	position.y = 0.0f;
	scale.x = 25.0f;
	scale.y = 25.0f;

}

Enemy::Enemy(float positionX, float positionY)
{
	position.x = positionX;
	position.y = positionY;
	scale.x = 25.0f;
	scale.y = 25.0f;
	health = 100;
	enemyFSM = new gameFSM();
	
	//velocity = { 50.0f,50.0f };
	
	
}


Enemy::~Enemy()
{

}

void Enemy::render()
{
	PLAY->app->m_2dRenderer->setRenderColour(255, 0, 0);
	PLAY->app->m_2dRenderer->drawBox(position.x, position.y, scale.x, scale.y);
}

void Enemy::update(float dt)
{

	for (auto &behaviours : m_behaviours)
	{
		behaviours->Update(dt);
	}
		position += velocity * dt;
}

void Enemy::changeToSeek(Object * target)
{
	for (auto &behaviours : m_behaviours)
	{
		if (behaviours->type == 0)
		{
			behaviours->behaviourWeight = 1.0f;
		}
		else
		{
			behaviours->behaviourWeight = 0.0f;
		}
	}
}

void Enemy::changeToFlee(Object * awayFromTarget)
{
	for (auto &behaviours : m_behaviours)
	{
		if (behaviours->type == 2)
		{
			behaviours->behaviourWeight = 1.0f;
		}
		else
		{
			behaviours->behaviourWeight = 0.0f;
		}
	}
}

void Enemy::changeToWander(Object* target)
{
	for (auto &behaviours : m_behaviours)
		if (behaviours->type != BehaviourID::WANDER)
		{
			behaviours->behaviourWeight = 0.0f;
		}
		else
		{
			behaviours->behaviourWeight = 1.0f;
		}
}
