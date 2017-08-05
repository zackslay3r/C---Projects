#pragma once
#include "IBehavior.h"
#include "Global.h"
class Alignment :
	public IBehavior
{
public:
	Alignment(Object* myself);

	void Update(float dt);
	~Alignment();
};

