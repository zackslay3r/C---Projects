#pragma once
#include "IGameState.h"


class enemyStateUser;
class seekState : public IGameState
{
public:
	seekState(enemyStateUser *_ploop, gameFSM *_gamefsm);
	
	virtual void update(float dt);
	 ~seekState();
};

