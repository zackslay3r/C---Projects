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

	utility = new UtilityAI();
	velocity = { 5,5 };
	
	
}


Enemy::~Enemy()
{
	
	delete utility;
}

void Enemy::render()
{
	PLAY->app->m_2dRenderer->setRenderColour(255, 0, 0);
	PLAY->app->m_2dRenderer->drawBox(position.x, position.y, scale.x, scale.y);
}

void Enemy::update(float dt)
{
	int nullBeheaviours = 0;
	for (auto &behaviours : m_behaviours)
	{

		if (behaviours->behaviourWeight <= 0.0f)
		{
			nullBeheaviours++;
		}
		else
		{
			desiredVelocity += behaviours->Update(dt);
		}
	}


	// Set the velocity to be that of the desired velocity (all the velocity's of every behaviour added)
	// divided by (the amount of behaviours the smartAI has - the amount of nullBehaviours)
	velocity.x = desiredVelocity.x / (m_behaviours.size() - nullBeheaviours);
	velocity.y = desiredVelocity.y / (m_behaviours.size() - nullBeheaviours);
	position += velocity * dt;
	desiredVelocity = { 0.0f, 0.0f };


	if (PLAY->myNodes.distanceCheck(this, 300, PLAY->player))
	{
		changeToSeek();
	}
	if (health <= 30)
	{
		changeToFlee();
	}
}

void Enemy::changeToSeek()
{
	for (auto &behaviours : m_behaviours)
	{
		if (behaviours->type == 0 || behaviours->type == 6)
		{
			behaviours->behaviourWeight = 1.0f;
		}
		else
		{
			behaviours->behaviourWeight = 0.0f;
		}
	}
}

void Enemy::changeToFlee()
{
	for (auto &behaviours : m_behaviours)
	{
		if (behaviours->type == 2 || behaviours->type == 6)
		{
			behaviours->behaviourWeight = 1.0f;
		}
		else
		{
			behaviours->behaviourWeight = 0.0f;
		}
	}
}

void Enemy::changeToWander()
{
	for (auto &behaviours : m_behaviours)
		if (behaviours->type == 1 || behaviours->type == 6)
		{
			behaviours->behaviourWeight = 1.0f;
		}
		else
		{
			behaviours->behaviourWeight = 0.0f;
		}
}
