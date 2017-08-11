#include "Cohesion.h"
#include "PlayLoop.h"


Cohesion::Cohesion(Object * myself)
{
	mySelf = myself;
	type = BehaviourNames::COHESION;
	behaviourWeight = 1.0f;
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
	for (auto &flockcubes : PLAY->flock)
	{
		if (mySelf != flockcubes)
		{
			if (PLAY->myNodes.distanceCheck(mySelf, 300, flockcubes))
			{
				tempVector.x += flockcubes->position.x;
				tempVector.y += flockcubes->position.y;
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
		
		
		//tempVector.x *= behaviourWeight;
		//tempVector.y *= behaviourWeight;


		Vector2 finalVec;
		finalVec = { tempVector.x - mySelf->velocity.x, tempVector.y - mySelf->velocity.y };

		finalVec.normalise();
		finalVec = finalVec * speed * behaviourWeight;
		return finalVec;
	}
	Vector2 emptyVec;
	return emptyVec;
}

Cohesion::~Cohesion()
{
}
