#include "Enemy.h"
#include "MoveAlongPath.h"
#include "seekState.h"

#include <string>

Enemy::Enemy()
{
	position.x = 0.0f;
	position.y = 0.0f;
	scale.x = 25.0f;
	scale.y = 25.0f;
	type = AgentType::BEHAVIOURUSINGENEMY;
}

Enemy::Enemy(float positionX, float positionY)
{
	position.x = positionX;
	position.y = positionY;
	scale.x = 25.0f;
	scale.y = 25.0f;
	health = 100.0;

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
	for (auto &behaviours : m_behaviours)
	{
		if (behaviours->type == IBehavior::MOVEALONGPATH && behaviours->behaviourWeight > 0.0f)
		{
			if (!PLAY->theBoard->usePathFollow(this))
			{
				changeToSeek();
			}
		}
		if (behaviours->type == IBehavior::SEEK && behaviours->behaviourWeight > 0.0f)
		{
			if (PLAY->theBoard->usePathFollow(this))
			{
				changeToFollowPath();
			}
		}
	}
	
	int nullBeheaviours = 0;
	Vector2 tempVec;
	for (auto &behaviours : m_behaviours)
	{

		if (behaviours->behaviourWeight <= 0.0f)
		{
			nullBeheaviours++;
		}
		else
		{
			tempVec = behaviours->Update(dt);
			if (tempVec.x == 0.0f && tempVec.y == 0.0f)
			{
				nullBeheaviours++;
			}
			else
			{
		
				desiredVelocity += tempVec;
				
			}
		}
	}
	// Set the velocity to be that of the desired velocity (all the velocity's of every behaviour added)
	// divided by (the amount of behaviours the smartAI has - the amount of nullBehaviours)
	float TotalActiveBeheaviours = (m_behaviours.size() - nullBeheaviours);
	if (desiredVelocity.x != 0.0f && desiredVelocity.y != 0.0)
	{
		desiredVelocity.x = desiredVelocity.x  / TotalActiveBeheaviours;
		desiredVelocity.y = desiredVelocity.y  / TotalActiveBeheaviours;
	}
	if (desiredVelocity.sqrMagnitude() <  (minSpeed*minSpeed))
	{
		if (desiredVelocity.x != 0.0f || desiredVelocity.y != 0.0)
		{
			desiredVelocity = desiredVelocity.normalised() * minSpeed;
		}
	}
	else if (desiredVelocity.sqrMagnitude() >  (maxSpeed*maxSpeed))
	{
		desiredVelocity = desiredVelocity.normalised() * maxSpeed;
	}


	if (TotalActiveBeheaviours > 0)
	{
		//velocity = (velocity + velocity + velocity + desiredVelocity)*0.25f;
		velocity = desiredVelocity;
	}

	if (velocity.sqrMagnitude() < (minSpeed*minSpeed))
	{
		if (velocity.x != 0.0f || velocity.y != 0.0)
		{
			velocity = velocity.normalised() * minSpeed;
		}
	}
	else if (velocity.sqrMagnitude() > (maxSpeed*maxSpeed))
	{
		velocity = velocity.normalised() * maxSpeed;
	}

	position += velocity * dt;
	desiredVelocity = { 0.0f, 0.0f };

	
	if (PLAY->myNodes.distanceCheck(this, 300, PLAY->player))
	{
		changeToFollowPath();
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
	
		switch (behaviours->type)
		{
		case IBehavior::SEEK:
			behaviours->behaviourWeight = 1.0f;
			PLAY->theBoard->isSeeking.push_back(((Enemy*)this));
			PLAY->theBoard->seekAsWell();
			break;
		case IBehavior::COHESION:
			break;
		case IBehavior::ALIGNMENT:
			break;
		case IBehavior::SEPERATION:
			break;
		case IBehavior::AVOIDANCE:
			break;
		default:
			behaviours->behaviourWeight = 0.0f;
		}
	}
}

void Enemy::changeToFollowPath()
{
	for (auto &behaviours : m_behaviours)
	{

		switch (behaviours->type)
		{
		case IBehavior::MOVEALONGPATH:
			behaviours->behaviourWeight = 1.0f;
			PLAY->theBoard->isSeeking.push_back(((Enemy*)this));
			PLAY->theBoard->seekAsWell();
			break;
		case IBehavior::COHESION:
			break;
		case IBehavior::ALIGNMENT:
			break;
		case IBehavior::SEPERATION:
			break;
		case IBehavior::AVOIDANCE:
			break;
		default:
			behaviours->behaviourWeight = 0.0f;
		}
	}
}

void Enemy::changeToFlee()
{
	for (auto &behaviours : m_behaviours)
	{
	
		switch (behaviours->type)
		{
		case IBehavior::FLEE:
			behaviours->behaviourWeight = 1.0f;
			break;
		case IBehavior::COHESION:
			break;
		case IBehavior::ALIGNMENT:
			break;
		case IBehavior::SEPERATION:
			break;
		case IBehavior::AVOIDANCE:
			break;
		default:
			behaviours->behaviourWeight = 0.0f;
		}
	}
}

void Enemy::changeToWander()
{
	for (auto &behaviours : m_behaviours)
	{
	/*	if (behaviours->type == IBehavior::WANDER || behaviours->type == IBehavior::AVOIDANCE)
		{
			behaviours->behaviourWeight = 1.0f;
		}
		else
		{
			behaviours->behaviourWeight = 0.0f;
		}*/
		switch (behaviours->type)
		{
		case IBehavior::WANDER: 
		behaviours->behaviourWeight = 1.0f;
		break;
		case IBehavior::COHESION:
		break;
		case IBehavior::ALIGNMENT:
		break;
		case IBehavior::SEPERATION:
		break;
		case IBehavior::AVOIDANCE:
		break;
		default:
		behaviours->behaviourWeight = 0.0f;
		}
	}
}
