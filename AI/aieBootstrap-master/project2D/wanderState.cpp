#include "wanderState.h"
#include "PlayLoop.h"
#include "Global.h"
#include "Player.h"

class Player;
wanderState::wanderState(Enemy * _enemy, gameFSM * _gamefsm) : IGameState(_enemy, _gamefsm)
{
	myself = _enemy;
}

void wanderState::update(float dt)
{

		
	
	// for each enemy...
	for (auto &behaviours : myself->m_behaviours)
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
		if (PLAY->myNodes.distanceCheck(myself, 300, PLAY->player))
		{
			myself->enemyFSM->popState();
			myself->enemyFSM->pushState(SEEK);
		}
	
}
	

wanderState::~wanderState()
{
}
