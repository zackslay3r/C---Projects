#include "Wander.h"
#include <stdlib.h>
#include <ctime>




Wander::Wander(Object * myself)
{
	mySelf = myself;
	type = BehaviourNames::WANDER;
}

void Wander::Update(float dt)
{
	//Vector2 tempVelocity;
	Vector2 circleCentre;
	circleCentre =  circleCentre + ((Enemy*)mySelf)->position;
	circleCentre.normalise();
	circleCentre = circleCentre * wanderDistance;
	
	Vector2 target;
	target.x = random() + ((Enemy*)mySelf)->position.x + circleCentre.x;
	target.y = random() + ((Enemy*)mySelf)->position.y + circleCentre.y;
	target.normalise(); 
	target = target * wanderRadius;
	
	target *= circleCentre;
	//target.normalise();
	
	float speed = 100.0f;

	Vector2 v1 = mySelf->position;
	// This is downcasting that will tell it to act as though it is a enemy pointer rather then a Object.
	Vector2 v2 = target;

	Vector2 v3 = v2 - v1;

	v3.normalise();

	mySelf->velocity = v3 * speed * behaviourWeight;

}

int Wander::random()
{
	srand(time(NULL));
	int rannumber = rand() % 100 + 1;
	return rannumber;
}

Wander::~Wander()
{
}
