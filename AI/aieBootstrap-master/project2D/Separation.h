#pragma once
#include "IBehavior.h"
#include "Global.h"
class Separation :
	public IBehavior
{
public:
	Separation(Object* myself);

	Vector2 Update(float dt);
	~Separation();
};

