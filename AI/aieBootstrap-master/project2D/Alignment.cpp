#include "Alignment.h"
#include "PlayLoop.h"


Alignment::Alignment(Object * myself)
{
	mySelf = myself;
	type = BehaviourNames::ALIGNMENT;
	behaviourWeight = 1.0f;
}

Vector2 Alignment::Update(float dt)
{
	// this is the temp vector that will store the velocity calculated.
	Vector2 tempVector;
	// This is the amount of neighbours each enemy will have.
	int neighborCount = 0;
	
	float speed = 100.0f;
	// 
	// Loop though all our enemies and if they are not the same and are within a certain distance,
	// add to the temporary vector the enemy velocitys vector and increment the neighbour count
	for (auto &flockcubes: PLAY->flock)
	{
		if (mySelf != flockcubes)
		{
			if (PLAY->myNodes.distanceCheck(mySelf, 300, flockcubes))
			{
				tempVector.x += flockcubes->velocity.x;
				tempVector.y += flockcubes->velocity.y;
				neighborCount++;
			}
		}
	
	}
	if (neighborCount == 0)
	{
		tempVector = { 0,0 };
		return tempVector;
	}
	else
	{
		tempVector.x /= neighborCount;
		tempVector.y /= neighborCount;
		tempVector.normalise();
		tempVector = tempVector * speed * behaviourWeight;
		return tempVector;
	}
}

Alignment::~Alignment()
{
}
