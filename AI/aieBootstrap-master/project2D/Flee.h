#pragma once
#include "IBehavior.h"
class Flee :
	public IBehavior
{
public:
	Flee();
	void Update(Object *movingObject, Object* movingToo, float dt);
	~Flee();
};

