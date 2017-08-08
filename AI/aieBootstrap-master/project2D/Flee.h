#pragma once
#include "IBehavior.h"
class Flee :
	public IBehavior
{
public:
	Flee(Object* myself);
	Vector2 Update(float dt);
	~Flee();
};

