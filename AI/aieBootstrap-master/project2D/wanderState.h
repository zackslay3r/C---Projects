#pragma once
#include "IGameState.h"
#include "Vector2.h"
class enemyStateUser;
class wanderState : public IGameState
{
public:
	
	wanderState(enemyStateUser *_ploop, gameFSM *_gamefsm);
	int random();
	float wanderRadius = 50.0f;
	float wanderDistance = 100.0f;
	float wanderJitter = 0.1f;
	float wanderAngle = 0.0f;
	void setAngle(Vector2* displacement, float wanderAngle);
	virtual void update(float dt);
	~wanderState();
};

