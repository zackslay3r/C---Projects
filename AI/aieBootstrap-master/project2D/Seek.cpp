#include "Seek.h"



Seek::Seek()
{
}

void Seek::Update(Object * pObject, float dt)
{
	pObject->position.x += pObject->velocity.x * dt;
}


Seek::~Seek()
{
}
