#include "wanderState.h"
#include "PlayLoop.h"
#include "Global.h"
#include "Player.h"

class Player;
wanderState::wanderState(Enemy * _enemy, gameFSM * _gamefsm) : IGameState(_enemy, _gamefsm)
{
}

void wanderState::update(float dt)
{
	for (auto &enemys : PLAY->enemies)
	{
		enemys->changeToWander(enemys);
		
	}
	for (auto &enemys : PLAY->enemies)
	{
	//	if (enemys->currentNode->posX != nullptr)
		{

			if (PLAY->myNodes.distanceCheck(enemys->currentNode, 300.0f, PLAY->player->closestNode))
			{
				enemys->changeToSeek(enemys);
			}
		}
	}
	
}

wanderState::~wanderState()
{
}
