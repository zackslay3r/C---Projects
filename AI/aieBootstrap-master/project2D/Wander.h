#pragma once
#include "IBehavior.h"
#include "Enemy.h"
#include "Vector2.h"
#include "Global.h"
class Wander :
	public IBehavior
{
public:
	Wander(Object* myself);
	void Update(float dt);
	int random();
	float wanderRadius = 50.0f;
	float wanderDistance = 200.0f;
	float wanderJitter = 5.0f;
	//Vector2 wanderTarget = r
	~Wander();
};

