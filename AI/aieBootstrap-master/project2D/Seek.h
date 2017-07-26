#pragma once
#include "IBehavior.h"
class Seek : public IBehavior
{
public:
	Seek();
	void Update(Object *movingObject, Object* movingToo, float dt);
	~Seek();
};

