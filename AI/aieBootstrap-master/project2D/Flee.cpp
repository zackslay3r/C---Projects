#include "Flee.h"
#include "Enemy.h"


Flee::Flee(Object* myself)
{
	type = BehaviourNames::FLEE;
	mySelf = myself;
	
}

Vector2 Flee::Update(float dt)
{
	if (behaviourWeight > 0.0f)
	{
		float speed = 100.0f;

		Vector2 v1 = mySelf->position;
		// This is downcasting that will tell it to act as though it is a enemy pointer rather then a Object.
		Vector2 v2 = ((Enemy*)mySelf)->target->position;

		Vector2 v3 = v1 - v2;

		v3.normalise();

		((Enemy*)mySelf)->utility->runAway(((Enemy*)mySelf));
		
		return (v3 * speed * behaviourWeight);

	}
	else
	{
		Vector2 tempVec;
		return tempVec;
	}

}


Flee::~Flee()
{
}
