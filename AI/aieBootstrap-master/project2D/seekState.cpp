#include "seekState.h"
#include "PlayLoop.h"
#include "Global.h"


using namespace BehaviourManagement;
seekState::seekState(enemyStateUser* _enemy, gameFSM * _gamefsm) : IGameState(_enemy, _gamefsm)
{
	enemyStateMyself = _enemy;
}

void seekState::update(float dt)
{
	
	for (auto &behaviours : enemyStateMyself->m_behaviours)
	{
		if (behaviours->type == SEEK)
		{
			behaviours->behaviourWeight = 1;
			behaviours->Update(dt);
			PLAY->theBoard->isOtherSeeking.push_back(enemyStateMyself);
			PLAY->theBoard->seekAsWell();
		}
		else
		{
			behaviours->behaviourWeight = 0;
		}
	}

	
		if (enemyStateMyself->health <= 30)
		{
			enemyStateMyself->enemyFSM->popState();
			enemyStateMyself->enemyFSM->pushState(FLEE);
		}
	//myself->utility->runAway(myself);
	
}

seekState::~seekState()
{
}
