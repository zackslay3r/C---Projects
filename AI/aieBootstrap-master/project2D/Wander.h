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
	float wanderDistance = 100.0f;
	float wanderJitter = 0.1f;
	float wanderAngle = 0.0f;

	void setAngle(Vector2* displacement, float wanderAngle);
	//Vector2 wanderTarget = r
	~Wander();
};

