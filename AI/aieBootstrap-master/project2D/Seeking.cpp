#include "Seeking.h"
#include "Enemy.h"

Seeking::Seeking(Object * myself)
{
	// Pass in myself and the enum type of the behaviour.
	mySelf = myself;
	type = BehaviourNames::SEEK;
}

Vector2 Seeking::Update(float dt)
{
	if (mySelf->type == ((Object*)type)->BEHAVIOURUSINGENEMY)
	{
		if (behaviourWeight > 0.0f)
		{
			// default speed scalar.
			float speed = 100.0f;

			Vector2 v1 = mySelf->position;
			// This is downcasting that will tell it to act as though it is a enemy pointer rather then a Object.
			Vector2 v2 = ((Enemy*)mySelf)->target->position;

			Vector2 v3 = v2 - v1;

			v3.normalise();



			return (v3 * speed * behaviourWeight);

		}
		else
		{
			Vector2 tempVec;
			return tempVec;
		}
	}
	if ((mySelf->type == ((Object*)type)->FLOCKCUBE))
	{
	
		behaviourWeight = 0.5f;
			
			// default speed scalar.
			float speed = 100.0f;

			Vector2 v1 = mySelf->position;
			// This is downcasting that will tell it to act as though it is a enemy pointer rather then a Object.
			Vector2 v2 = ((FlockCube*)mySelf)->target->position;

			Vector2 v3 = v2 - v1;

			v3.normalise();



			return (v3 * speed * behaviourWeight);

		}
	
}

Seeking::~Seeking()
{
}
