#include "Seek.h"
#include "Vector2.h"


Seek::Seek()
{
}

void Seek::Update(Object * objectMoving, Object* movingToo, float dt)
{
	float speed = 200.0f;


	Vector2 v1 = objectMoving->position;
	Vector2 v2 = movingToo->position;

	Vector2 v3 = v2 - v1;

	v3.normalise();

	objectMoving->velocity = v3 * speed;
	behaviourWeight = 1;

}


Seek::~Seek()
{
}
