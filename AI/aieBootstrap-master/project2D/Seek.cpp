//HACK
//#pragma optimize("", off)

#include "Seek.h"
#include "Vector2.h"
#include "Enemy.h"

Seek::Seek(Object* myself)
{
	// Pass in myself and the enum type of the behaviour.
	mySelf = myself;
	type = BehaviourNames::SEEK;
}

void Seek::Update(float dt)
{
	// If the behaviour is actually active and has a weighting....
	if (behaviourWeight > 0.0f)
	{
		// If the path is not empty...
		if (((Enemy*)mySelf)->path.size() > 0)
		{
			// the default distance between nodes.
			float distance = 50.0f;
			// the enemy position - the position of the last node.
			float DistX = ((Enemy*)mySelf)->position.x - ((Enemy*)mySelf)->path.back()->posX;
			float DistY = ((Enemy*)mySelf)->position.y - ((Enemy*)mySelf)->path.back()->posY;


			float x = DistX * DistX;
			float y = DistY * DistY;
			float xy = x + y;
		
		if (xy < distance * distance)
			{
				((Enemy*)mySelf)->path.pop_back();
			}
		}	
		
			
		// if the path has at least one node in it, we need to go there!
		if (((Enemy*)mySelf)->path.size() > 0)
		{
			// default velocity.
			float speed = 100.0f;

			// vector1 is our own position.
			Vector2 v1 = mySelf->position;
			// This is downcasting that will tell it to act as though it is a enemy pointer rather then a Object.
			Vector2 v2 = { ((Enemy*)mySelf)->path.back()->posX, ((Enemy*)mySelf)->path.back()->posY };

			Vector2 v3 = v2 - v1;

			v3.normalise();

			//this will work out the final velocity.
			mySelf->velocity = v3 * speed * behaviourWeight;
			
		}
		// if the path is 0, we want to stop moving, please?
		if (((Enemy*)mySelf)->path.size() <= 0)
		{
			mySelf->velocity = {0,0 };
		}

	
	}


}


Seek::~Seek()
{
}
