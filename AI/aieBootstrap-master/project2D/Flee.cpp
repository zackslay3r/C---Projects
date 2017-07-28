#include "Flee.h"



Flee::Flee()
{
}

void Flee::Update(Object * movingObject, Object * movingToo, float dt)
{
	float speed = 200.0f;


	Vector2 v1 = movingObject->position;
	Vector2 v2 = movingToo->position;

	Vector2 v3 = v1 - v2;

	v3.normalise();
	behaviourWeight = 2;
	movingObject->velocity = v3 * speed * behaviourWeight;
	


}


Flee::~Flee()
{
}
