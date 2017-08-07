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
		if (PLAY->myNodes.distanceCheck(enemys, 300, PLAY->player))
		{
			enemys->changeToSeek(enemys);
		}
	
	}
	
}

wanderState::~wanderState()
{
}
