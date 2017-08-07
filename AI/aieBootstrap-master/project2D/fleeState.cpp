#include "fleeState.h"
#include "PlayLoop.h"




fleeState::fleeState(enemyStateUser * _myself, gameFSM * _gamefsm): IGameState(_myself, _gamefsm)
{
	enemyStateMyself = _myself;
}

void fleeState::update(float dt)
{
	for (auto &behaviours : enemyStateMyself->m_behaviours)
	{
		if (behaviours->type == FLEE)
		{
			enemyStateMyself->utility->runAway(enemyStateMyself);
			behaviours->Update(dt);
			
		}
		else
		{
			behaviours->behaviourWeight = 0;
		}
	}
}

fleeState::~fleeState()
{
}
