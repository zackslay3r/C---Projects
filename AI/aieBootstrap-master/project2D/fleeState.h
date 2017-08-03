#pragma once
#include "IGameState.h"
class Enemy;
class fleeState : public IGameState
{
public:
	fleeState(Enemy *_ploop, gameFSM *_gamefsm);
	virtual void update(float dt);
	~fleeState();
};

