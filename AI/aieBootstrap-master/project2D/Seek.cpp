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
	behaviourWeight = 1.0f;
	float speed = 200.0f;

	Vector2 v1 = mySelf->position;
	// This is downcasting that will tell it to act as though it is a enemy pointer rather then a Object.
	Vector2 v2 = ((Enemy* )mySelf)->target->position;

	Vector2 v3 = v2 - v1;

	v3.normalise();

	mySelf->velocity = v3 * speed * behaviourWeight;
	


}


Seek::~Seek()
{
}
