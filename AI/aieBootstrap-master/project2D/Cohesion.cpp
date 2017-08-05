#include "Cohesion.h"
#include "PlayLoop.h"


Cohesion::Cohesion(Object * myself)
{
	mySelf = myself;
	type = BehaviourNames::COHESION;
}

void Cohesion::Update(float dt)
{

	// this is the temp vector that will store the velocity calculated.
	Vector2 tempVector;
	// This is the amount of neighbours each enemy will have.
	int neighborCount = 0;

	// Loop though all our enemies and if they are not the same and are within a certain distance,
	// add to the temporary vector the enemy velocitys vector and increment the neighbour count
	for (auto &enemys : PLAY->enemies)
	{
		if (mySelf != enemys)
		{
			if (PLAY->myNodes.distanceCheck(mySelf, 250, enemys))
			{
				tempVector.x += enemys->position.x;
				tempVector.y += enemys->position.y;
				neighborCount++;
			}
		}

	}
	if (neighborCount == 0)
	{
		tempVector = { 0,0 };
		mySelf->velocity = tempVector;
	}
	tempVector.x /= neighborCount;
	tempVector.y /= neighborCount;
	Vector2 finalVec;
	finalVec = { tempVector.x - mySelf->position.x, tempVector.y - mySelf->position.y };

	finalVec.normalise();
	mySelf->velocity = finalVec;
}

Cohesion::~Cohesion()
{
}
