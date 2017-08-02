#pragma once
#include "IGameState.h"
class Enemy;
class wanderState : public IGameState
{
public:
	
	wanderState(Enemy *_ploop, gameFSM *_gamefsm);
	virtual void update(float dt);
	~wanderState();
};

