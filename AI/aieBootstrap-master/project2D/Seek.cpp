//HACK
#pragma optimize("", off)

#include "Seek.h"
#include "Vector2.h"
#include "Enemy.h"

Seek::Seek(Object* myself)
{
	mySelf = myself;
	type = BehaviourNames::SEEK;
}

void Seek::Update(float dt)
{
	if (behaviourWeight > 0.0f)
	{

		if (((Enemy*)mySelf)->path.size() > 0)
		{
			float distance = 50.0f;
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
		//Vector2 tempLocation = { ((Enemy*)mySelf)->path.back()->posX, ((Enemy*)mySelf)->path.back()->posY };
			
		
		if (((Enemy*)mySelf)->path.size() > 0)
		{
			float speed = 100.0f;

			Vector2 v1 = mySelf->position;
			// This is downcasting that will tell it to act as though it is a enemy pointer rather then a Object.
			Vector2 v2 = { ((Enemy*)mySelf)->path.back()->posX, ((Enemy*)mySelf)->path.back()->posY };

			Vector2 v3 = v2 - v1;

			v3.normalise();


			mySelf->velocity = v3 * speed * behaviourWeight;
			
		}

		if (((Enemy*)mySelf)->path.size() <= 0)
		{
			mySelf->velocity = {
				0,0 };
		}
	}


}


Seek::~Seek()
{
}
