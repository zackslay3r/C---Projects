#include "Wander.h"
#include <stdlib.h>





Wander::Wander(Object * myself)
{
	mySelf = myself;
}

void Wander::Update(float dt)
{
	//Vector2 tempVelocity;
	Vector2 circleCentre;
	circleCentre =  circleCentre + ((Enemy*)mySelf)->velocity;
	circleCentre.normalise();
	circleCentre = circleCentre * wanderDistance;
	
	Vector2 target;
	target.x = rand() % 100 + -100;
	target.y = rand() % 100 + -100;
	target.normalise(); 
	target = target * wanderRadius;
	
	target *= circleCentre;

	float speed = 100.0f;

	Vector2 v1 = mySelf->position;
	// This is downcasting that will tell it to act as though it is a enemy pointer rather then a Object.
	Vector2 v2 = target;

	Vector2 v3 = v2 - v1;

	v3.normalise();

	mySelf->velocity = v3 * speed * behaviourWeight;

}

Wander::~Wander()
{
}
