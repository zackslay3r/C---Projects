#include "FlockCube.h"
#include "PlayLoop.h"




FlockCube::FlockCube(float positionX, float positionY)
{
	position.x = positionX;
	position.y = positionY;
	scale.x = 10.0f;
	scale.y = 10.0f;
	//velocity.x = 5.0f;
	//velocity.y = 5.0f;
	
}

void FlockCube::render()
{
	PLAY->app->m_2dRenderer->setRenderColour(0, 0, 255);
	PLAY->app->m_2dRenderer->drawBox(position.x, position.y, scale.x, scale.y);
}

void FlockCube::update(float dt)
{
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
		float TotalActiveBeheaviours = (m_behaviours.size() - nullBeheaviours);
		if (desiredVelocity.x != 0.0f && desiredVelocity.y != 0.0)
		{
			desiredVelocity.x = desiredVelocity.x / TotalActiveBeheaviours;
			desiredVelocity.y = desiredVelocity.y / TotalActiveBeheaviours;
		}
	


		if (TotalActiveBeheaviours > 0)
		{
			
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
	}
}


void FlockCube::changeToSeek()
{
	for (auto &behaviours : m_behaviours)
	{

		switch (behaviours->type)
		{
		case IBehavior::SEEK:
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

FlockCube::~FlockCube()
{
}
