#pragma once
#include "IBehavior.h"
class Flee :
	public IBehavior
{
public:
	Flee(Object* myself);
	void Update(float dt);
	~Flee();
};

