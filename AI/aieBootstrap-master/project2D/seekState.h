#pragma once
#include "IGameState.h"
class seekState :
	public IGameState
{
public:
	seekState(Application2D *_app, gameFSM *_gamefsm);
	void update(float dt);
	~seekState();
};

