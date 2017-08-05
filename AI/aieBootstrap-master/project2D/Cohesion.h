#pragma once
#include "IBehavior.h"
#include "Global.h"
class Cohesion :
	public IBehavior
{
public:
	Cohesion(Object* myself);

	void Update(float dt);
	~Cohesion();
};

