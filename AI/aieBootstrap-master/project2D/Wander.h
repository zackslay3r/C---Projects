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
	Vector2 Update(float dt);
	int random();
	float wanderRadius = 200;
	float wanderDistance = 150;
	float wanderJitter = 0.1f;
	float wanderAngle = 0.0f;

	void setAngle(Vector2* displacement, float wanderAngle);
	//Vector2 wanderTarget = r
	~Wander();
};

