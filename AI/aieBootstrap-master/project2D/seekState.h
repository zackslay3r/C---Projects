#pragma once
#include "IGameState.h"


class Enemy;
class seekState : public IGameState
{
public:
	seekState(Enemy *_ploop, gameFSM *_gamefsm);
	
	virtual void update(float dt);
	 ~seekState();
};

