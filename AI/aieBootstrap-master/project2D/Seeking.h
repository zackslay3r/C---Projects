#pragma once
#include "IBehavior.h"

class Seeking :
	public IBehavior
{
public:
	Seeking(Object* myself);
	Vector2 Update(float dt);
	~Seeking();
};

