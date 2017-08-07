#include "fleeState.h"
#include "PlayLoop.h"




fleeState::fleeState(Enemy * _myself, gameFSM * _gamefsm): IGameState(_myself, _gamefsm)
{
	myself = _myself;
}

void fleeState::update(float dt)
{
	for (auto &behaviours : myself->m_behaviours)
	{
		if (behaviours->type == FLEE)
		{
			myself->utility->runAway(myself);
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
