#include "Separation.h"
#include "PlayLoop.h"

Separation::Separation(Object * myself)
{
	mySelf = myself;
	type = BehaviourNames::SEPERATION;
	behaviourWeight = 2.0f;
}

Vector2 Separation::Update(float dt)
{
	// this is the temp vector that will store the velocity calculated.
	Vector2 tempVector;
	// This is the amount of neighbours each enemy will have.
	int neighborCount = 0;
	// default speed
	float speed = 100.0f;

	// Loop though all our enemies and if they are not the same and are within a certain distance,
	// add to the temporary vector the enemy velocitys vector and increment the neighbour count
	for (auto &flockcubes : PLAY->flock)
	{
		if (mySelf != flockcubes)
		{
			if (PLAY->myNodes.distanceCheck(mySelf, 150, flockcubes))
			{
				tempVector.x += flockcubes->position.x - mySelf->position.x;
				tempVector.y += flockcubes->position.y - mySelf->position.y;
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

		tempVector.x *= -1.0f;
		tempVector.y *= -1.0f;

		if (tempVector.x != 0.0f && tempVector.y != 0.0f)
		{
			tempVector.normalise();
			tempVector * speed * behaviourWeight;
			return tempVector;
		}
		else
		{
			Vector2 empty;
			return empty;
		}
	}
}

Separation::~Separation()
{
}
