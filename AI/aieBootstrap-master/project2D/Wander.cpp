#include "Wander.h"
#include <stdlib.h>





Wander::Wander(Object * myself)
{
	mySelf = myself;
}

void Wander::Update(float dt)
{
	Vector2 tempVelocity;
	Vector2 circleCentre;
	circleCentre =  circleCentre + ((Enemy*)mySelf)->velocity;
	circleCentre.normalise();
	circleCentre = circleCentre * wanderDistance;
	
	Vector2 target;
	target.x = rand() % 100 + -100;
	target.y = rand() % 100 + -100;
	target.normalise * wanderRadius;
	target = target * wanderRadius;
	
}

Wander::~Wander()
{
}
