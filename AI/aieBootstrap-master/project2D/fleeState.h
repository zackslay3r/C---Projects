#pragma once
#include "IGameState.h"
class enemyStateUser;
class fleeState : public IGameState
{
public:
	fleeState(enemyStateUser *_ploop, gameFSM *_gamefsm);
	virtual void update(float dt);
	~fleeState();
};

