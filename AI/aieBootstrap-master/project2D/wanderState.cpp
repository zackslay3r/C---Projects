#include "wanderState.h"
#include "PlayLoop.h"
#include "Global.h"
#include "Player.h"

class Player;
wanderState::wanderState(enemyStateUser * _enemy, gameFSM * _gamefsm) : IGameState(_enemy, _gamefsm)
{
	enemyStateMyself = _enemy;
}

void wanderState::update(float dt)
{

		
	
	// for each enemy...
	for (auto &behaviours : enemyStateMyself->m_behaviours)
	{
		if (behaviours->type == WANDER)
		{
			behaviours->behaviourWeight = 1;
			behaviours->Update(dt);
		}
		else
		{
			behaviours->behaviourWeight = 0;
		}
		//PLAY->theBoard->seekAsWell();
	}
		// if the distance to the player is equal or less than 300...
		if (PLAY->myNodes.distanceCheck(enemyStateMyself, 300, PLAY->player))
		{
			enemyStateMyself->enemyFSM->popState();
			enemyStateMyself->enemyFSM->pushState(SEEK);
		}
	
}
	

wanderState::~wanderState()
{
}
