#include "seekState.h"
#include "PlayLoop.h"
#include "Global.h"


using namespace BehaviourManagement;
seekState::seekState(Enemy * _enemy, gameFSM * _gamefsm) : IGameState(_enemy, _gamefsm)
{
}

void seekState::update(float dt)
{
	for (auto &enemys : PLAY->enemies)
	{
		for (auto &behaviours : enemys->m_behaviours)
		{
			if (behaviours->type == SEEK)
			{
				behaviours->behaviourWeight = 1.0f;
			}
			else
			{
				behaviours->behaviourWeight = 0.0f;
			}
		}
		enemys->changeToSeek(enemys);
	}

	for (auto &enemys : PLAY->enemies)
	{
		if (enemys->health < 30)
		{
			enemys->enemyFSM->popState();
			enemys->enemyFSM->pushState(FLEE);
		}
	}
}

seekState::~seekState()
{
}
