#include "Wander.h"
#include <stdlib.h>
#include <ctime>
#include <math.h>



Wander::Wander(Object * myself)
{
	mySelf = myself;
	type = BehaviourNames::WANDER;
	behaviourWeight = 0.0f;
}

void Wander::Update(float dt)
{
	

	if (behaviourWeight > 0.0f)
	{
		// circleCentre is a clone of the enemy's position, then it is normalized
		// then it is multiplied by the wander distance.


		Vector2 circleCentre;
		circleCentre = ((Enemy*)mySelf)->velocity;
		circleCentre.normalise();
		circleCentre = circleCentre * wanderDistance;

		//calculate the displacement force
		Vector2 displacement;
		displacement = { 0,-1 };
		displacement = displacement * wanderRadius;

		// randomly change the vector direction
		setAngle(&displacement, wanderAngle);

		// change the wanderAngle a little bit, so its not the same every frame.
		wanderAngle += (random() * wanderJitter) - (wanderJitter * 0.5);

		float speed = 100.0f;

		//Vector2 v1 = mySelf->position;
		// This is downcasting that will tell it to act as though it is a enemy pointer rather then a Object.
		Vector2 v2 = circleCentre + displacement;

		//Vector2 v3 = v2 - v1;

		v2.normalise();

		mySelf->velocity = v2 * speed * behaviourWeight;

		if (PLAY->myNodes.distanceCheck(mySelf, 300, PLAY->player))
		{
			((Enemy*)mySelf)->changeToSeek(mySelf);
		}
	}
}

int Wander::random()
{
	
	int rannumber = rand() % 10 + 1;
	return rannumber;
}

void Wander::setAngle(Vector2* displacement, float wanderAngle)
{
	float tempFloat = 10.0f;

	displacement->x = cos(wanderAngle) * tempFloat;
	displacement->y = sin(wanderAngle) * tempFloat;

}

Wander::~Wander()
{
}
