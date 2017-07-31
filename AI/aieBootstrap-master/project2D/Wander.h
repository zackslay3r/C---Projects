#pragma once
#include "IBehavior.h"
class Wander :
	public IBehavior
{
public:
	Wander(Object* myself);
	void Update(float dt);

	float wanderRadius = 50.0f;
	float wanderDistance = 100.0f;
	float wanderJitter = 5.0f;
	//Vector2 wanderTarget = r
	~Wander();
};

