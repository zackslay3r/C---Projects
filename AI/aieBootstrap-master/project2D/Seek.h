#pragma once
#include "IBehavior.h"
class Seek : public IBehavior
{
public:
	Seek();
	void Update(Object *pObject, float dt);
	~Seek();
};

