#include "seekState.h"
#include "PlayLoop.h"
#include "Global.h"


using namespace BehaviourManagement;
seekState::seekState(Enemy * _enemy, gameFSM * _gamefsm) : IGameState(_enemy, _gamefsm)
{
	myself = _enemy;
}

void seekState::update(float dt)
{
	
	for (auto &behaviours : myself->m_behaviours)
	{
		if (behaviours->type == SEEK)
		{
			behaviours->behaviourWeight = 1;
			behaviours->Update(dt);
			PLAY->theBoard->isSeeking.push_back(myself);
			PLAY->theBoard->seekAsWell();
		}
		else
		{
			behaviours->behaviourWeight = 0;
		}
	}

	
		if (myself->health <= 30)
		{
			myself->enemyFSM->popState();
			myself->enemyFSM->pushState(FLEE);
		}
	//myself->utility->runAway(myself);
	
}

seekState::~seekState()
{
}
