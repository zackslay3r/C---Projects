#pragma once
#include "IBehavior.h"
#include "Global.h"
class Alignment :
	public IBehavior
{
public:
	Alignment(Object* myself);

	Vector2 Update(float dt);
	~Alignment();
};

