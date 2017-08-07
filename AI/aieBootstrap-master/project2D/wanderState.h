#pragma once
#include "IGameState.h"
class enemyStateUser;
class wanderState : public IGameState
{
public:
	
	wanderState(enemyStateUser *_ploop, gameFSM *_gamefsm);
	virtual void update(float dt);
	~wanderState();
};

