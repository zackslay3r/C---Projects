#pragma once
#include "IBehavior.h"
#include "Global.h"
class Cohesion :
	public IBehavior
{
public:
	Cohesion(Object* myself);

	Vector2 Update(float dt);
	~Cohesion();
};

