#include "Cohesion.h"
#include "PlayLoop.h"


Cohesion::Cohesion(Object * myself)
{
	mySelf = myself;
	type = BehaviourNames::COHESION;
	behaviourWeight = 5.0f;
}

Vector2 Cohesion::Update(float dt)
{

	// this is the temp vector that will store the velocity calculated.
	Vector2 tempVector;
	// This is the amount of neighbours each enemy will have.
	int neighborCount = 0;

	float speed = 100.0f;
	// Loop though all our enemies and if they are not the same and are within a certain distance,
	// add to the temporary vector the enemy velocitys vector and increment the neighbour count
	for (auto &enemys : PLAY->enemies)
	{
		if (mySelf != enemys)
		{
			if (PLAY->myNodes.distanceCheck(mySelf, 300, enemys))
			{
				tempVector.x += enemys->position.x;
				tempVector.y += enemys->position.y;
				neighborCount++;
			}
		}

	}
	if (neighborCount == 0)
	{
		
		Vector2 empty;
		return empty;
	}
	else
	{
		tempVector.x /= neighborCount;
		tempVector.y /= neighborCount;
		
		
		tempVector.x *= behaviourWeight;
		tempVector.y *= behaviourWeight;


		Vector2 finalVec;
		finalVec = { tempVector.x - mySelf->position.x, tempVector.y - mySelf->position.y };

		finalVec.normalise();
		finalVec = finalVec * speed;
		return finalVec;
	}
	Vector2 emptyVec;
	return emptyVec;
}

Cohesion::~Cohesion()
{
}
