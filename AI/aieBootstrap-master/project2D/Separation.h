#pragma once
#include "IBehavior.h"
#include "Global.h"
class Separation :
	public IBehavior
{
public:
	Separation(Object* myself);

	void Update(float dt);
	~Separation();
};

