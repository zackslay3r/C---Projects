#include "Wander.h"






Wander::Wander(Object * myself)
{
	mySelf = myself;
}

void Wander::Update(float dt)
{
	Vector2 circleCentre;
	circleCentre = ((Enemy*)mySelf)->velocity;
}

Wander::~Wander()
{
}
